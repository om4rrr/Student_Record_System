#include "Student.h"
#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Validation/Validation.h"
#include "../Program/Program.h"
#include "../Linked_List/Linked_List.h"



long CheckStudentID(StudentNode *Head){
   StudentNode *Current=NULL;

   bool flag;
   long ID;
   int cnt = 0;
    do{
        if(cnt >= 9) printf("Sorry, You entered wrong ID many times") ;
        Current = Head;
        flag = true;
        ID = ValidateIDLength();
        while(Current != NULL)
        {
            if(ID == Head->Data.Student.ID){
                flag = false;
                break;
            }
            Current = Current->Link;
        }
        cnt++;
    }while(flag && printf("\nWrong ID, Try again..\nEnter your ID : "));

    return ID;
}



bool CheckStudentPassword(StudentNode *Head, long ID){

    char *CorrectPassword = NULL, *Password = NULL;
    Password = (char *) malloc(MAX_STRING_LENGTH*sizeof(short ));
    CorrectPassword = StoreCorrectPassword(Head,ID);
    int cnt = 0, var = 0; bool f = false;

    do{
    if(f) scanf("%d",&var);
    if(var == 1)
    {
        if(CheckStudentData(Head, ID))
        {
            char *str = NULL;
            str = CheckingRandomPasswordStrength();
            printf("\nYour New Password is \"%s\"",str);
            StoreNewPassword(Head,ID,str);
            return true;
        }else{
            printf("Sorry, You entered wrong Information three times, Try later...");
            return false;
        }
    }
    else
    {
        if(cnt > 2) {printf("Sorry, You entered wrong Password three times, Try later..."); return false;}
        if(f)printf("\nEnter your password : ");
        Password = SetString();
        cnt++;
    }
    }while(strcmp(CorrectPassword,Password) && printf("\nWrong Password, \"if you forget your"
                                                "password... Enter -1- , if not and want to ""try again... Enter -2-\"\nEnter Number : ") && (f = true));
    return true;
}

//void StdMode(struct StudentNode *CurrentStd)
//{
//    int Choice;
//    label2:
//    printf("1. View your record.");
//    printf("\n2. Edit your password.");
//    printf("\n3. Edit your name");
//    printf("\n4. Exit");
//    printf("Enter Your choice");
//    scanf("%d",&Choice);
//    switch(Choice)
//    {
//        case 1: StdRec(CurrentStd); break;
//        case 2: EditStdPass(CurrentStd); break;
//        case 3: EditStdName(CurrentStd); break;
//
//        default : printf("\nInvalid Choice"); break;
//    }
//}
//
//
//void StdRec(struct StudentNode *CurrentStd)
//{
//
//    printf("\nName : %s\t\tID : %ld \n",CurrentStd->Data.Student.Name,CurrentStd->Data.Student.ID);
//    printf("\nTotal Degree : %.2lf\tTotal Grade : %s     GPA : %.1lf \n",CurrentStd->Data.TotalDegree,CurrentStd->Data.TotalGrade,CurrentStd->Data.GPA);
//    printf("______________________________________________________\n");
//    printf("\n    Subject      \t\tDegree\t\tGrade\n\n");
//    printf(" Digital_Circuits\t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.DigitalCircuits.Degree,CurrentStd->Data.Subject.DigitalCircuits.Rate);
//    printf(" Control_System  \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.ControlSystem.Degree  ,CurrentStd->Data.Subject.ControlSystem.Rate);
//    printf(" Data_Structure  \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.Programming.Degree    ,CurrentStd->Data.Subject.Programming.Rate);
//    printf(" Electronics     \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.Programming.Degree    ,CurrentStd->Data.Subject.Electronics.Rate);
//    printf(" Programming     \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.DataStructure.Degree  ,CurrentStd->Data.Subject.DataStructure.Rate);
//    printf(" Measurements    \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.Measurements.Degree    ,CurrentStd->Data.Subject.Measurements.Rate);
//    printf("______________________________________________________\n");
//    PrintSupportingMessage(CurrentStd->Data.TotalGrade);
//}

//void EditStdPass(struct StudentNode *CurrentStd)
//{
//    char *CheckCurrentPass , *NewStdPass, *NewStdPassConfirm;
//    bool flag=false;
//    for(int i=0;i<3;i++)
//    {
//        printf("Enter Your Current Password");
//        CheckCurrentPass=SetString();
//        if(strcmp(*CheckCurrentPass,CurrentStd->Data.Student.Password)==0)
//        {
//            printf("Enter Your New Password:");
//            NewStdPass=SetString();
//            CheckingPasswordStrength(NewStdPass);
//            bool flag2=false;
//            for(int i=0;i<3;i++)
//            {
//                printf("Confirm Your New Password:");
//                NewStdPassConfirm=SetString();
//                if(strcmp(*NewStdPassConfirm,*NewStdPass)==0)
//                {
//                    printf("Password Has Changed Successfully");
//                    flag=true;
//                    break;
//                }
//                else{
//                    printf("Not Identical,Try Again");
//                }
//                if(flag2==false)
//                {
//                    printf("No More Tries");
//                    //goto label2;
//
//                }
//
//            }
//
//            flag=true;
//
//        }
//        else
//        {
//            printf("Wrong Password ,Try Again");
//        }
//    }
//    if(flag == false)
//    {
//        printf("No More Tries");
//        //goto label2; //student menu
//    }
//    if(flag==true)
//    {
//        CurrentStd->Data.Student.Name= NewStdPass;
//
//    }
//
//}
//
//void EditStdName(struct StudentNode *CurrentStd)
//{
//    printf("Edit Your  Name");
//    CurrentStd->Data.Student.Name=SetString();
//    printf(" Name Edited Successfully");
//
//}
