#include "Tree.h"

BTNode* BuyBTNode(BTDataType x)//新建一个结点
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)//创建一个二叉树
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
	{
		return NULL;
	}
}


int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (root->_left == NULL
			&& root->_right == NULL)
		{
			return 1;
		}

		return BinaryTreeSize(root->_left)
			+ BinaryTreeSize(root->_right)+1;

	}

}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL
		&& root->_right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k==1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right,k-1);

}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		if (root->_data == x)
		{
			return root;
		}
		else
		{
			struct BTNode* ret = BinaryTreeFind(root->_left, x);
			if (ret)
			{
				return BinaryTreeFind(root->_right, x);
			}
			else
			{
				return NULL;
			}
		}
	}
}


void BinaryTreeTest()
{
	char* array = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* tree = BinaryTreeCreate(array, &i);
	printf("%d\n", BinaryTreeLeafSize(tree));
	printf("%d\n", BinaryTreeSize(tree));
    printf("%d\n", BinaryTreeLevelKSize(tree, 4));
	printf("%d\n", BinaryTreeFind(tree, 1));
}