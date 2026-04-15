#include "apc.h"
#include<stdio.h>

/*Function to perform Addition operation*/
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	int sum,num1,num2,carry=0;

	Dlist *tail = NULL;
	//Treversing the list upto NULL
	while(temp1 != NULL || temp2 != NULL)
	{
		//Traversing first list upto NULL
		if(temp1 != NULL)
		{
			num1 = temp1 -> data;
			temp1 = temp1 -> prev;
		}
		else
		{
			num1 = 0;
		}
		//Traversing second list upto NULL
		if(temp2 != NULL)
		{
			num2 = temp2 -> data;
			temp2 = temp2 -> prev;
		}
		else
		{
			num2 = 0;
		}
		//Calulating the sum of two operends and carry
		sum = num1 + num2 + carry;
		//Compute carry for the next operand
		carry = sum/10;
		//Remainder after dividing by 10
		sum = sum % 10;

		//Insert result at the beginning of the result list
		insert_first(headR,tailR,sum);
	}
	return SUCCESS;
}
