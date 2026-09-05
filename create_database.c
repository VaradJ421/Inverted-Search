#include "main.h"

void create_database(main_info **arr,f_name *head) // Function to create database from all input files
{
    int index;
    FILE*fp = NULL;
    while(head != NULL)  //Traverse through all files
    {
        fp = openfile(head->fname);   // Open current file
        char str[100];
        while(feof(fp) == 0)
        {
            fscanf(fp,"%s",str);
          
            if(isalpha(str[0]))        // Read words until end of file
            {
                char ch = toupper(str[0]);
                index = (ch - 'A');   // Calculate array index
                if(arr[index] == NULL)
                {
                    insert_at_first_in_main(&arr[index],str);
                    insert_at_first_in_sub(&(arr[index]->sub_link),head->fname);
                    arr[index]->f_count = 1;
                    arr[index]->sub_link->word_count = 1;
                    continue;
                }
                main_info *ptr = check_word(arr[index],str);  // Check whether word already exists
                if(ptr==NULL)  // If word not found
                {
                    insert_at_first_in_main(&arr[index],str);
                    insert_at_first_in_sub(&(arr[index]->sub_link),head->fname);
                    arr[index]->f_count = 1;
                    arr[index]->sub_link->word_count = 1;
                }
                else
                {
                    sub_info *s=check_file((ptr->sub_link),head->fname);  // Check whether file already exists in sub list
                    if(s==NULL)
                    {
                       insert_at_first_in_sub(&ptr->sub_link,head->fname);
                       ptr->f_count++;
                       ptr->sub_link->word_count = 1;
                    }
                    else
                    {
                        s->word_count++;
                    }
                }
            }
            else // Store special character words at index 26
            {
                index = 26; 
                insert_at_first_in_main(&arr[index],str);
                insert_at_first_in_sub(&(arr[index]->sub_link),head->fname);
                arr[index]->f_count = 1;
                arr[index]->sub_link->word_count = 1;
            }

        }
        fclose(fp);
        head = head->link;
    }
}
sub_info* check_file(sub_info *ptr,char *str) // Function to check whether file already exists in sub list
{
    if(ptr == NULL)
    {
        return NULL;
    }
    while(ptr!=NULL)
    {
        if(strcmp(ptr->f_name,str) == 0)
        {
            return ptr;
        }
        ptr = ptr->link;
    }
    return NULL;
}
main_info* check_word(main_info *arr,char *str) // Function to check whether word exists in database
{
    main_info *temp = arr;
    while(temp != NULL)
    {
        if((strcmp(temp->word,str))==0)
        {
            return temp;
        }
        temp = temp->main_link;
    }
    return NULL;
}
int insert_at_first_in_sub(sub_info  **head, char* data) // Function to insert node at beginning of sub list
{
	sub_info *temp = *head;
	*head = malloc(sizeof(sub_info));
	strcpy((*head)->f_name ,data);
	(*head)->link= temp;
	return 1;
	
}
int insert_at_first_in_main(main_info  **head, char* data) // Function to insert node at beginning of main list
{
	main_info *temp = *head;
	*head = malloc(sizeof(main_info));
	strcpy((*head)->word ,data);
	(*head)->main_link = temp;
     (*head)->sub_link = NULL;
	return 1;
	
}
FILE *openfile(char *str) // Function to open file in read mode
{
    FILE *fp = fopen(str,"r");
    if(fp == NULL)
    {
        return NULL;
    }
    else
        return fp;
}