#include<stdio.h>
#include<stdlib.h>

#include "structure.c"
#include "prototype.c"
#include "function_body.c"

int main()
{
	int ch;
	emp *head=NULL;
	while(1)
	{
		printf("\n1.Enter the employee details\n2.Display all employee details\n3.Delete an employee details");
		printf("\n4.Show a particular details\n5.Show MINIMUM and MAXIMUM salary\n99.exit\nEnter your choice : ");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
			case 1: head=insert(head);
				break;
			case 2: display(head);
				break;
			case 3: head=delete(head);
				break;
			case 4: show_a_details(head);
				break;
			case 5: min_max(head);
				break;
			case 99:exit(0);
			default:printf("\nPlease enter a correct choice !!");
		}
	}
}
