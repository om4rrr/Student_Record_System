
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
    } while (count != 9 && printf("\nID must consist of 9 digits, Try again..\n\nEnter ID : "));
    return temp;
}


// Validate Student National ID Length


char *ValidateNationalIDLength(){
    char * NationalID;
    do{
        NationalID = SetString();

    } while (Strlen(NationalID)  != 14 && printf("\nNational ID must consist of 14 digits, Try again..\n\nEnter National ID : "));
    return NationalID;
}


// Validate Student Phone number Length


char *ValidatePhoneNumberLength(){
    char *temp;
    do{
        temp = SetString();
    } while (Strlen(temp) != 10 && printf("\nPhone Number must consist of 11 digits, Try again..\n\nEnter Phone Number : +20"));
    return temp;
}


// Check Phone Number


long CheckPhoneNumber(){
    char *temp;
    do{
        temp = ValidatePhoneNumberLength();
    } while ((temp[0] != '1' && (temp[1] != '0' && temp[1] != '1' &&  temp[1] != '2' &&  temp[1] != '5'))
             && printf("\nWrong Phone Number, Try again..\n\nEnter Phone Number : +20"));
    return StringToInt(temp);
}


// check E-mail validation


bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
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

    return Dot < (Strlen(email) - 1);
}

char *CheckMailValidation(){
    char *Mail = NULL;
    do{
        Mail = SetString();
    } while (!IsValid(Mail) && printf("Invalid E-mail, Try again...\n\nEnter E-mail : "));
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
    }while(!flag && printf("\nID already exist, Try again..\n\nEnter ID : "));

    return ID;
}


// Validate Student Name


char* ValidName(){

    bool check;
    int c;
    char* str = NULL;
    do{
        check = true;
        c = 0;
        str = SetString();
        for(int i = 0; i < Strlen(str); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' ) continue;
            else if(str[i] == ' ') c++;
            else {check = false; break; }
        }
    }while(((c < 2)  || !check) && printf("\nInvalid Name, Please enter first, middle, and last name correctly\n\nEnter Name : "));
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
        str = SetPassword();
        for(int i = 0; i < Strlen(str); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z') Lower = true;
            else if (str[i] >= 'A' && str[i] <= 'Z') Upper = true;
            else if (str[i] - '0' >= 0 && str[i] - '0' <= 9) Digit = true;
            else Special = true;
        }
    }while((Strlen(str) < 8 || !Lower || !Upper || !Digit || !Special) && printf("\n\n\"The new password is weak, and will reduce the security of system\n"
                                                                                 "password must contain at least 8 characters,\none uppercase, one lowercase, one"
                                                                                 "number and one special character.\"\n\nEnter Password : "));
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
    int Var;
    char *temp;
    do{
        temp = SetString();
        Var = StringToInt(temp);
    }while((Var < 18 || Var > 50) && printf("\nInvalid Age, Try again...\n\nEnter Age : "));
    return Var;

}


// Validate Student Gender


char* ValidateGender(){
    char* Gender = NULL;
    do{
        Gender = SetString();
    } while(((strcmp("female",Gender) && strcmp("male",Gender) && (strcmp("Female",Gender) && strcmp("Male",Gender))))
            && printf("\nNot valid, Please try again..\n\nEnter Gender : ") );
    return Gender;
}


//  Validate Subject Degree


int ValidateSubjectDegree(){
    int Var;
    char *temp;
    do{
        temp = SetString();
        Var = StringToInt(temp);
    }while( (Var < 0 || Var > 125) && printf("\nInvalid Degree, Try again...\n\nEnter Student Degree : ") );
    return Var;
}


// Validate choice to select Subject


int ChoiceSubjectValidate()
{
    int Choice;
    char *temp;
    printf("\nSelect the subject number to modify:\n\n1-Digital_Circuits\t2-Control_System\t3-Data_Structure\t"
           "4-Electronics\t5-Programming\t6-Measurements\n\nYour Choice : ");
    do{
        temp = SetString();
        Choice = StringToInt(temp);
    } while((Choice<1 || Choice>6) && printf("\nInvalid Choice! please try again..\n\nYour Choice : "));
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
    } while((choice!=1 && choice!=2) && printf("\nInvalid Choice! please try again..\n\nYour Choice : "));
    return choice;
}


// Validate choice to select UserMode


