#include "Validation.h"
#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Program/Program.h"
#include "../Linked_List/Linked_List.h"
#define MAX_STRING_LENGTH 50



// Validate Student ID Length

long ValidateIDLength(){
    int count;
    long ID, temp;
    do{
        count = 0;
        scanf("%ld",&ID);
        temp = ID;
        while (ID != 0) {
            count++;
            ID /= 10;
        }
    } while (count!=9 && printf("\nID must consist of 9 digits, Try again..\nEnter Student ID : "));
    return temp;
}


// Checking Existing ID


long CheckExistingID(StudentNode *head){
    struct StudentNode *ptr = NULL;
    bool flag;
    long ID;
    do{
        ptr = head;
        flag = true;
        ID = ValidateIDLength();
        while(ptr != NULL)
        {
            if(ID == ptr->Data.Student.ID){
                flag = false;
                break;
            }
            ptr = ptr->Link;
        }
    }while(!flag && printf("\nID already exist, Try again..\nEnter Student ID : "));

    return ID;
}


// Validate Student Name

char* ValidName(){

    bool check;
    int c;
    char* str = NULL;
    str = (char *) malloc(MAX_STRING_LENGTH*sizeof(char));
    do{
        check=true;
        c = 0;
        str = SetString();
        for(int i = 0; i < Strlen(str); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' ) continue;
            else if(str[i] == ' ') c++;
            else {check = false; break; }
        }
    }while(((c < 2)  || !check) && printf("\nInvalid Name, Please enter first, middle, and last name correctly\nEnter Student Name : "));
    return str;
}


// Checking Password Strength


char *CheckingPasswordStrength(){

    char *str = NULL;

    bool Lower   = false;
    bool Upper   = false;
    bool Digit   = false;
    bool Special = false;

    do{
        str = SetString();
        for(int i = 0; i < Strlen(str); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z') Lower = true;
            else if (str[i] >= 'A' && str[i] <= 'Z') Upper = true;
            else if (str[i] - '0' >= 0 && str[i] - '0' <= 9) Digit = true;
            else Special = true;
        }
    }while((Strlen(str) < 8 || !Lower || !Upper || !Digit || !Special) && printf("\nThe new password is weak, and will reduce the security of system\n"
                                                                                 "password must contain at least 8 characters,\none uppercase, one lowercase, one number and one special character.\n\nEnter Student Password : "));
    return str;
}


// Validate Student Age  18 --> 50

int ValidateStudentAge(){
    int Var = 0;
    do{
        scanf("%d",&Var);
    }while((Var < 18 || Var > 50) && printf("\nInvalid Age, Try again...\nEnter Student Age : "));
    return Var;

}


// Validate Student Gender

char* ValidateGender(){
    char* Gender = NULL;
    Gender = (char*)malloc(7*sizeof(char));
    do{
        Gender = SetString();
    } while(((strcmp("female",Gender) && strcmp("male",Gender))) && printf("\nNot valid, Please try again..\nEnter Student Gender : ") );
    return Gender;
}


//  Validate Subject Degree

int ValidateSubjectDegree(){
    int Var = 0;
    do{
        scanf("%d",&Var);
    }while( (Var < 0 || Var > 125) && printf("\nInvalid Degree, Try again...\nEnter Student Degree : ") );
    return Var;
}


// Validate choice to select Subject

int ChoiceSubjectValidate()
{
    int Choice;
    printf("\nselect the subject number to modify:\n1-Digital_Circuits\t2-Control_System\t3-Data_Structure\t"
           "4-Electronics\t5-Programming\t6-Measurements\nEnter the number : ");
    do{
        scanf("%d",&Choice);
    } while((Choice<1 || Choice>6) && printf("\nInvalid Choice! please try again..\nEnter the choice_number : "));
    return Choice;
}

// Validate choice to select modify another Subject

int ChoiceAnotherSubjectValidate()
{
    int choice;
    do{
        printf("\nwant to modify another Subject?     1-YES  2-NO\n");
        scanf("%d",&choice);
    } while((choice!=1 && choice!=2) && printf("Invalid Choice! please try again..\nEnter the choice_number : "));
    return choice;
}












