#include "Student.h"
#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Validation/Validation.h"
#include "../Program/Program.h"
#include "../Linked_List/Linked_List.h"
struct StudentNode *CurrentStd=NULL;

void StdIdCheck(StudentNode *head)
{
    long StdId;
   // char *StdPass;
      //char StdPass[50];
    //struct StudentNode *CurrentStd=NULL;
     CurrentStd=head;
    bool flag=false;
    printf("Student Log In\n");
    printf("Enter Your ID:");
    scanf("%ld",&StdId);
    while(CurrentStd != NULL)
    {
    if(StdId==CurrentStd->Data.Student.ID)
    {
        //StdPassCheck(CurrentStd);
        flag=true;
        break;
    }
    CurrentStd=CurrentStd->Link;
    }



     if(flag == false)
    {
        while(StdId != CurrentStd->Data.Student.ID)
        {
            printf("\nWrong ID ,Try Again");
            printf("Enter correct ID:");
            scanf("%ld",&StdId);
            while(CurrentStd != NULL) {
    if(StdId==CurrentStd->Data.Student.ID) break;
    CurrentStd=CurrentStd->Link;
            }
        }
        StdPassCheck(CurrentStd);
    }

 if(flag==true) StdPassCheck(CurrentStd);
}

void StdPassCheck(StudentNode *head)
{
    char *StdPass;
   printf("\nEnter Your Password:");
   StdPass=SetString();
   //printf("%s",CurrentStd->Data.Student.Password);
   if(/*strcmp(StdPass, CurrentStd->Data.Student.Password)==0*/0){
        StdMode(CurrentStd);
        printf("Hello");
                 }

    else
   {
       bool flag=false;
       for(int i=0;i<2;i++)
       {

       printf("\nWrong Password ,Try Again");
       printf("Enter correct Password:");
       StdPass=SetString();
   if(strcmp(StdPass, CurrentStd->Data.Student.Password)==0)
   {
       flag=true;
       break;
   }
       }
       if(flag==true) StdMode(CurrentStd);
       else
       {
           printf("No More Tries");
       }
}
}
//}
//
//
//   int i=0;
//   do
//   {
//    printf("Enter Your ID:");
//    scanf("%ld",&StdId);
//     printf("\nEnter Your Password:");
//     //scanf("%s",StdPass);
//     StdPass=SetString();
//     while(CurrentStd != NULL) {
//    if(StdId==CurrentStd->Data.Student.ID && (strcmp(StdPass, CurrentStd->Data.Student.Password)==0) )
//    //if(StdId==111444444 && StdPass=="Marwa44")
//    {
//        //StdMode(CurrentStd);
//        flag =true;
//        break;
//    }
//    CurrentStd=CurrentStd->Link;
//    }
//    if (flag==true) break;
//    i++;
//   }while(i<2);
//   if(flag==false)
//    {
//        printf("No More Tries");
//        //goto label; //main menu
//    }
//    else StdMode(CurrentStd);
//
//}
void StdMode(struct StudentNode *CurrentStd)
{
    int Choice;
    label2:
    printf("1. View your record.");
    printf("\n2. Edit your password.");
    printf("\n3. Edit your name");
    printf("\n4.Exit");
    printf("Enter Your choice");
    scanf("%d",&Choice);
    switch(Choice)
    {
        case 1: StdRec(CurrentStd); break;
        case 2: EditStdPass(CurrentStd); break;
        case 3: EditStdName(CurrentStd); break;

        default : printf("\nInvalid Choice"); break;

    }
}
void StdRec(struct StudentNode *CurrentStd)
{

     printf("\nName : %s\t\tID : %ld \n",CurrentStd->Data.Student.Name,CurrentStd->Data.Student.ID);
            printf("\nTotal Degree : %.2lf\tTotal Grade : %s     GPA : %.1lf \n",CurrentStd->Data.TotalDegree,CurrentStd->Data.TotalGrade,CurrentStd->Data.GPA);
            printf("______________________________________________________\n");
            printf("\n    Subject      \t\tDegree\t\tGrade\n\n");
            printf(" Digital_Circuits\t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.DigitalCircuits.Degree,CurrentStd->Data.Subject.DigitalCircuits.Rate);
            printf(" Control_System  \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.ControlSystem.Degree  ,CurrentStd->Data.Subject.ControlSystem.Rate);
            printf(" Data_Structure  \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.Programming.Degree    ,CurrentStd->Data.Subject.Programming.Rate);
            printf(" Electronics     \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.Programming.Degree    ,CurrentStd->Data.Subject.Electronics.Rate);
            printf(" Programming     \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.DataStructure.Degree  ,CurrentStd->Data.Subject.DataStructure.Rate);
            printf(" Measurements     \t\t  %d \t\t  %s\n",CurrentStd->Data.Subject.Measurements.Degree    ,CurrentStd->Data.Subject.Measurements.Rate);
            printf("______________________________________________________\n");
            PrintSupportingMessage(CurrentStd->Data.TotalGrade);
}

void EditStdPass(struct StudentNode *CurrentStd)
{
    char *CheckCurrentPass , *NewStdPass, *NewStdPassConfirm;
    bool flag=false;
    for(int i=0;i<3;i++)
        {
    printf("Enter Your Current Password");
    CheckCurrentPass=SetString();
    if(strcmp(*CheckCurrentPass,CurrentStd->Data.Student.Password)==0)
    {
        printf("Enter Your New Password:");
        NewStdPass=SetString();
        CheckingPasswordStrength(NewStdPass);
         bool flag2=false;
        for(int i=0;i<3;i++)
        {
        printf("Confirm Your New Password:");
        NewStdPassConfirm=SetString();
        if(strcmp(*NewStdPassConfirm,*NewStdPass)==0)
        {
            printf("Password Has Changed Successfully");
            flag=true;
            break;
        }
        else{
            printf("Not Identical,Try Again");
        }
        if(flag2==false)
        {
            printf("No More Tries");
            //goto label2;

        }

        }

        flag=true;

    }
    else
    {
        printf("Wrong Password ,Try Again");
    }
    }
    if(flag == false)
    {
        printf("No More Tries");
        //goto label2; //student menu
    }
    if(flag==true)
    {
         CurrentStd->Data.Student.Name= NewStdPass;

    }

}

void EditStdName(struct StudentNode *CurrentStd)
{
  printf("Edit Your  Name");
  CurrentStd->Data.Student.Name=SetString();
  printf(" Name Edited Successfully");

}