int ChooseModeValidate(){
    int choice;
    char *temp;
    printf("\n\n\t\t\t\t*-----------------------------------------------<<<<Welcome to Student_Record_System !>>>>-----------------------------------------------*\n\n");
    do{
        printf("\nChoose your Mode..."
               "\n\n1. Student Mode\t\t\t2. Admin Mode"
               "\t\t\t3. Quit\n\nYour Choice Number : ");
        fflush(stdout);
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice!=1 && choice!=2 && choice!=3) && printf("Invalid Choice! please try again..\n"));
    return choice;
}


// Validate choice to select Student Features


int ChooseStudentFeaturesValidate(){
    int choice;
    char *temp;
    do{
        printf("\nEnter Appropriate number to perform following tasks "
               "\n\n1. View your record\t\t2. Edit your password."
               "\t\t3. Edit your name\t\t4. Quit\n\nEnter Choice Number : ");
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice < 1 || choice > 4) && printf("\nInvalid Choice! please try again..\n"));
    return choice;
}


// Check Student Data to change Password


bool CheckStudentData(StudentNode *Head,long ID){

    printf("\n\"We need you to enter the following information to verify your identity\"\n");

    // Take National ID

    char *CorrectNationalID = NULL,*NationalID  = NULL;
    CorrectNationalID = StoreStudentNationalID(Head, ID);
    int cnt = 0;
    printf("\nEnter your National ID : ");
    do{
        NationalID = SetString();
        cnt++;
    }while(strcmp(NationalID,CorrectNationalID) && cnt < 3 && printf("\nWrong National ID, Try again...\n\nEnter your National ID : "));
    if(cnt >= 3) return false;

    // Take Phone Number

    long CorrectPhoneNumber,PhoneNumber;
    CorrectPhoneNumber = StoreStudentPhoneNumber(Head,ID);
    char *temp;
    cnt = 0;
    printf("\nEnter your Phone Number : +20");
    do{
        temp = SetString();
        PhoneNumber = StringToInt(temp);
        cnt++;
    }while(CorrectPhoneNumber != PhoneNumber && cnt < 3 && printf("\nWrong Phone Number, Try again...\n\nEnter your Phone Number : +20"));
    if(cnt >= 3) return false;

    // Take E-mail

    char *CorrectMail = NULL,*Mail = NULL;
    CorrectMail = StoreStudentMail(Head, ID);

    cnt = 0;
    printf("\nEnter your E-mail : ");
    do{
        Mail = SetString();
        cnt++;
    }while(strcmp(Mail,CorrectMail) && cnt < 3 && printf("\nWrong E-mail, Try again...\n\nEnter your E-mail : "));
    if(cnt >= 3) return false;

    return true;
}


// Check Student ID to log in

long CheckStudentID(StudentNode *Head){
    StudentNode *Current=NULL;

    bool flag;
    long ID;
    int cnt = 0;
    do{
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
    }while(flag && cnt < 6 && printf("\nWrong ID, Try again..\n\nEnter ID : "));

    if(cnt >= 6) {printf("\nSorry, You entered wrong ID many times, try later...\n") ; return 0;}

    return ID;
}


// Check Student Password to log in


int ChoiceValidation(){
    char *temp;
    int var;
    do{
        temp = SetString();
        var = StringToInt(temp);
    }while(var != 1 && var != 2 && printf("\nInvalid Choice, try again...\n\nYour Choice : "));
    return var;
}



bool CheckStudentPassword(StudentNode *Head, long ID){

    char *CorrectPassword = NULL, *Password = NULL;
    CorrectPassword = StoreStudentCorrectPassword(Head,ID);

    int cnt = 3, var = 0; bool f = false;
    do{
        if(f) { var = ChoiceValidation();}
        if(var == 1)
        {
            if(CheckStudentData(Head, ID))
            {
                char *str = NULL;
                str = CheckingRandomPasswordStrength(); // calling CheckingRandomPasswordStrength --> calling Generating RandomPassword
                printf("\nYour New Password is \"%s\"\n",str);
                StoreStudentNewPassword(Head,ID,str);
                WriteToStudentFile(Head);
                return true; // go to next background (Student's features)
            }else{
                printf("\n\nSorry, You entered wrong Information three times, Try later...\n");
                return false; // return to previous background (Admin or Student)
            }
        }
        else
        {   if(cnt == 2 || cnt == 1) printf("\n\nYou have %d more tries",cnt);
            if(cnt < 1) {printf("\n\nSorry, You entered wrong Password three times, Try later...\n"); return false;}
            if(f)printf("\n\nEnter your password : ");
            Password = SetPassword();
            cnt--;
        }
    }while(strcmp(CorrectPassword,Password) && printf("\nWrong Password, \"If you forget your "
                                                      "password, Enter (1)  ,  if not and want to ""try again... Enter (2)\"\n\nYour Choice : ") && (f = true));
    return true;
}


