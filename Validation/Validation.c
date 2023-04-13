#include "Validation.h"



// Validate Student ID Length

long ValidateIDLength(){
    int count;
    long ID, temp;
    char *tmp;
    do{
        count = 0;
        tmp = SetString();
        ID = StringToInt(tmp);
        temp = ID;
        while (ID != 0) {
            count++;
            ID /= 10;
        }
    } while (count!=9 && printf("\nID must consist of 9 digits, Try again..\nEnter The ID : "));
    return temp;
}


// Validate Student National ID Length

char *ValidateNationalIDLength(){
    char * NationalID;
    do{
        NationalID = SetString();

    } while (Strlen(NationalID)!=15 && printf("\nID must consist of 14 digits, Try again..\nEnter Student National ID : "));
    return NationalID;
}

// Validate Student Phone number Length

long ValidatePhoneNumberLength(){
    int count;
    long PhoneNumber, temp;
    char *tmp;
    do{
        count = 0;
        tmp = SetString();
        PhoneNumber = StringToInt(tmp);
        temp = PhoneNumber;
        while (PhoneNumber != 0) {
            count++;
            PhoneNumber /= 10;
        }
    } while (count!=10 && printf("\nPhone Number must consist of 11 digits, Try again..\n"
                                        "Enter Student Phone Number : +20"));
    return temp;
}

// Check Phone Number

long CheckPhoneNumber(){

    long PhoneNumber;
    int var1,var2;
    do{
        PhoneNumber = ValidatePhoneNumberLength();
        var1 = PhoneNumber%(long)1e10;
        var2 = PhoneNumber%(long)1e19;
    } while ((var1 != 1 &&(var2 != 0 || var2 != 1 ||  var2 != 2 ||  var2 != 5))
             && printf("\nWrong Phone Number, Try again..\nEnter Student Phone Number : +20"));

}



// check E-mail validation

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

bool IsValid(char *email)
{
    if (!isChar(email[0]))  return 0;

    int At = -1, Dot = -1;

    for (int i = 0;i < Strlen(email); i++) {

        if (email[i] == '@')  At = i;
        else if (email[i] == '.') Dot = i;
    }
    if (At == -1 || Dot == -1) return 0;

    if (At > Dot) return 0;

    return !(Dot >= (Strlen(email) - 1));
}

char *CheckMailValidation(){
    char *Mail = NULL;
    Mail = (char*) malloc(MAX_STRING_LENGTH*sizeof(char));
    do{
        Mail = SetString();
    } while (!IsValid(Mail) && printf("Invalid E-mail, Try again...\nEnter Student E-mail : "));
    return Mail;
}

// Checking Existing ID


long CheckExistingID(StudentNode *head){
    StudentNode *ptr = NULL;
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
    }while(((c < 2)  || !check) && printf("\nInvalid Name, Please enter first, middle, and last name correctly\nEnter The Name : "));
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
                                                                                 "password must contain at least 8 characters,\none uppercase, one lowercase, one"
                                                                                 "number and one special character.\n\nEnter The Password : "));
    return str;
}


// Checking Random Password Strength

char *CheckingRandomPasswordStrength(){

    char *str = NULL;

    bool Lower   = false;
    bool Upper   = false;
    bool Digit   = false;
    bool Special = false;

    do{
        str = RandomString(str,10);
        for(int i = 0; i < Strlen(str); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z') Lower = true;
            else if (str[i] >= 'A' && str[i] <= 'Z') Upper = true;
            else if (str[i] - '0' >= 0 && str[i] - '0' <= 9) Digit = true;
            else Special = true;
        }
    }while(!Lower || !Upper || !Digit || !Special);
    return str;
}

// Validate Student Age  18 --> 50

