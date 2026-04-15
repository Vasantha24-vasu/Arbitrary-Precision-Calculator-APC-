#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	
    Dlist *temp2 = *tail2;
    int shift = 0;

    // Outer loop – goes through digits of second number (right to left)
    while (temp2)
    {
        Dlist *temp1 = *tail1;
        Dlist *headT = NULL, *tailT = NULL;  // Temporary list for one row of multiplication

        int carry = 0;
        while (temp1)
        {
            int mul = temp1->data * temp2->data + carry;
            insert_first(&headT, &tailT, mul % 10);
            carry = mul / 10;

            temp1 = temp1->prev;
        }

        if (carry)
            insert_first(&headT, &tailT, carry);

        // Add required number of trailing zeros
        for (int i = 0; i < shift; i++)
            insert_at_end(&headT, &tailT, 0);

        // Add this temp row to result list
        if (*headR == NULL)
        {
            // If first row, just copy temp
            Dlist *copy = headT;
            while (copy)
            {
                insert_at_end(headR, tailR, copy->data);
                copy = copy->next;
            }
        }
        else
        {
            // Add this temp row to result list using addition()
            Dlist *tempHead = NULL, *tempTail = NULL;
            Dlist *copy = headT;
            while (copy)
            {
                insert_at_end(&tempHead, &tempTail, copy->data);
                copy = copy->next;
            }

            Dlist *resHead = NULL, *resTail = NULL;
            addition(headR, tailR, &tempHead, &tempTail, &resHead, &resTail);

            // clear headR and assign new result
            *headR = resHead;
            *tailR = resTail;
        }

        shift++;
        temp2 = temp2->prev;
    }

    // Remove leading zeros
    while (*headR && (*headR)->data == 0 && (*headR)->next)
    {
        Dlist *del = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(del);
    }

    return SUCCESS;
}