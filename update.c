#include "main.h"
int valid_backfile(char *str);
void update_database(main_info** arr,f_name **head) //This function for update database
{
    char str[100];
    printf("Give the file : ");
    scanf("%s",str);
    if(valid_backfile(str) == 0) //validating the newfile
    {
        return;
    }
    FILE *fp = fopen(str,"r"); //open the file in read mode
    
    int index,f_count,w_count;
    char word[20],fname[20];
    if((fscanf(fp,"#%d;%[^;];%d;%[^;];%d",&index,word,&f_count,fname,&w_count))==0) //checking file is database file or not
    {
        printf("It is not a valid file\n");
        return;
    }
    printf("before : %d %s %d ",index,word,f_count);
    rewind(fp);
    while(fscanf(fp,"#%d;%[^;];%d;%[^;];%d",&index,word,&f_count,fname,&w_count)==5) //reading the input from file or saving into database
    {
    
      // printf("%d %s %d ",index,word,f_count);

        insert_at_first_in_main(&arr[index],word);
        arr[index]->f_count = f_count;
        insert_at_first_in_sub(&(arr[index]->sub_link),fname);
        arr[index]->sub_link->word_count = w_count;
        insert_at_first(head,fname);
        for(int i = 0;i<f_count-1;i++)
        {
            fscanf(fp,";%[^;];%d",fname,&w_count);

            printf("%s %d\n",fname,w_count);
            insert_at_first_in_sub(&(arr[index]->sub_link),fname);
            arr[index]->sub_link->word_count = w_count;
            insert_at_first(head,fname);
        }
        fgetc(fp);
        fgetc(fp);
        fgetc(fp);
    }
}
int valid_backfile(char *str)
{
    char *str1 = strstr(str,".txt");
    //printf("%s\n",str1);
    if(str1 == NULL ||(strcmp(str1,".txt"))!=0 )
    {
        printf("Give the proper file name\n");
        //i++;
        return 0;
    }
    if((check_exist(str))!=1)
    {
        printf("%s this file not exits \n",str);
        //i++;
        return 0;
    }
    return 1;
    
}