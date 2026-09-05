#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct file_name
{
    char  fname[20];
    struct file_name *link;
}f_name;

typedef struct sub_info
{
    char f_name[20];
    int word_count;
    struct sub_info *link;
}sub_info;

typedef struct main_info
{
    char word[20];
    int f_count;
    sub_info *sub_link;
    struct main_info *main_link;
}main_info;
int check_exist(char *str);
int check_duplicate(char *str ,f_name** head);
int insert_at_first(f_name **head, char* data);
int validate(int count,char *str[],f_name **head);
void create_database(main_info **arr,f_name *head);
void display(main_info **arr);
int search(main_info **arr);
void save_database(main_info **arr);
void update_database(main_info** arr,f_name **);
FILE *openfile(char *str);
int insert_at_first_in_main(main_info  **head, char*data);
int insert_at_first_in_sub(sub_info  **head, char* data);
main_info* check_word(main_info *arr,char *str);
sub_info *check_file(sub_info *ptr,char *str);
#endif
