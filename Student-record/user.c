#include <stdio.h>
#include <windows.h>

#include <string.h>
#include <stdbool.h>
#define bool int 
#define true 1
#define false 0

typedef struct student
{
    char id[20];
    char fullname[3][100];
    char pass[100];
    int age;
    char gender[10];
    int total_grade;
}student;



void Show_record_user(FILE *file, char* id) 
{
    student new_student;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }
    char password[20];
    int line_count = 0; // Counter to track the line number

    bool found = false;
    char line[300]; 
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (line_count == 0) 
        {   sscanf(line,"%s",password);
            fprintf(temp_file, "%s\n",password);
            line_count++;
            continue;
        }

        sscanf(line, "%s %s %s %s %s %d %s %d", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
        
        fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], new_student.age, new_student.gender, new_student.total_grade);

        if (!strcmp(id, new_student.id)) 
        {
            printf("\n\n\t==================================================================\n\n");
            printf("\t\t\t\t\tYOUR RECORD\n");
            printf("Full Name: %s %s %s\n", new_student.fullname[0], new_student.fullname[1], new_student.fullname[2]);
            printf("Password: %s\n", new_student.pass);
            printf("ID: %s\n", new_student.id);
    
            found = true;
        }
      
    }
    if (!found)
    printf("ID does not found");

    fclose(temp_file);
    fclose(file);
    remove("file.txt"); 
    rename("temp.txt", "file.txt");

}


void Edit_pass_user(FILE *file, char* id) 
{
    student new_student;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }

    int line_count = 0; // Counter to track the line number
    char password[20];
    char line[300]; 
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (line_count == 0) 
        {   sscanf(line,"%s",password);
            fprintf(temp_file, "%s\n",password);
            line_count++;
            continue;
        }

        sscanf(line, "%s %s %s %s %s %d %s %d", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
        if (!strcmp(id, new_student.id)) 
        {
            char newpass[100];
            printf("Enter new password: ");
            scanf("%s", newpass);
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, newpass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], new_student.age, new_student.gender, new_student.total_grade);
            printf("Password updated successfully.\n");
        }
        else 
        {
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass,new_student.fullname[0], new_student.fullname[1],new_student. fullname[2], new_student.age, new_student.gender,new_student. total_grade);
        }
    }
    fclose(temp_file);
    fclose(file);

    remove("file.txt"); 
    rename("temp.txt", "file.txt"); 
}


void Edit_name(FILE *file, char* id)
{
    student new_student;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }

    int line_count = 0; // Counter to track the line number
    char password[20];
    char line[300]; 
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (line_count == 0) 
        {   
            sscanf(line, "%s", password);
            fprintf(temp_file, "%s\n", password);
            line_count++;
            continue;
        }

        sscanf(line, "%s %s %s %s %s %d %s %d", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
        if (!strcmp(id, new_student.id)) 
        {
            printf("\t\t================Enter you new name================\n");
            printf("\n\t\t\t\tFirst Name  : ");
            scanf("%s",new_student.fullname[0]);
            printf("\t\t\t\tSecond Name : ");
            scanf("%s",new_student.fullname[1]);
            printf("\t\t\t\tThird Name  : ");
            scanf("%s",new_student.fullname[2]);
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], new_student.age, new_student.gender, new_student.total_grade);
            printf("\n\t\t================ Name updated successfully ================\n");
        }
        else 
        {
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], new_student.age, new_student.gender, new_student.total_grade);
        }
    }
    fclose(temp_file);
    fclose(file);

    remove("file.txt"); 
    rename("temp.txt", "file.txt"); 
}
