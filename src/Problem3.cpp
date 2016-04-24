/*
Given a Tree which consists of operands and operators ,Solve the Tree and return the result
The tree will have special nodes of type enode which will have 3 fields
data => String of 5 chars .which can be either a operator or operand 
If its a operator its values will be one of the 3 following strings "+" , "-" , "*".
If its a operand its values will be any number from -9999 to 99999 in its respective string format;
Left and Right pointers will point to either NULL or another enode
Only the leaf nodes will have operand values .

Example 1:
    +
   / \
  4   5 
The Result expression is : 4+5 ,Ans is 9

Example 2:
        *
       / \
      -   5
     / \
    7   2

The Result expression is : (7-2) * 5  ,Ans is 25

Example 3:
       +
     /   \
    *     -  
   / \   / \
  7   2  4  *
           / \
          2   1
  
The Result expression is : (7*2) + (4-(2*1)) =>14+2 =>16 ,Ans is 16 

Constraints : 
Total number of enodes will be <=20 for 50% of Test cases
Data value will only have "0"<=data<="99999" values for 50% of cases .
Data value for operators will have sign as first character and \0 as next character .

Input :
Root node of a Tree of type enode
Output :
Return Final answer or -1 for Null inputs

Note :
->Dont Create an Extra Array/String ,or else your solution would receive 20%-40% Cut in the Marks you got .

Difficulty : Medium
*/
#include <stdlib.h>;
#include <stdio.h>

//data can be accessed using root->data;
typedef struct enode{
	char data[6];
	enode *left;
	enode *right;
};

/*
Helper Functions are optional to write 
*/
//Helper Functions Start
int isOperator(char *data){
	if (*data == 42 || *data == 43 || *data == 45 || *data == 47)
		return 1;
	else
		return 0;
}
int isOperand(char *data,int n1,int n2){
	if (*data == 42)
		return n1 + n2;
	else if (*data == 43)
		return n1*n2;
	else if (*data == 45)
		return n1 - n2;
	else if (*data == 47)
		return n1 / n2;

}
int getOperand(char *data,int n1,int n2){
	//converts data string to an integer "123" => 123
	
}
//Helper Functions end
int solve_tree(enode *root){
    
	enode *temp;
	int n1,n2;
	char c;
	if (temp == NULL)
		return -1;
	else if (isOperator(temp->data))
	{
			n1 = to_left(temp->left);
			n2 = to_right(temp->right);
			c=getOperand(temp->data,n1,n2);
			return c;
	}
}

