#include <stdio.h>
#include "apc.h"
#include <string.h>

/* Validation Function */
int read_and_validate(char *argv[])
{
	// Check the condition given operator is i.e, '+' , '-', 'x' and '/'   
	if (argv[2][0]  == '+' || argv[2][0] == '-' || argv[2][0] == 'x' || argv[2][0] == '/')
	{
		char *str = argv[1];
		//Check the condition first operand is digit or not           
		while (*str)
		{
			if (*str < '0' || *str > '9')
			{
				printf(" %s is not a digit\n", argv[1]);
				break;
			}
			str++;
		}
		char *str1 = argv[3];
		//Check the condition second operand is digit or not
		while (*str1)
		{
			if (*str1 < '0' || *str1 > '9')
			{
				printf(" %s is not a digit\n", argv[3]);
				break;
			}
			str1++;
		}
		return SUCCESS;
	}
	else
	{
		//printf("Given operator is not a arithmatic operator\n please enter '+', '-'. '*', '/'\n"); 
		return FAILURE;
	}
}
/* Insert digit function */
void insert_digit (Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
        int len = strlen(argv[1]);
	// Insert Digits into the first list i.e, argv[1]
        for (int i = 0; i < len; i++)
        {
		
                Dlist *new = malloc(sizeof (Dlist));
                new -> data = argv[1][i] - '0';
                new -> prev = *tail1;
                new -> next = NULL;
                if (*head1 == NULL)
                {
                        *head1 = new;
                        *tail1 = new;
                        continue;
                }
                (*tail1) -> next = new;
                *tail1 = new;
        }
        int len1 = strlen(argv[3]);

	//Insert Digits into the second list i.e, argv[3]
        for (int j = 0; j < len1; j++)
        {
		//New node is creating
                Dlist *new = malloc(sizeof (Dlist));
                new -> data = argv[3][j] - '0';
                new -> prev = *tail2;
                new -> next = NULL;
                if (*head2 == NULL)
                {
                        *head2 = new;
                        *tail2 = new;
                        continue;
                }
                (*tail2) -> next = new;
                *tail2 = new;
        }

}
/* Insert first Function */
int insert_first(Dlist **head, Dlist **tail, int data)
{
	// Allocate memory for new node
    	Dlist *new = malloc(sizeof(Dlist));
    	if(new == NULL)
    	{
        	return FAILURE;
    	}
    	new -> data = data;  
    	new -> prev = NULL;  
    	new -> next = *head; // The next node is the current head of the list
    	if(*head == NULL)
    	{
        	*head = new;  
        	*tail = new;  
        	return SUCCESS;
    	}
    	(*head)-> prev = new;  // Update the previous pointer of the old head
    	*head = new;           
    	return SUCCESS;

}
/* Remove Zeros Function */
void remove_zero(Dlist *headR)
{
	// Traversing list upto NULL
	while (headR != NULL)
	{
		
		if (headR -> data == 0)
		{
			headR = headR -> next;
			free(headR -> prev);
			headR -> prev = NULL;
		}
		else
		{
			break;
		}
	}
	print_list(headR, 1);
}
/* Print list Function */
void print_list(Dlist *headR, int flag)
{
        /* Checking the list is empty or not */
        if (headR == NULL)
        {
                printf("INFO : list is empty\n");
        }
	if (flag == 1)
	{
		while (headR)
		{
			printf("%d", headR -> data);
			headR = headR -> next;
		}
	}
        else
        {
                while(headR)
                {
                        /* Printing the list */
                        printf("%d", headR -> data);

                        /*Traversing in forward direction */
                        headR = headR -> prev;
		}
	}
    printf("\n");
}

void insert_at_end(Dlist **head, Dlist **tail, int data)
{
        // Create new node
        Dlist *new = malloc(sizeof(Dlist));
        if (!new)
        {
                printf("Memory allocation failed\n");
                return;
        }

                new->data = data;
                new->next = NULL;
                new->prev = NULL;

                // If list is empty
        if (*head == NULL)
        {
                *head = new;
                *tail = new;
        }
        else
        {
                // Link the new node at the end
                new->prev = *tail;
                (*tail)->next = new;
                *tail = new;
        }
}

int compare_lists(Dlist *head1, Dlist *head2)
{
        // Count lengths
        int len1 = 0, len2 = 0;
        Dlist *temp1 = head1, *temp2 = head2;

        while (temp1) 
        {
                len1++; temp1 = temp1->next;
        }
        while (temp2) 
        {
                len2++; temp2 = temp2->next;
        }

        if (len1 > len2) return 1;
        if (len2 > len1) return -1;

        // If lengths are equal, compare digit by digit
        temp1 = head1; temp2 = head2;
        while (temp1 && temp2) 
        {
                if (temp1->data > temp2->data) return 1;
                if (temp1->data < temp2->data) return -1;
                temp1 = temp1->next;
                temp2 = temp2->next;
        }
        return 0; // equal
}
        // Subtracts head2 from head1 (head1 >= head2)
int subtract_lists(Dlist **head1, Dlist **tail1, Dlist *head2, Dlist *tail2)
{
    Dlist *p1 = *tail1;
    Dlist *p2 = tail2;
    int borrow = 0;

    while (p2)
    {
        int diff = p1->data - p2->data - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        p1->data = diff;
        p1 = p1->prev;
        p2 = p2->prev;
    }

    while (borrow && p1)
    {
        int diff = p1->data - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        p1->data = diff;
        p1 = p1->prev;
    }
}
// Creates a deep copy of src list into dest
void copy_list(Dlist *src_head, Dlist **dest_head, Dlist **dest_tail)
{
        Dlist *temp = src_head;
        while (temp)
        {
                insert_at_end(dest_head, dest_tail, temp->data);
                temp = temp->next;
        }
}

int is_valid_number(char *str)
{
        if(str == NULL || str[0] == '\0')  // check empty
                return 0;

        int i = 0;
        while (str[i] != '\0')
        {
                if (str[i] < '0' || str[i] > '9')  // not a digit
                return 0;
                i++;
        }

        return 1;  // all characters are digits
}

void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    // Skip all 0s except if only one node remains (i.e., result = 0)
        while (*head && (*head)->data == 0 && (*head)->next != NULL)
        {
                Dlist *temp = *head;
                *head = (*head)->next;
                (*head)->prev = NULL;
                free(temp);
        }

    // Recalculate tail
        if (*head == NULL)
        {
                *tail = NULL;
        }
        else
        {
                Dlist *temp = *head;
                while (temp->next)
                temp = temp->next;
                *tail = temp;
        }
}