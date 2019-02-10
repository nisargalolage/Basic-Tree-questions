#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

int max(int a, int b)
{
	if (a>b)
	return a;
	else
	return b;
}

struct node *create(int data)
{
	struct node *nn = (struct node*) malloc(sizeof(struct node));
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
int height(struct node *root)
{
	if(!root)
	return -1;
	return (1+max(height(root->left),height(root->right)));
}

void printTree(struct node* root)
{
	if (!root)
		return;
	
	printTree(root->left);
	printf(" %d ", root->data);
	printTree(root->right);

}

int countNodes(struct node* root)
{
	if (!root)
	return 0;
	return (1 + countNodes(root->left) + countNodes(root->right));
}

int countLeafNodes(struct node* root)
{
	if(!root)
	return 0;

	if(!root->left && !root->right)
	return 1;
	return ( countLeafNodes(root->left) +  countLeafNodes(root->right));
}

int countNonLeaf(struct node * root)
{
	if(!root)
	return 0;
	if (root->left || root->right)
	return(1 + countNonLeaf(root->left) + countNonLeaf(root->right));
}

void printLevel(struct node* root, int n)
{
	if(!root)
	return;
	if(n == 1)
	{
		printf(" %d ", root->data);
		return;
	}
	
	printLevel(root->left, n-1);
	printLevel(root->right, n-1);
}

int sumLeaves(struct node *root)
{

	if(!root)
	return 0;
	
	if(!root->left && !root->right)
	return (root->data);

	return(sumLeaves(root->left)+sumLeaves(root->right));
}
int max1 = 0;

int maximum(struct node *root)
{
	if(!root)
	return 0;

	return(max(max(maximum(root->left),maximum(root->right)),root->data));

	if(root->data > max1)
        {
                max1 = root->data;
                return max1;
        }

}

int max5 =0;
int min5 =100;
int isBst(struct node *root)
{
if(!root)
{
	return 1;
}
	
return(isBst(root->left) && isBst(root->right));

printf("here");
if(!root->left && !root->right)
{
	max5 = root->data;
	min5 = root->data;
}
}

int main()
{
	struct node *root;
	root = create(10);
	root->left = create(5);
	root->right = create(21);
	root->right->right = create(31);
	root->left->left = create(3);
	root->right->left = create(8);
	root->right->left->right = create(9);
	root->left->right = create(7);
	printTree(root);
	printf("ht = %d", height(root));
	printf("count = %d",countNodes(root));
	printf("leaf = %d",countLeafNodes(root));
	printf("Nleaf = %d",countNonLeaf(root));
	int i = 0;
	for(i = 1; i <= height(root)+1; i++)
	{
		printLevel(root,i);
	}
	
	printf("sum=%d ",sumLeaves(root));

	printf("max-%d",maximum(root));
	
	printf("---%d----",isBst(root));
	return 0;
}
