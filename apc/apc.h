#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*Read and validate*/
int read_and_validate(char *argv[]);

/*Insert digit*/
void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

/*Remove zeros*/
void remove_zero(Dlist *headR);

/*Delete list*/
int delete_list(Dlist **head, Dlist **tail);

/*Print list*/
void print_list(Dlist *headR, int flag);

/*Insert first*/
int insert_first(Dlist **head, Dlist **tail, int data);

/*Insert at end*/
void insert_at_end(Dlist **head, Dlist **tail, int data);

/*Compare lists*/
int compare_lists(Dlist *head1, Dlist *head2);

/*Addition */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Division */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*remove leading zeros*/
void remove_leading_zeros(Dlist **head, Dlist **tail);

int subtract_lists(Dlist **head1, Dlist **tail1, Dlist *head2, Dlist *tail2);

int is_valid_number(char *str);

void remove_leading_zeros(Dlist **head, Dlist **tail);

#endif
