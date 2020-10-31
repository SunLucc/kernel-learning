#include <stdio.h>
#include <stdlib.h>
#include <string.h>





typedef struct 
{
	int data;
	struct BST_TREE * left;
	struct BST_TREE * right;
}BST_TREE;


int count = 0;

/*pre order travers a binary tree*/
void preorder(BST_TREE* tree)
{
	if(NULL != tree)
	{	
		printf(" %2d", tree);
		preorder(tree->left);
		preorder(tree->right);

	}
}

void inorder_trav(BST_TREE * tree)
{
	if(NULL != tree)
	{	
		inorder_trav(tree->left);
		printf(" %2d", (tree->data));
		inorder_trav(tree->right);
	}
	
}


BST_TREE * search(BST_TREE *t, int data)
{
	if((!t) || (data == t->data))
	{
		return t;
	}
	else if(data < t->data)
	{
		return search(t->left, data);
	}
	else
	{
		return search(t->right, data);
	}
}

void insert(BST_TREE **t, int data)
{	
	count++;
	printf("count %d, input tree addr %p\n", count, *t);
	if(!(*t))
	{	
		BST_TREE *s_new_node = NULL;
		s_new_node = (BST_TREE *)malloc(sizeof(BST_TREE));
		if(NULL == s_new_node)
			return 0;
		s_new_node->data = data;
		s_new_node->left = s_new_node->right = NULL;
		printf("s_new_node malloced!\n");
		printf("node_data %d node_ptr %p left child %p right child  %p \n", data,s_new_node, s_new_node->left, s_new_node->right);
		*t = s_new_node;
	}
	else if (data < (BST_TREE *)(*t)->data)
		insert((BST_TREE**)&((*t)->left), data);
	else
		insert((BST_TREE**)&((*t)->right), data);
}


//void create(BST_TREE **t, int data)
//{
	
//}
void main()
{
	BST_TREE node;
	int data[10] = {21,1,3,4,11,14,6,43,23,33};
	int i = 0;
	memset(&node, 0, sizeof(BST_TREE));
	BST_TREE *root = NULL;
	printf("the addr of root %p\n", &root);
	for(i = 0; i<10;i++)
	{
		insert(&root, data[i]);
		
		
	}

	printf("root node data %d, addr %p\n", root->data, root);
	inorder_trav(root);
}






















