//**********************************************************************
// queue.h
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

#ifndef _QUEUE_H_
#define _QUEUE_H_


class Queue
{
public:
	Queue(int);
	~Queue();

	int enqueue(int);
	int dequeue();
	void print();

private:
	int		m_head, m_tail;
	int*	m_ptr;
	int		m_size;

};


#endif





