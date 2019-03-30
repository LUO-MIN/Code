#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{ 
	BTDataType _data;    
	struct BinaryTreeNode* _left;    
	struct BinaryTreeNode* _right; 
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi); 
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root); 
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeLevelKSize(BTNode* root, int k); 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);