#include "apc.h"
#include <string.h>

int main(int argc,char *argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL,*tailR=NULL;

	if(argc == 4)
	{
		/* put argv[1] digits into list‑1 */
        for (int i = 0; argv[1][i]; i++)
        insert_at_end(&head1, &tail1, argv[1][i] - '0');

         /* put argv[3] digits into list‑2 */
        for (int i = 0; argv[3][i]; i++)
        insert_at_end(&head2, &tail2, argv[3][i] - '0');
		if(!is_valid_number(argv[1]) || !is_valid_number(argv[3]))
		{
			printf("Invalid input: Please enter only digits (0-9)\n");
			return 1;
        }
		//if(read_and_validate(argv) == SUCCESS)
		{
			char operator = argv[2][0];

                switch (operator)
		    {
			    case '+':
                        //insert_first(&head2,&tail2,atoi(argv[1]));
				        /* call the function to perform the addition operation */
                        if(addition(&head1,&tail1,&head2,&tail2,&headR,&tailR)==SUCCESS)
				        {
					        printf("Addition Result: ");
					        //print the result list
					        print_list(headR, 1);
				        }
			            else
				        {
					        printf("Addition is unsuccessful: ");
				        }
				        break;
			    case '-':	
				        /* call the function to perform the subtraction operation */
						//printf("Performing Subtraction.\n");
						if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR)==SUCCESS)
				        {
					        printf("Subtraction Result: ");
					        //print the result list
					        print_list(headR, 1);
				        }
			            else
				        {
					        printf("Subtraction is unsuccessful: ");
				        }
				        break;
			    case '*':	
				        /* call the function to perform the multiplication operation */
						if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
						{
							printf("Multiplication Result: ");
							print_list(headR, 1);
						}
						else
						{
						printf("Multiplication failed\n");
						}
						break;
			    case '/':	
				        /* call the function to perform the division operation */
						//printf("Performing Division:\n");
						if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
						{
							printf("Division Result: ");
							print_list(headR, 1);
						}
						else
						printf("Division failed\n");

				        break;
			    default:
				        printf("Invalid Input:-( Try again...\n");
		    }
		}
	}
	else
	{
		printf("Arguments is less than four please try again\n");
	}
	return 0;
}
