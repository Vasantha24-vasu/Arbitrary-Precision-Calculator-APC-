#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int cmp = compare_lists(*head1, *head2);
    int is_negative = 0;

    // Swap if head1 < head2
    if (cmp < 0)
    {
        // Swap heads
        Dlist *temp = *head1;
        *head1 = *head2;
        *head2 = temp;

        // Swap tails
        temp = *tail1;
        *tail1 = *tail2;
        *tail2 = temp;

        is_negative = 1;
    }
    else if (cmp == 0)
    {
        insert_first(headR, tailR, 0);
        return 0;  // SUCCESS
    }

    // Perform subtraction now
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0;

    while (temp1 || temp2)
    {
        int num1 = (temp1) ? temp1->data : 0;
        int num2 = (temp2) ? temp2->data : 0;

        num1 -= borrow;

        if (num1 < num2)
        {
            num1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int diff = num1 - num2;
        insert_first(headR, tailR, diff);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    // Remove leading zeros
    while (*headR && (*headR)->data == 0 && (*headR)->next)
    {
        Dlist *del = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(del);
    }

    //Instead of inserting -1, just store is_negative
    if (is_negative)
        (*headR)->data = -(*headR)->data;  // Make the first digit negative

    return SUCCESS;  // SUCCESS
}

