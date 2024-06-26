
#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include "admin.c"


#define bool int 
#define true 1
#define false 0

struct student;


bool check_pass_Admin(FILE *file);

void Edit_pass_Admin(FILE *file);

void ADD_new_record(FILE *file);

void Remove_record(FILE *file, char* id);

void Show_record(FILE *file, char* id);

void Show_all_records(FILE *file,char* id);

void Edit_grade(FILE *file, char* id);

#endif