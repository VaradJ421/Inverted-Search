#if 0
Project : inverted search
Name : shubham jagtap
Description: Built an Inverted Search system to perform fast word-based file searching.
Implemented linked lists and hash table concepts for efficient indexing and retrieval.
Supported keyword search across multiple files with optimized search complexity.
Developed using C language with file handling and DSA concepts.
#endif
#include<stdio.h>
#include "main.h"
void print_list(f_name *head);
int new_files(f_name *head1 ,f_name *head2,f_name**res);
int main(int argc,char *argv[])
{
    main_info *arr[27]={NULL};  // Array of pointers for hash table database

	
    f_name *head = NULL;
	f_name *backup = NULL;
	f_name *new_f = NULL;
    validate(argc,argv,&head);      // Validate command line arguments and create file list
   // print_list(head);
	int flag = 0,update = 0;     // Flags to track database creation and update status
	int option;
	while(1)     // Infinite loop for menu-driven operations
	{

		printf("Select your choice among following options:\n1.Create DATABASE\n2.Display Database\n3.Search\n4.Save DATABASE\n5.Update DATABASE\n6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&option);
		switch (option)   // Perform operation based on user choice
		{
		case 1:
		
		if(flag == 0 && update == 1)
		{
			new_files(head ,backup,&new_f);
			print_list(new_f);
			create_database(arr,new_f);
			printf("Database created successful\n");
		}
		else if(flag == 0)
		{
			create_database(arr,head);
			printf("\nDatabase created successful\n\n");
			flag = 1;
		}
		else
		{
			printf("\nDatabase is already created\n\n");
		}

			break;
		case 3:if(search(arr))
				{
					printf("\nData found and successfully displayed\n\n");
				}
				else{
					printf("\nData not found\n\n");
				}
			break;
		case 2:display(arr);
			break;
		case 4:save_database(arr);
				break;
		case 5:
		if(flag == 0)
		{
			update_database(arr,&backup);
			//printf("Database updated successful\n");
			//flag =1;
			update = 1;
			printf("backup list : ");
			print_list(backup);
		}
		else
		{
			printf("\nDatabase is already created\n\n");
		}

		break;
	    case 6:return 0;
		}
	}
}
int new_files(f_name *head1 ,f_name *head2,f_name**res)  // Function to find files not present in backup list
{
	f_name *temp = *res;
	f_name *t1 = head1;
	f_name *t2 ;
	while(t1 != NULL)
	{
		int count = 0;
		t2= head2;
		while(t2!=NULL)
		{
			if(strcmp(t1->fname,t2->fname) == 0)
			{
			   count = 1;
			   break;
			}
			t2 = t2->link;
		}
		if(count == 0)
		{
			insert_at_first(res,t1->fname);
		}
		t1 = t1->link;
	}
}
void print_list(f_name *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head ->fname);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}