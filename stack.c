#include "stack.h"


void StackInit(Stack* ps, int n)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*n);
	ps->_top = 0;
	ps->_capacity = n;

}

STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_a[ps->_top - 1];
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}

}



int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}


void StackTest()
{
	Stack s;
	StackInit(&s, 3);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);

	while (StackEmpty(&s))
	{
		printf("top:%d\n", StackTop(&s));
		StackPop(&s);
	}
}