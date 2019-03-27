#include "Test.h"

void StackInit(Stack* ps,int n)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*n);
	ps->_top = 0;
	ps->_capacity = n;

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

int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->_a[ps->_top - 1];
}
//�������ǵݹ��������
void InOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack st;
	StackInit(&st,10);
	
	while (cur || StackEmpty != NULL)
	{
		while (cur)
		{
			//ѹ��·���
			StackPush(&st, cur);
			cur = cur->_left;
		}
		
		//ȡ����·�ڵ㣬��·�ڵ㼰������
			BTNode* top = StackTop(&st);
			StackPop(&st);
			printf("%d\n", top->_data);

		//�������������⣩
			cur = cur->_right;
		
	}

}