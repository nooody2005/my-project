#ifndef USER_H
#define USER_H

#include <stdio.h>
#include "user.c"


#define bool int 
#define true 1
#define false 0

struct student;


void Show_record_user(FILE *file, char* id); 

void Edit_pass_user(FILE *file, char* id);

void Edit_name(FILE *file , char* id);



#endif