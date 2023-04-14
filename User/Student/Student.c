#include "Student.h"



// Print Student Information

void PrintStudentInfo(StudentNode *head, long ID){
    struct StudentNode *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        if(ptr->Data.Student.ID == ID){
            printf("\nName : %s\t\tID : %ld \n",ptr->Data.Student.Name,ptr->Data.Student.ID);
            printf("\nTotal Degree : %.2lf\tTotal Grade : %s     GPA : %.1lf \n",ptr->Data.TotalDegree,ptr->Data.TotalGrade,ptr->Data.GPA);
            printf("______________________________________________________\n");
            printf("\n    Subject      \t\tDegree\t\tGrade\n\n");
            printf(" Digital_Circuits\t\t  %d \t\t  %s\n",ptr->Data.Subject.DigitalCircuits.Degree,ptr->Data.Subject.DigitalCircuits.Rate);
            printf(" Control_System  \t\t  %d \t\t  %s\n",ptr->Data.Subject.ControlSystem.Degree  ,ptr->Data.Subject.ControlSystem.Rate);
            printf(" Data_Structure  \t\t  %d \t\t  %s\n",ptr->Data.Subject.DataStructure.Degree  ,ptr->Data.Subject.DataStructure.Rate);
            printf(" Electronics     \t\t  %d \t\t  %s\n",ptr->Data.Subject.Electronics.Degree    ,ptr->Data.Subject.Electronics.Rate);
            printf(" Programming     \t\t  %d \t\t  %s\n",ptr->Data.Subject.Programming.Degree    ,ptr->Data.Subject.Programming.Rate);
            printf(" Measurements    \t\t  %d \t\t  %s\n",ptr->Data.Subject.Measurements.Degree  ,ptr->Data.Subject.Measurements.Rate);
            printf("______________________________________________________\n");
            PrintSupportingMessage(ptr->Data.TotalGrade);
        }
        ptr = ptr->Link;
    }
}


// Edit Student Name

char *EditStudentName(StudentNode *Head,long ID){

    StudentNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            printf("\n  -----------<<<Edit Your Name>>>-----------  \n"
                          "Enter your Name : " );

            Current->Data.Student.Name = ValidName();
        }
        Current = Current->Link;
    }
    WriteToStudentFile(Head);
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
            printf("\n  -----------<<<Edit Your Password>>>-----------  \n"
                          "Enter your password : ");

            Current->Data.Student.Password = CheckingPasswordStrength();
        }
        Current = Current->Link;
    }
    WriteToStudentFile(Head);
    return "\n\"Password Edited Successfully\"\n\n";
}


// Choose Student Features


void  ChooseStudentFeatures(StudentNode *Head, long ID){
    printf("\n\t\t\t\tHello, %s\n\n", StudentName(Head, ID));
    while (1) {
        int choice = ChooseStudentFeaturesValidate();
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

