//**********************************************************************
// Stack.h
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

#ifndef _STACK_H_
#define _STACK_H_


class Stack
{
public:
	Stack(int);
	~Stack();
	int push(int);
	int pop();
	void print();

private:
	int		m_size;
	int*	m_ptr;
	int		m_top;

//enchancement functions
private:
	//increase the container size when overflow
	void resize();
};



#endif


