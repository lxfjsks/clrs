//**********************************************************************
// Stack.cpp
//**********************************************************************
//
//		Application	: CLRS
//		Author		: Sima Liu
//		Description	: Stack class
//
//**********************************************************************
/* 
 * 
 * Revison History
 * Date		Author			Comments
 * ----------	------------	-------------------
 * 08/07 2010  Sima Liu	 	init
 * 08/14 2010  Sima Liu		Stack implementation
 * 
 */ 
 
#include "stack.h"
#include <iostream>


Stack::Stack(int size):m_size(size)
{
	std::cout << "in Stack()" << ", size=" << m_size <<std::endl;
	m_ptr = new int[size];
	m_top = -1;
}


Stack::~Stack()
{
	std::cout << "in ~Stack()" << std::endl;
	delete[] m_ptr;
}

int Stack::pop()
{
	if(m_top>-1)
	{
		return m_ptr[m_top--];
	}else{
		std::cout << "empty!" << std::endl;
		return -1;
	}
}

int Stack::push(int v)
{
	if(m_top<m_size-1)
	{
		m_ptr[++m_top]=v;
		return m_ptr[m_top];
	}else{
		std::cout << "overflow when push <" << v <<">!" << std::endl;
		return -1;
	}
}

void Stack::print()
{
	for(int i=0;i<=m_top;i++)
	{
		std::cout << m_ptr[i] << '\t';
	}
	std::cout << std::endl;
}
