
#include "methods.h"
#include "user.h"
#include "admin.h"

int main()
{
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }

    char ch = Case();
    printf("\n");

    if(ch == 'a' )
    {
        int option = Show_option_Admin();

        if(check_pass_Admin(file)==0)
        return 1;

        switch (option)
        {
            case 1:                              
            {
                ADD_new_record(file);                  
                break;
            }
            case 2:
            {
                
                char id[100];
                printf("Enter ID : ");
                scanf("%s", id);
                Remove_record(file, id);
                break;
            }
            case 3:
            {
                char id[100];
                printf("Enter ID : ");
                scanf("%s", id);
                Show_record(file, id);
                break;
            }
            case 4:
            {
                char id[100];
                printf("Enter ID : ");
                scanf("%s", id);
                Show_all_records(file, id);
                break;
            }
            case 5:
            {
                Edit_pass_Admin(file);
                break;
            }
            case 6:
            {
                char id[100];
                printf("Enter ID : ");
                scanf("%s", id);
                Edit_grade(file, id);
                break;
            }

            default:
            // wrong data
            break;
        }

    }
    else if(ch == 'u')
    {
        int option = Show_option_User();

        switch (option)
        {
            case 1:                              
            {
                char id[100];
                printf("Enter ID : ");
                scanf("%s", id);
                Show_record_user(file,id);                  
                break;
            }
            case 2:
            {
                
                char id[100];
                printf("Enter ID : ");
                scanf("%s", id);
                Edit_pass_user(file,id);

                /*int count =3;
                while(count--)
                {
                    char pass[100]=Get_pass();
                    if(Check_user_pass(file,id))
                    {
                        Edit_pass_user(file,id);
                        break;
                    }
                    else
                    {
                        printf("invalid password");
                    }
                }*/
                break;
            }
            case 3:
            {
                char id[100];
                printf("Enter ID : ");
                scanf("%s", id);
                Edit_name(file ,id);
                break;
            }

        }
    }

    else
    {
        printf("wrong data try agian");
    }



    fclose(file); 
    return 0;
}

