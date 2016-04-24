/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node{
	int data;
	node *left;
	node *right;
};
int to_left(node *, int,int);
int to_right(node *, int,int);

int to_left(node *curr, int N, int n)
{
	if (curr == NULL)
		return N;
	else
	{
		if (curr->data >= 0 && curr->data <= n)
			N = N - (curr->data);
		//(*n)--;
		N = to_left(curr->left, N, n);
		N = to_right(curr->right, N, n);
	}
	return N;
}
int to_right(node *curr, int N, int n)
{
	if (curr == NULL)
		return N;
	else
	{
		if (curr->data >= 0 && curr->data <= n)
			N = N - (curr->data);
		N = to_left(curr->left, N, n);
		N = to_right(curr->right, N, n);
	}
	return N;
}

int get_missing_value(node *root, int n){

	int N;
	node *temp;
	temp = root;
	N = (n*(n + 1)) / 2;
	if (root != NULL)
	{
		if (temp->data >= 0 && temp->data <= n)
			N = N - temp->data;
		//n--;
	}
	else
		return -1;
	N = to_left(temp->left, N, n);
	N = to_right(temp->right, N, n);
	return N;
}