int ValidateStudentAge(){
    int Var = 0;
    char *temp;
    do{
        temp = SetString();
        Var = StringToInt(temp);
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
    char *temp;
    do{
        temp = SetString();
        Var = StringToInt(temp);
    }while( (Var <= 0 || Var > 125) && printf("\nInvalid Degree, Try again...\nEnter Student Degree : ") );
    return Var;
}


// Validate choice to select Subject

int ChoiceSubjectValidate()
{
    int Choice;
    char *temp;
    printf("\nSelect the subject number to modify:\n1-Digital_Circuits\t2-Control_System\t3-Data_Structure\t"
           "4-Electronics\t5-Programming\t6-Measurements\nEnter the number : ");
    do{
        temp = SetString();
        Choice = StringToInt(temp);
    } while((Choice<1 || Choice>6) && printf("\nInvalid Choice! please try again..\nEnter the choice_number : "));
    return Choice;
}

// Validate choice to select modify another Subject

int ChoiceAnotherSubjectValidate()
{
    int choice;
    char *temp;
    do{
        printf("\nwant to modify another Subject?     1-YES  2-NO\n");
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice!=1 && choice!=2) && printf("Invalid Choice! please try again..\nEnter the choice number : "));
    return choice;
}




// Validate choice to select UserMode

int ChooseModeValidate(){
    int choice;
    char *temp;
    printf("\n-----------------------------------Welcome to Student_Record_System !-----------------------------------\n\n");
    do{
        printf("Choose your mode..."
               "\n1. Student Mode\t\t\t2. Admin Mode"
               "\t\t\t3. Quit\nYour Choice Number : ");
        fflush(stdout);
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice!=1 && choice!=2 && choice!=3) && printf("Invalid Choice! please try again..\n"));
    return choice;
}


// Validate choice to select Student Features

int ChooseStudentFeaturesValidate(StudentNode *Head, long ID){
    int choice;
    char *temp;
    do{
        printf("Enter appropriate number to perform following tasks "
               "\n1. View your record\t\t2. Edit your password."
               "\t\t3. Edit your name\t\t4. Quit\nEnter Choice Number : ");
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice < 1 || choice > 4) && printf("Invalid Choice! please try again..\n"));
    return choice;
}



///////////////////////////////////////////////////////////////////////////////////////////////////


// Check Student Data to chang Password

bool CheckStudentData(StudentNode *Head,long ID){

    printf("\n\"You Should enter some information to be able to change your password\"\n");


    // Take National ID

    char *CorrectNationalID = NULL,*NationalID  = NULL;
    CorrectNationalID = StoreStudentNationalID(Head, ID);
    int cnt = 0;
    printf("\nEnter your National_ID : ");
    do{
        NationalID = SetString();
        cnt++;
    }while(strcmp(NationalID,CorrectNationalID) && cnt < 3 && printf("\nWrong National ID, Try again...\nEnter your National_ID : "));
    if(cnt >= 3) { return false;}
    // Take Phone Number

    long CorrectPhoneNumber,PhoneNumber;
    CorrectPhoneNumber = StoreStudentPhoneNumber(Head,ID);
    char *temp;
    cnt = 0;
    printf("\nEnter your Phone Number : ");
    do{
        if(cnt > 2) {printf("Sorry, You entered wrong Phone Number three times"); return false;}
        temp = SetString();
        PhoneNumber = StringToInt(temp);
        cnt++;
    }while(CorrectPhoneNumber != PhoneNumber && printf("\nWrong Phone Number, Try again...\nEnter your Phone Number : "));


    // Take E-mail

    char *CorrectMail = NULL,*Mail = NULL;
    CorrectMail = StoreStudentMail(Head, ID);

    cnt = 0;
    printf("\nEnter your E-mail : ");
    do{
        if(cnt > 2) {printf("Sorry, You entered wrong E-mail three times"); return false;}
        Mail = SetString();
        cnt++;
    }while(strcmp(Mail,CorrectMail) && printf("\nWrong E-mail, Try again...\nEnter your E-mail : "));

    return true;
}


// Check Student ID to log in

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
            if(ID == Current->Data.Student.ID){
                flag = false;
                break;
            }
            Current = Current->Link;
        }
        cnt++;
    }while(flag && printf("\nWrong ID, Try again..\nEnter your ID : "));

    return ID;
}


// Check Student Password to log in


