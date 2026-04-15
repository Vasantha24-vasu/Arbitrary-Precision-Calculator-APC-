#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
    if ((*head2)->data == 0 && (*head2)->next == NULL)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    // Compare dividend and divisor
    int cmp = compare_lists(*head1, *head2);
    if (cmp < 0)
    {
        insert_at_end(headR, tailR, 0);
        return SUCCESS;
    }
    else if (cmp == 0)
    {
        insert_at_end(headR, tailR, 1);
        return SUCCESS;
    }

    Dlist *temp1 = *head1;
    Dlist *dividend = NULL, *dividend_tail = NULL;

    while(temp1)
    {
        insert_at_end(&dividend, &dividend_tail, temp1->data);
        remove_leading_zeros(&dividend, &dividend_tail);

        int count = 0;
        while (compare_lists(dividend, *head2) >= 0)
        {
            subtract_lists(&dividend, &dividend_tail, *head2, *tail2);
            count++;
        }

        insert_at_end(headR, tailR, count);
        temp1 = temp1->next;
    }

    remove_leading_zeros(headR, tailR);
    return SUCCESS;
}
