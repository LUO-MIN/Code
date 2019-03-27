#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>


typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

int StackEmpty(Stack* ps);
void StackPop(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackInit(Stack* ps, int n);
void InOrderNonR(BTNode* root);