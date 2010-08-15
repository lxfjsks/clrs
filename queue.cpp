//**********************************************************************
// queue.cpp
//**********************************************************************
//
// Application : CLRS
// Author : Sima Liu
// Description : Queue class
//
//**********************************************************************
/*
*
* Revison History
* Date			Author			Comments
* ----------	------------	-------------------
* 08/15 2010	Sima Liu		init
*
*/

/**
 * DO NOT INSERT A value=-999999
 * Using NULL_VALUE to check overflow, m_head==m_tail to check underflow
 *
 * REASON 1: After enqueue, move m_tail to next(m_tail = (m_tail+1)%m_size) if m_tail==m_head after move
 * then dequeue, full but will return empty
 * ANSWER: so do no move m_tail to next when  ((m_tail+1)%m_size==m_head)
 * 
 * REASON 2: enqueue again, but there is a value for m_tail, we should not overwrite it
 * ANSWER: so using NULL_VALUE to check overflow
 */
const int NULL_VALUE= -999999;

#include "queue.h"
#include <iostream>

Queue::Queue(int size): m_size(size)
{
	m_head=m_tail=0;
	m_ptr = new int[size];
	for(int i=0;i<size;i++)
		m_ptr[i]=NULL_VALUE;
	std::cout << "in Queue()" << std::endl;
}


Queue::~Queue()
{
	delete[] m_ptr;
	std::cout << "in ~Queue()" << std::endl;
}


/*
 * detect underflow and overflow by value -999999 and (m_tail+1)%m_size != m_head
 */
int Queue::enqueue(int v)
{
	if(m_ptr[m_tail]!=NULL_VALUE) 
	{
		std::cout << "overflow when enqueue <" << v << ">!"  << std::endl;
		return 0;
	}

	m_ptr[m_tail] = v;

	//do not move the tail to next when full. see code in dequeue
	if((m_tail+1)%m_size != m_head)
		m_tail = (m_tail+1)%m_size;

	return v;
}

int Queue::dequeue()
{
	if(m_head==m_tail)
	{
		std::cout << "queue empty! " << std::endl;
		return 0;
	}
	else
	{
		int t=m_ptr[m_head];
		m_ptr[m_head]=NULL_VALUE;
		m_head = (m_head+1) % m_size;

		//move the tail to next after dequeue a elem and tail is one elem before the dequeued elem
		if(m_ptr[m_tail]!=NULL_VALUE && ((m_tail+1)%m_size != m_head) )
				m_tail = (m_tail+1)%m_size;

		return t;
	}
}

void Queue::print()
{
	std::cout << "m_head=" << m_head << std::endl;
	std::cout << "m_tail=" << m_tail << std::endl;
	for(int i=0;i<m_size;i++)
	{
		if(m_ptr[i] ==NULL_VALUE)
			std::cout << "*,";
		else 
			std::cout << m_ptr[i] << ",";
	}
	std::cout << std::endl;
}


/*
 //TEST CODE
int main()
{
	Queue q(3);
	q.dequeue();

	q.enqueue(5);q.enqueue(1);q.enqueue(22);q.enqueue(4);q.enqueue(52);q.enqueue(15);
	q.dequeue();q.enqueue(12);
	q.dequeue();q.enqueue(22);
	q.dequeue();q.enqueue(32);
	q.print();
	
	return 0;
}
}
*/