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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi); 
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root); 
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeLevelKSize(BTNode* root, int k); 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);