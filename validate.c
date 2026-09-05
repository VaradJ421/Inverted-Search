#include "main.h"

int validate(int count,char *str[],f_name **head)
{
    if(count <=1)
    {
        return 0;
    }
    int i =1;
    while(str[i]!=NULL)
    {
        char *str1 = strstr(str[i],".txt");
        //printf("%s\n",str1);
        if(str1 == NULL ||(strcmp(str1,".txt"))!=0 )
        {

            printf("Give the proper file name\n");
            i++;
            continue;
        }
        if((check_exist(str[i]))!=1)
        {
            printf("%s this file not exits \n",str[i]);
            i++;
           continue;
        }
        if(check_duplicate(str[i] ,head) == 1)
        {
           insert_at_first(head, str[i]);
        }
        else
        {
            printf("%s This file is present more then one time\n",str[i]);
        }
        i++;

    }
    return 1;
}
int insert_at_first(f_name **head, char* data)
{
	f_name *temp = *head;
	*head = malloc(sizeof(f_name));
	strcpy((*head)->fname,data);
	(*head)->link = temp;
	return 1;
	
}
int check_duplicate(char *str ,f_name** head)
{
    f_name *temp = *head;
    if(*head == NULL)
    {
        return 1;
    }
    while(temp != NULL)
    {
        if((strcmp(temp->fname,str))==0)
        {
            return 0;
        }
        temp = temp->link;
    }
    return 1;
}
int check_exist(char *str)
{
    FILE *fp = fopen(str,"r");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,0,SEEK_END);
    if((ftell(fp))==0)
    {
        fclose(fp);
        return 0;
    }
    else
    {
        fclose(fp);
        return 1;
    }
}