#include "main.h"
int check(char *str);
void save_database(main_info **arr) // Function to save database into a text file
{
    char str[100];
     start:    // Label for re-entering filename
    printf("Give the file name to save: ");
    scanf(" %s",str);
    char *str1 = strstr(str,".txt");
    if(str1 == NULL ||(strcmp(str1,".txt"))!=0 )
    {
        printf("Give the proper file name\n");
        goto start;
    }
    int i;
    if(check(str)==0) // Check whether file already contains data
    {
        printf("file is already having same data choice the option\n");
        printf("1.New filename.\n2.overwrite\n3.exit\n ");
        scanf("%d",&i);
        switch (i)
        {
        case 1:goto start;
            break;
        case 3:return;
        }
    }
    FILE *fp = fopen(str,"w");
    if(fp == NULL)
    {
        printf("file is not opened\n");
        return;
    }
    for(int i = 0;i<=26;i++)
    {
        if(arr[i]==NULL)
        {
            continue;
        }
        main_info *main = arr[i];
        while(main!=NULL)
        {
            fprintf(fp,"#%d;%s;%d;",i,main->word,main->f_count);
            sub_info *temp = main->sub_link;
            while(temp!=NULL)
            {
                fprintf(fp,"%s;%d;",temp->f_name,temp->word_count);
                temp = temp->link;
            }
            fprintf(fp,"#\n");
            main = main->main_link;
        }
    }
    fclose(fp);
}
int check(char *str) // Function to check whether file exists and contains data
{
    FILE *fp = fopen(str,"r");
    if(fp==NULL)
    {
        return 1;
    }
    fseek(fp,0,SEEK_END);
    if((ftell(fp))!=0)
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