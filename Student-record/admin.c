
#include <stdio.h>
#include <windows.h>

#include <string.h>
#include <stdbool.h>
#define bool int 
#define true 1
#define false 0

// typedef struct student
// {
//     char id[20];
//     char fullname[3][100];
//     char pass[100];
//     int age;
//     char gender[10];
//     int total_grade;
// }student;

bool check_pass_Admin(FILE *file) 
{
    char password[20];
    int count = 3;

    char pass[100];
    while (fscanf(file, "%s", pass) != EOF) 
    {
        while(count != 0) 
        {
            printf("Enter password: ");
            scanf("%s", password);
            if (!strcmp(pass, password)) 
            {
                printf("Welcome .^_^.\n");
                return true;
            } 
            else 
            {
                count--;
                if (count == 0)
                {
                    break;
                }
                printf("Sorry, password is wrong! Try again\n");
            }
        } 
    }
    printf("Sorry *_*, No more tries ...\n");
    return false;
}


void Edit_pass_Admin(FILE *file)
{
    student new_student;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }

    int line_count = 0;
    char password[20];
    char line[300]; 
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (line_count == 0) 
        {   char newpass[100];
            printf("Enter new password of Admin: ");
            scanf("%s", newpass);
            fprintf(temp_file, "%s\n",newpass);
            printf("Password updated successfully.\n");
            line_count++;
            continue;
        }
         else 
        {
            sscanf(line, "%s %s %s %s %s %d %s %d", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], &new_student.age, new_student.gender, &new_student.total_grade);
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass,new_student.fullname[0], new_student.fullname[1],new_student. fullname[2], new_student.age, new_student.gender,new_student. total_grade);
        }
    }
    fclose(temp_file);
    fclose(file);

    remove("file.txt"); 
    rename("temp.txt", "file.txt"); 
}

void ADD_new_record(FILE *file) 
{
    student new_student;
    file = fopen("file.txt", "a");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter student information:\n");
    printf("ID: ");
    scanf("%s", &new_student.id);
    printf("Password: ");
    scanf("%s", new_student.pass);
    printf("Full Name : ");
    for (int i = 0; i < 3; i++) 
    {
        scanf("%s",new_student.fullname[i]);
    }
    printf("Age: ");
    scanf("%d", & new_student.age);
    printf("Gender: ");
    scanf(" %s", &new_student.gender);
    printf("Total Grade: ");
    scanf("%d", &new_student.total_grade);

    fprintf(file, "%s %s %s %s %s %d %s %d\n", new_student.id ,new_student.pass ,new_student.fullname[0], new_student. fullname[1],new_student. fullname[2],new_student. age,new_student. gender,new_student.total_grade);

    printf("New student added successfully.\n");
    fclose(file);
}






void Remove_record(FILE *file, char* id) 
{
    student new_student;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }
    char password[20];

    int record_removed = 0; 
    int line_count = 0; // Counter to track the line number

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
            record_removed = 1;
            printf("Student record removed successfully.\n");
        }
        else 
        {
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], new_student.age, new_student.gender, new_student.total_grade);
        }
    }

    fclose(temp_file);
    fclose(file);

    if (record_removed) 
    {
        remove("file.txt"); 
        rename("temp.txt", "file.txt");
    } 
    else
    {
        printf("Record with ID '%s' not found.\n", id);
        remove("temp.txt"); 
    }
}


void Show_record(FILE *file, char* id) 
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


void Show_all_records(FILE *file,char* id) 
{
    student new_student;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }

    bool found = false;
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
        
        fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2], new_student.age, new_student.gender, new_student.total_grade);

        if (!strcmp(id, new_student.id)) 
        {
            printf("Full Name: %s %s %s\n", new_student.fullname[0], new_student.fullname[1], new_student.fullname[2]);
            printf("Password: %s\n", new_student.pass);
            printf("ID: %s\n", new_student.id);
            printf("Age: %d\n", new_student.age);
            printf("Gender: %s\n", new_student.gender);
            printf("Total Grade: %d\n", new_student.total_grade);
            
            found = true;
        }
      
    }
    if (!found)
    printf("ID not found");

    fclose(temp_file);
    fclose(file);
    remove("file.txt"); 
    rename("temp.txt", "file.txt");
}


void Edit_grade(FILE *file, char* id) 
{
    student new_student;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
    {
        printf("Error opening temporary file.\n");
        return;
    }

    bool found = false;
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
            int new_grade;
            printf("Enter new grade: ");
            scanf("%d", &new_grade);
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass, new_student.fullname[0], new_student.fullname[1], new_student.fullname[2],new_student.age,new_student. gender, new_grade);
            printf("Grade updated successfully.\n");
            found = true;
        }
        else 
        {
            fprintf(temp_file, "%s %s %s %s %s %d %s %d\n", new_student.id, new_student.pass,new_student.fullname[0], new_student.fullname[1],new_student. fullname[2], new_student.age, new_student.gender,new_student. total_grade);
        }
    }

    if (!found)
    {
        printf("ID not found");
    }
    fclose(temp_file);
    fclose(file);

    remove("file.txt"); 
    rename("temp.txt", "file.txt"); 
 
}