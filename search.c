#include"main.h"
int search(main_info **arr)  //This function for search data into database
{
    char str[100];
    printf("Give the data you want search : ");
    scanf(" %s",str);
    int index = toupper(str[0]) - 'A';

    main_info*temp = arr[index];
    while(temp != NULL)
    {
        if((strcmp(temp->word,str))==0)
        {
            printf("-----------------------------------------------------------------------\n");
            printf("%10s|%20s|%7s|%15s|%7s|\n","index","word","f_count","f_name","w_count");
            printf("----------------------------------------------------------------------\n");
            sub_info *temp1 = temp->sub_link;
            while(temp1!=NULL)
            {
                 printf("%10d|%20s|%7d|",index,temp->word,temp->f_count);
                printf("%15s|%7d|\n",temp1->f_name,temp1->word_count);
                temp1 = temp1->link;
                return 1;
            }
        }
        temp = temp->main_link;
    }
    return 0;
}