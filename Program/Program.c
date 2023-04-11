#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Linked_List/Linked_List.h"
#include "Program.h"

// We Calculate Student Total degree.

double CalcTotalDegree(StudentNode *head){
    StudentNode *ptr = NULL;
    ptr = head;
    return ptr->Data.Subject.DigitalCircuits.Degree+ ptr->Data.Subject.ControlSystem.Degree
           + ptr->Data.Subject.Programming.Degree   + ptr->Data.Subject.Programming.Degree
           + ptr->Data.Subject.DataStructure.Degree + ptr->Data.Subject.Measurements.Degree;

}

// We Calculate Student Total Grade.

char *CalcTotalGrade(double TotalDegree){
    if(TotalDegree >= 727.5 &&  TotalDegree <= 750)         return "A+";
    else if (TotalDegree >= 697.5 &&  TotalDegree < 727.5 ) return "A ";
    else if (TotalDegree >= 675   &&  TotalDegree <= 697.5) return "A-";
    else if (TotalDegree >= 652.5 &&  TotalDegree <= 675  ) return "B+";
    else if (TotalDegree >= 622.5 &&  TotalDegree <= 652.5) return "B ";
    else if (TotalDegree >= 600   &&  TotalDegree <= 622.5) return "B-";
    else if (TotalDegree >= 577.5 &&  TotalDegree <= 600  ) return "C+";
    else if (TotalDegree >= 547.5 &&  TotalDegree <= 755.5) return "C ";
    else if (TotalDegree >= 525   &&  TotalDegree <= 547.5) return "C-";
    else if (TotalDegree >= 502.5 &&  TotalDegree <= 525  ) return "D+";
    else if (TotalDegree >= 487.5 &&  TotalDegree <= 502.5) return "D ";
    else return "F ";
}

// We Calculate Student Total GPA.

double CalcGPA(double TotalDegree){
    if(TotalDegree >= 697.5 &&  TotalDegree <= 750)         return 4.0;
    else if (TotalDegree >= 675   &&  TotalDegree <= 697.5) return 3.7;
    else if (TotalDegree >= 652.5 &&  TotalDegree <= 675  ) return 3.3;
    else if (TotalDegree >= 622.5 &&  TotalDegree <= 652.5) return 3.0;
    else if (TotalDegree >= 600   &&  TotalDegree <= 622.5) return 2.7;
    else if (TotalDegree >= 577.5 &&  TotalDegree <= 600  ) return 2.3;
    else if (TotalDegree >= 547.5 &&  TotalDegree <= 755.5) return 2.0;
    else if (TotalDegree >= 525   &&  TotalDegree <= 547.5) return 1.7;
    else if (TotalDegree >= 502.5 &&  TotalDegree <= 525  ) return 1.3;
    else if (TotalDegree >= 487.5 &&  TotalDegree <= 502.5) return 1.0;
    else return 0;

}

// Calculate Subject Grade


char *CalcSubjectGrade(double TotalDegree){
    if(TotalDegree >= 121.5 &&  TotalDegree <= 125) return "A+";
    else if (TotalDegree >= 116.25 &&  TotalDegree < 121.5  ) return "A ";
    else if (TotalDegree >= 112.5  &&  TotalDegree <= 116.25) return "A-";
    else if (TotalDegree >= 108.75 &&  TotalDegree <= 112.5 ) return "B+";
    else if (TotalDegree >= 103.75 &&  TotalDegree <= 108.75) return "B ";
    else if (TotalDegree >= 100    &&  TotalDegree <= 103.75) return "B-";
    else if (TotalDegree >= 96.25  &&  TotalDegree <= 100   ) return "C+";
    else if (TotalDegree >= 912.5  &&  TotalDegree <= 96.25 ) return "C ";
    else if (TotalDegree >= 87.5   &&  TotalDegree <= 91.25 ) return "C-";
    else if (TotalDegree >= 83.75  &&  TotalDegree <= 87.5  ) return "D+";
    else if (TotalDegree >= 81.25  &&  TotalDegree <= 83.75 ) return "D ";
    else return "F ";

}


// Calculate String length

size_t Strlen(const char *s){
    const char *p = s;
    while(*s)
        s++;
    return s-p;
}

// Take string from user

char *SetString(){
    char *str = NULL, ch;
    int i = 0;
    str = (char*)malloc(2*sizeof(char));

    while(ch = getc(stdin),ch !='\n')
    {
        str[i] = ch;
        str[i+1] = '\0';
        i++;
        str = (char *)realloc(str,i*sizeof(short));
    }
    return str;
}


// Print Supporting messages

