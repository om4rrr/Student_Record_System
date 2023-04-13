#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Linked_List/Linked_List.h"
#include "../Validation/Validation.h"
#include "Program.h"

// We Calculate Student Total degree.

double CalcTotalDegree(StudentNode *ptr1){
    StudentNode *ptr = NULL;
    ptr = ptr1;
    return ptr->Data.Subject.DigitalCircuits.Degree + ptr->Data.Subject.ControlSystem.Degree
           + ptr->Data.Subject.Programming.Degree   + ptr->Data.Subject.Electronics.Degree
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


char* SetString(){
    char *str = (char *)calloc(1,sizeof(char));
    int len = 1;
    *str = '\0';
    char ch;
    ch = getchar();
    _putch('*');
    int cnt = 1;
    while(ch != '\n'){
        if(cnt == len)
        {
            str = (char *)realloc(str, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(str + cnt - 1) = ch;
        *(str + cnt) = '\0';
        cnt++;
        ch = getchar();
    }
    fflush(stdin);
    if(len == 1 ) return SetString();
    return str;
}

// Take Password from user encrypted

char* SetPassword(){
    char *str = (char *)calloc(1,sizeof(char));
    int len = 1;
    *str = '\0';
    char ch;
    ch =_getch();
    printf("*");
    fflush(stdout);
    int cnt = 1;
    while(ch != 13){
        if(cnt == len)
        {
            str = (char *)realloc(str, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(str + cnt - 1) = ch;
        *(str + cnt) = '\0';
        cnt++;
        ch = _getch();
        _putch('*');
    }
    fflush(stdin);
    if(len == 1 ) return SetPassword();
    return str;
}


// convert String to int

int StringToInt(char* StringNum){
    if(Strlen(StringNum) > 10) return -1;
    int num = 0;
    for(int i = 0; i < strlen(StringNum); i++)
    {
        if(!isdigit(StringNum[i])) return -1;
        num *= 10;
        num += StringNum[i] - '0';
    }
    return num;
}

// Print Supporting messages

void PrintSupportingMessage(char *str){
    if( !strcmp("A+",str) || !strcmp("A ",str) || !strcmp("A-",str) )
        printf("\nCongratulations !\nYour excellent results are a testament to your perseverance and determination,\n"
               "and I have no doubt that you have a bright future ahead of you.\n\n");
    else if(!strcmp("B+",str) || !strcmp("B ",str) || !strcmp("B-",str))
        printf("\nCongratulations !\nKeep working hard and believing in yourself, and success shall follow you everywhere you go.\n\n");
    else if(!strcmp("C+",str) || !strcmp("C ",str) || !strcmp("C-",str))
        printf("\nCongratulations !\nKeep going, you can do better.\n\n");
    else if(!strcmp("D+",str) || !strcmp("D ",str))
        printf("\nCongratulations !\nKeep going, you can do better.\n\n");
    else
        printf("failure is the opportunity to begin again more intelligently");

}

// Store Correct Password

char *StoreStudentCorrectPassword(StudentNode *ptr,long ID){

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

// Store New Password

void StoreStudentNewPassword(StudentNode *Head,long ID, char *Password){

    StudentNode *Current=NULL;
    Current = Head;
    while(Current != NULL) {
        if (ID == Current->Data.Student.ID) {
            Current->Data.Student.Password = Password;
            break;
        }
        Current = Current->Link;
    }
}

// Student Name

char *StudentName(StudentNode *ptr,long ID){

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
    return Name;
}

// Store Student National ID

char *StoreStudentNationalID(StudentNode *ptr,long ID){

    StudentNode *Current=NULL;
    Current = ptr;

    char *NationalID;
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

long StoreStudentPhoneNumber(StudentNode *ptr,long ID){

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

char *RandomString(char *str, int Num){

    char *str1 = NULL;
    str1 = (char *) malloc(MAX_STRING_LENGTH * sizeof (char));
    srand(time(NULL));
    char RandomCharacters[]={'a','b','d','6','g','t','L','k','r',
                             'p','@','#','^','W','&','A','R',
                             '1','2','3','4','5','6','0','o'};

    int Length = sizeof( RandomCharacters) / sizeof(char);
    for(int i = 0; i < Num; i++) {
        str1[i] = RandomCharacters[rand() % Length];
    }
    str1[Num] = 0;
    return str1;
}

/////////////////////////////////


// Store Correct Password

char *StoreAdminCorrectPassword(AdminNode *ptr,long ID){

    AdminNode *Current=NULL;
    Current = ptr;

    char *Password = NULL;
    Password = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
    while(Current != NULL) {
        if (ID == Current->Data.ID) {
            Password = Current->Data.Password;
            break;
        }
        Current = Current->Link;
    }
    return Password;
}

// Store New Password

void StoreAdminNewPassword(AdminNode *Head,long ID, char *Password){

    AdminNode *Current=NULL;
    Current = Head;
    while(Current != NULL) {
        if (ID == Current->Data.ID) {
            Current->Data.Password = Password;
            break;
        }
        Current = Current->Link;
    }
}

// Student Name

char *AdminName(AdminNode *ptr,long ID){

    AdminNode *Current=NULL;
    Current = ptr;

    char *Name = NULL;
    Name = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            Name = Current->Data.Name;
        }
        Current = Current->Link;
    }
    return Name;
}

// Store Student National ID

char *StoreAdminNationalID(AdminNode *ptr,long ID){

    AdminNode *Current=NULL;
    Current = ptr;

    char *NationalID;
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            NationalID = Current->Data.NationalID;
        }
        Current = Current->Link;
    }
    return NationalID;
}

// Store Student Phone Number

long StoreAdminPhoneNumber(AdminNode *ptr,long ID){

    AdminNode *Current=NULL;
    Current = ptr;

    long phoneNumber;
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            phoneNumber = Current->Data.PhoneNumber;
        }
        Current = Current->Link;
    }
    return phoneNumber;
}

// Store Student E-Mail

char *StoreAdminMail(AdminNode *ptr,long ID){

    AdminNode *Current=NULL;
    Current = ptr;

    char *studentMail = NULL;
    studentMail = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            studentMail = Current->Data.Mail;
        }
        Current = Current->Link;
    }
    return studentMail;
}


///////////

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}