bool CheckStudentPassword(StudentNode *Head, long ID){
    char *CorrectPassword = NULL, *Password = NULL;
    CorrectPassword = StoreStudentCorrectPassword(Head,ID);
    int cnt = 0, var = 0; bool f = false;
    do{
        if(f) scanf("%d",&var);
        if(var == 1)
        {
            if(CheckStudentData(Head, ID))
            {
                char *str = NULL;
                str = CheckingRandomPasswordStrength(); // calling CheckingRandomPasswordStrength --> calling Generating RandomPassword
                printf("\nYour New Password is \"%s\"",str);
                StoreStudentNewPassword(Head,ID,str);
                return true; // go to next background (Student's features)
            }else{
                printf("Sorry, You entered wrong Information three times, Try later...");
                return false; // return to previous background (Admin or Student)
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


////////////////////////////////////////////////////////////////////////////////////////////



// Check Student Data to chang Password

bool CheckAdminData(AdminNode *Head,long ID){

    printf("\n\"You Should enter some information to be able to change your password\"\n");


    // Take National ID

    char *CorrectNationalID = NULL,*NationalID  = NULL;
    CorrectNationalID = StoreAdminNationalID(Head, ID);
    int cnt = 0;
    printf("\nEnter your National_ID : ");
    do{
        NationalID = SetString();
        cnt++;
    }while(strcmp(NationalID,CorrectNationalID) && cnt < 3 && printf("\nWrong National ID, Try again...\nEnter your National_ID : "));
    if(cnt >= 3) { return false;}
    // Take Phone Number

    long CorrectPhoneNumber,PhoneNumber;
    CorrectPhoneNumber = StoreAdminPhoneNumber(Head,ID);
    char *temp;
    cnt = 0;
    printf("\nEnter your Phone Number : ");
    do{
        if(cnt > 2) {printf("Sorry, You entered wrong Phone Number three times"); return false;}
        temp = SetString();
        PhoneNumber = StringToInt(temp);
        cnt++;
    }while(CorrectPhoneNumber != PhoneNumber && printf("\nWrong Phone Number, Try again...\nEnter your Phone Number : "));


    // Take E-mail

    char *CorrectMail = NULL,*Mail = NULL;
    CorrectMail = StoreAdminMail(Head, ID);

    cnt = 0;
    printf("\nEnter your E-mail : ");
    do{
        if(cnt > 2) {printf("Sorry, You entered wrong E-mail three times"); return false;}
        Mail = SetString();
        cnt++;
    }while(strcmp(Mail,CorrectMail) && printf("\nWrong E-mail, Try again...\nEnter your E-mail : "));

    return true;
}



// Check Admin ID to log in

long CheckAdminID(AdminNode *Head){
    AdminNode *Current=NULL;

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
            if(ID == Current->Data.ID){
                flag = false;
                break;
            }
            Current = Current->Link;
        }
        cnt++;
    }while(flag && printf("\nWrong ID, Try again..\nEnter your ID : "));

    return ID;
}

// Check Admin Password to log in

bool CheckAdminPassword(AdminNode *Head, long ID){
    char *CorrectPassword = NULL, *Password = NULL;
    CorrectPassword = StoreAdminCorrectPassword(Head,ID);
    int cnt = 0, var = 0; bool f = false;
    do{
        if(f) scanf("%d",&var);
        if(var == 1)
        {
            if(CheckAdminData(Head, ID))
            {
                char *str = NULL;
                str = CheckingRandomPasswordStrength(); // calling CheckingRandomPasswordStrength --> calling Generating RandomPassword
                printf("\nYour New Password is \"%s\"",str);
                StoreAdminNewPassword(Head,ID,str);
                return true; // go to next background (Student's features)
            }else{
                printf("Sorry, You entered wrong Information three times, Try later...");
                return false; // return to previous background (Admin or Student)
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

// Validate choice to select Student Affairs for Admin

int StudentAffairsValidate(){
    int choice;
    char *temp;
    do{
        printf("Enter Appropriate number to perform following tasks..."
               "\n1. Add New Student\t\t2. Remove Student.\t\t3. View Student Record\n\n"
               "\t\t4. View All Records\t\t5. Edit Student Grade\t\t6. Quit\n\nYour Choice Number : ");
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice < 1 || choice > 6) && printf("Invalid Choice! please try again..\n"));
    return choice;
}

int EditAdminInfoValidate(){
    int choice;
    char *temp;
    do{
        printf("Enter Appropriate number to perform following tasks..."
               "\n1. Edit your name\t\t2. Edit your password.\t\t3. Quit\n\nYour Choice Number : ");
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice < 1 || choice > 3) && printf("Invalid Choice! please try again..\n"));
    return choice;

}