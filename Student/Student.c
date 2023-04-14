#include "Student.h"




// Edit Student Name

char *EditStudentName(StudentNode *Head,long ID){

    StudentNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            printf("\n-----------<Edit Your Name>-----------\n"
                          "Enter your Name : " );

            Current->Data.Student.Name = ValidName();
        }
        Current = Current->Link;
    }
    return "\n\"Name Edited Successfully\"\n\n";
}

// Edit Student password

char *EditStudentPassword(StudentNode *Head,long ID){

    StudentNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            printf("\n-----------<Edit Your Password>-----------\n"
                          "Enter your password : ");

            Current->Data.Student.Password = CheckingPasswordStrength();
        }
        Current = Current->Link;
    }
    return "\n\"Password Edited Successfully\"\n\n";
}

// Choose Student Features

void  ChooseStudentFeatures(StudentNode *Head, long ID){
    printf("\n\t\t\t\tHello, %s\n\n", StudentName(Head, ID));
    while (1) {
        int choice = ChooseStudentFeaturesValidate(Head, ID);
        bool EOP = false;
        switch (choice) {
            case 1:
                PrintStudentInfo(Head, ID); break;
            case 2:
                printf("%s",EditStudentPassword(Head, ID)); break;
            case 3:
                printf("%s",EditStudentName(Head, ID)); break;
            case 4:
                EOP = true;
                break;
        }
        if (EOP) break;
    }
}

// Student Log In

void StudentMode(StudentNode *Head)
{
    printf("\nEnter your ID : ");
    long ID = CheckStudentID(Head);
    if(ID > 0) {
        printf("\nEnter your Password : ");
        if (CheckStudentPassword(Head, ID)) ChooseStudentFeatures(Head, ID);
    }
}

