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
            printf("\n\n  ------------<<Edit Your Name>>------------  \n");
            char *name;
            do{
                printf("Enter your Name : ");
                name = ValidName();
            }while(!strcmp(name,Current->Data.Student.Name) && printf("\n\n\"This name is the previous name\", try again...\n"));
            Current->Data.Student.Name = name;
            break;
        }
        Current = Current->Link;
    }
    WriteToStudentFile(Head);
    return "\n\n\"Name Edited Successfully\"\n\n";
}


// Edit Student password


char *EditStudentPassword(StudentNode *Head,long ID){

    StudentNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            printf("\n\n  ------------<<Edit Your Password>>------------  \n");
            char *password;
            do{
                printf("Enter your Password : ");
                password = SetPassword();
            }while(!strcmp(password,Current->Data.Student.Password) && printf("\n\n\"This name is the previous password\", try again...\n"));
            Current->Data.Student.Password = password;
            break;
        }
        Current = Current->Link;
    }
    WriteToStudentFile(Head);
    return "\n\n\"Password Edited Successfully\"\n\n";
}


// Choose Student Features


void  ChooseStudentFeatures(StudentNode *Head, long ID){
    int n = 30;
    system("cls");
    printf("\n\n\t\t\t\t*-----------------------------------------------<<<<Hello, "
                  "%s>>>>-----------------------------------------------*\n\n", StudentName(Head, ID),n,' ');
    while (1) {
        int choice = ChooseStudentFeaturesValidate();
        bool EOP = false;
        switch (choice) {
            case 1:
                system("cls");
                PrintStudentInfo(Head, ID); break;
            case 2:
                system("cls");
                printf("%s",EditStudentPassword(Head, ID)); break;
            case 3:
                system("cls");
                printf("%s",EditStudentName(Head, ID)); break;
            case 4:
                system("cls");
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