// Check Student Data to chang Password


bool CheckAdminData(AdminNode *Head,long ID){

    printf("\n\n\"We need you to enter the following information to verify your identity\"\n\n");


    // Take National ID

    char *CorrectNationalID = NULL,*NationalID  = NULL;
    CorrectNationalID = StoreAdminNationalID(Head, ID);

    int cnt = 0;
    printf("\nEnter your National_ID : ");
    do{
        NationalID = SetString();
        cnt++;
    }while(strcmp(NationalID,CorrectNationalID) && cnt < 3 && printf("\nWrong National ID, Try again...\n\nEnter your National_ID : "));
    if(cnt >= 3) { return false;}

    // Take Phone Number

    long CorrectPhoneNumber,PhoneNumber;
    CorrectPhoneNumber = StoreAdminPhoneNumber(Head,ID);
    char *temp;
    cnt = 0;
    printf("\nEnter your Phone Number : +20");
    do{
        temp = SetString();
        PhoneNumber = StringToInt(temp);
        cnt++;
    }while(CorrectPhoneNumber != PhoneNumber && cnt < 3 && printf("\nWrong Phone Number, Try again...\n\nEnter your Phone Number : +20"));
    if(cnt >= 3) { return false;}

    // Take E-mail

    char *CorrectMail = NULL,*Mail = NULL;
    CorrectMail = StoreAdminMail(Head, ID);

    cnt = 0;
    printf("\nEnter your E-mail : ");
    do{
        Mail = SetString();
        cnt++;
    }while(strcmp(Mail,CorrectMail) && cnt < 3 && printf("\nWrong E-mail, Try again...\n\nEnter your E-mail : "));
    if(cnt >= 3) { return false;}

    return true;
}


// Check Admin ID to log in


long CheckAdminID(AdminNode *Head){
    AdminNode *Current=NULL;

    bool flag;
    long ID;
    int cnt = 0;
    do{
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
    }while(flag && cnt < 10 && printf("\nWrong ID, Try again..\n\nEnter your ID : "));

    if(cnt >= 10) {printf("\nSorry, You entered wrong ID many times\n") ; return 0;}

    return ID;
}


// Check Admin Password to log in


bool CheckAdminPassword(AdminNode *Head, long ID){

    char *CorrectPassword = NULL, *Password = NULL;
    CorrectPassword = StoreAdminCorrectPassword(Head,ID);


    int cnt = 3, var = 0; bool f = false;
    do{
        if(f) { var = ChoiceValidation();}
        if(var == 1)
        {
            if(CheckAdminData(Head, ID))
            {
                char *str = NULL;
                str = CheckingRandomPasswordStrength(); // calling CheckingRandomPasswordStrength --> calling Generating RandomPassword
                printf("\n\nYour New Password is \"%s\"\n",str);
                StoreAdminNewPassword(Head,ID,str);
                WriteToAdminFile(Head);
                return true; // go to next background (Student's features)
            }else{
                printf("\nSorry, You entered wrong Information three times, Try later...\n");
                return false; // return to previous background (Admin or Student)
            }
        }
        else
        {
            if(cnt==2 || cnt==1) printf("\n\nYou have %d more tries",cnt);
            if(cnt < 1) {printf("\n\nSorry, You entered wrong Password three times, Try later...\n"); return false;}
            if(f)printf("\n\nEnter your password : ");
            Password = SetPassword();
            cnt--;
        }
    }while(strcmp(CorrectPassword,Password) && printf("\nWrong Password, \"If you forget your "
                                                      "password, Enter (1)  ,  if not and want to "
                                                      "try again... Enter (2)\"\nYour Choice : ") && (f = true));
    return true;
}


// Validate choice to select Student Affairs for Admin


int StudentAffairsValidate(){
    int choice;
    char *temp;
    do{
        printf("\nEnter Appropriate number to perform following tasks..."
               "\n\n1. Add New Student\t\t2. Remove Student.\t\t3. View Student Record\t\t"
               "\t\t4. View All Records\t\t5. Edit Student Grade\t\t6. Quit\n\nYour Choice Number : ");
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice < 1 || choice > 6) && printf("\nInvalid Choice! please try again..\n"));
    return choice;
}

int EditAdminInfoValidate(){
    int choice;
    char *temp;
    do{
        printf("\nEnter Appropriate number to perform following tasks..."
               "\n\n1. Edit your name\t\t2. Edit your password.\t\t3. Quit\n\nYour Choice Number : ");
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice < 1 || choice > 3) && printf("\nInvalid Choice! please try again..\n"));
    return choice;

}