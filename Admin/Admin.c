#include "Admin.h"

// Edit Student Name

char *EditAdminName(struct AdminNode *Head,long ID){

    AdminNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            printf("\n-----------<Edit Your Name>-----------\n"
                   "Enter your Name : " );

            Current->Data.Name = ValidName();
        }
        Current = Current->Link;
    }
    return "\n\"Name Edited Successfully\"\n\n";
}

// Edit Student password

char *EditAdminPassword(AdminNode *Head,long ID){

    AdminNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            printf("\n-----------<Edit Your Password>-----------\n"
                   "Enter your password : ");

            Current->Data.Password = CheckingPasswordStrength();
        }
        Current = Current->Link;
    }
    return "\n\"Password Edited Successfully\"\n\n";
}


// Choose Admin Features

void  ChooseAdminFeatures(AdminNode *AdminHead, StudentNode **StudentHead, long ID){

    while(1) {
        printf("\n--------------------------Hello, %s--------------------------\n\n", AdminName(AdminHead, ID));
        printf("\n\nEnter Appropriate Choice...\n");
        int choice1;
        char *temp;
        do {
            printf("\n1. Student Affairs\t\t\t2. Edit your information\t\t\t3. Quit\nYour Choice Number : ");
            fflush(stdout);
            temp = SetString();
            choice1 = atoi(temp);
        } while ((choice1 != 1 && choice1 != 2 && choice1 != 3) && printf("Invalid Choice! please try again..\n"));

        if (choice1 == 1) {
            while (1) {
                int choice = StudentAffairsValidate(AdminHead, ID);
                bool Quit = false;
                switch (choice) {
                    case 1:
                        AddNewStudent(StudentHead);
                        break;
                    case 2:
                        DeleteStudent(*StudentHead, ID);
                        break;
                    case 3:
                        PrintStudentInfo_ForAdmin(*StudentHead, ID);
                        break;
                    case 4:
                        PrintAllRecords(*StudentHead);
                        break;
                    case 5:
                        ModifyStudentGrade(*StudentHead, ID);
                        break;
                    case 6:
                        Quit = true; break;

                }
                if (Quit) break;
            }
        } else if (choice1 == 2) {
            while (1) {
                int choice = EditAdminInfoValidate(AdminHead, ID);
                bool Quit = false;
                switch (choice) {
                    case 1:
                        printf("%s", EditAdminName(AdminHead, ID));
                        break;
                    case 2:
                        printf("%s", EditAdminPassword(AdminHead, ID));
                        break;
                    case 3:
                        Quit = true;
                        break;
                }
                if (Quit) break;
            }
        }
        else break;
    }
}

// Admin Log In

void AdminMode(AdminNode *AdminHead,StudentNode **StudentHead){
    printf("\nEnter your ID : ");
    long ID = CheckAdminID(AdminHead);
    printf("\nEnter your Password : ");
    if (CheckAdminPassword(AdminHead, ID)) ChooseAdminFeatures(AdminHead,StudentHead, ID);
}