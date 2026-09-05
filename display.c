#include"main.h"
void display(main_info **arr) // Function to display the database contents
{
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("%10s|%20s|%7s|%15s|%7s|\n","index","word","f_count","f_name","w_count");
    printf("-------------------------------------------------------------------------------------------------\n");
    for(int i = 0;i<=26;i++) // Traverse through all index positions
    {
        if(arr[i]==NULL)
        {
            continue; 
        }
        main_info *main = arr[i];
        while (main != NULL)
        {
            //printf("%10d|%20s|%7d|",i,main->word,main->f_count);
            sub_info *temp = main->sub_link;
            while(temp != NULL)
            {
                printf("%10d|%20s|%7d|",i,main->word,main->f_count);
                printf("%15s|%7d|\n",temp->f_name,temp->word_count);
                temp = temp->link;
            }
            main = main->main_link;
        }
        printf("--------------------------------------------------------------------------------------------\n");
        
    }
}