void PrintSupportingMessage(char *str){
    if( !strcmp("A+",str) || !strcmp("A ",str) || !strcmp("A-",str) )
        printf("\nCongratulations !\nYour excellent results are a testament to your perseverance and determination,\n"
               "and I have no doubt that you have a bright future ahead of you.");
    else if(!strcmp("B+",str) || !strcmp("B ",str) || !strcmp("B-",str))
        printf("\nCongratulations !\nKeep working hard and believing in yourself, and success shall follow you everywhere you go.\n");
    else if(!strcmp("C+",str) || !strcmp("C ",str) || !strcmp("C-",str))
        printf("\nCongratulations !\nKeep going, you can do better.\n");
    else if(!strcmp("D+",str) || !strcmp("D ",str))
        printf("\nCongratulations !\nKeep going, you can do better.\n");
    else
        printf("failure is the opportunity to begin again more intelligently");

}

// Store Correct Password

char *StoreCorrectPassword(StudentNode *ptr,long ID){

    StudentNode *Current=NULL;
    Current = ptr;

    char *Password = NULL;
    Password = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));

    while(Current != NULL) {
        if (ID == Current->Data.Student.ID) {
            Password = Current->Data.Student.Password;
            break;
        }
        Current = Current->Link;
    }
    return Password;
}

// Store Student Name

char *StoreStudentName(StudentNode *ptr,long ID){

    StudentNode *Current=NULL;
    Current = ptr;

    char *Name = NULL;
    Name = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            Name = Current->Data.Student.Name;
        }
        Current = Current->Link;
    }
}

// Store Student National ID

long StoreNationalID(StudentNode *ptr,long ID){

    StudentNode *Current=NULL;
    Current = ptr;

    long NationalID;
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            NationalID = Current->Data.Student.NationalID;
        }
        Current = Current->Link;
    }
    return NationalID;
}

// Store Student Phone Number

long StorePhoneNumber(StudentNode *ptr,long ID){

    StudentNode *Current=NULL;
    Current = ptr;

    long phoneNumber;
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            phoneNumber = Current->Data.Student.PhoneNumber;
        }
        Current = Current->Link;
    }
    return phoneNumber;
}

// Store Student E-Mail

char *StoreStudentMail(StudentNode *ptr,long ID){

    StudentNode *Current=NULL;
    Current = ptr;

    char *studentMail = NULL;
    studentMail = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
    while(Current != NULL)
    {
        if(ID == Current->Data.Student.ID)
        {
            studentMail = Current->Data.Student.Mail;
        }
        Current = Current->Link;
    }
    return studentMail;
}

// Generate Random string

void RandomString(char *str, int Num){

    srand(time(NULL));
    char RandomCharacters[]={'a','b','d','6','g','t','L',
                             'p','@','#','^','W','&','A',
                             '1','2','3','4','5','6','0'};

    int Length = sizeof( RandomCharacters) / sizeof(char);
    for(int i = 0; i < Num; i++)
    {
        str[i] =  RandomCharacters[rand() % Length] ;
    }
    str[Num] = '\0';
}

/////////

bool CheckStudentData(StudentNode *ptr,long ID){
    printf("\n\"You Should enter some information to be able to change your password\"\n");
    // Store Student National ID

    long NationalID;
    NationalID = StoreNationalID(ptr, ID);

    // Store Student Phone Number

    long PhoneNumber;
    PhoneNumber = StoreNationalID(ptr, ID);

    // Store Student E-mail

    char *StudentMail = NULL;
    StudentMail = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
    StudentMail = StoreStudentMail(ptr, ID);

    // Take National ID

    int cnt = 0;
    long NationalID1;
    printf("\nEnter your National_ID : ");
    do{
        if(cnt > 2) {printf("Sorry, You entered wrong National ID three times"); return false;}
        scanf("%ld",NationalID1);
        cnt++;
    }while(NationalID1 != NationalID && printf("\nWrong National ID, Try again...\nEnter your National_ID : "));

    // Take Phone Number

    long PhoneNumber1; cnt = 0;
    printf("\nEnter your Phone Number : ");
    do{
        if(cnt > 2) {printf("Sorry, You entered wrong Phone Number three times"); return false;}
        scanf("%ld",PhoneNumber1);
        cnt++;
    }while(NationalID1 != NationalID && cnt < 4&& printf("\nWrong National ID, Try again...\nEnter your Phone Number : "));

    // Take E-mail

    char *StudentMail1 = NULL; cnt = 0;
    StudentMail1 = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
    printf("\nEnter your E-mail : ");
    do{
        if(cnt > 2) {printf("Sorry, You entered wrong E-mail three times"); return false;}
        StudentMail1 = SetString();
        cnt++;
    }while(NationalID1 != NationalID && cnt < 4&& printf("\nWrong National ID, Try again...\nEnter your E-mail : "));

    return true;
}


