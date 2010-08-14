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


