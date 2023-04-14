#include "Admin.h"


// Print All Student Records

void PrintAllRecords(StudentNode *head){
    struct StudentNode *ptr = NULL;
    ptr = head;

    printf("\n*---------------------------------------------------------------------------------<<<<ALL STUDENT RECORDS>>>>--------------------------------------------------------------------------------*\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("    Student Name             Student ID         Digital Circuits    Control System    Data Structure    Electronics     Programming     Measurements      GPA      Total Degree     Total Grade\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while(ptr != NULL)
    {

        printf("\n %-28s%ld\t\t   %3d  ,  %2s\t      %3d  ,  %2s\t%3d  ,  %2s\t %3d  ,  %2s\t %3d  ,  %2s\t %3d  ,  %2s\t  %1.1lf\t      %3.2lf\t\t %2s\n",
               ptr->Data.Student.Name,ptr->Data.Student.ID,ptr->Data.Subject.DigitalCircuits.Degree,ptr->Data.Subject.DigitalCircuits.Rate,
               ptr->Data.Subject.ControlSystem.Degree  ,ptr->Data.Subject.ControlSystem.Rate,ptr->Data.Subject.DataStructure.Degree,
               ptr->Data.Subject.DataStructure.Rate,ptr->Data.Subject.Electronics.Degree,ptr->Data.Subject.Electronics.Rate,
               ptr->Data.Subject.Programming.Degree    ,ptr->Data.Subject.Programming.Rate,ptr->Data.Subject.Measurements.Degree,
               ptr->Data.Subject.Measurements.Rate,ptr->Data.GPA,ptr->Data.TotalDegree, ptr->Data.TotalGrade);
        ptr = ptr->Link;
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Print Student information for Admin

void PrintStudentInfo_ForAdmin(StudentNode *head, long ID){
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
        }
        ptr = ptr->Link;
    }
}


// Adding New Student


char *AddNewStudent(StudentNode **Head){

    StudentNode* temp = malloc(sizeof(StudentNode));
    if (temp == NULL) {
        exit(1);
    }
    temp->Link = NULL;

    temp->Data.Student.Name     = malloc(MAX_STRING_LENGTH*sizeof(char));

    // Ask Admin For Student Data

    printf("\nEnter ID \"Only digits are allowed\" : ");
    temp->Data.Student.ID = CheckExistingID(*Head);
    printf("\nEnter National ID : ");
    temp->Data.Student.NationalID = ValidateNationalIDLength();
    printf("\nEnter Phone Number : +20");
    temp->Data.Student.PhoneNumber = CheckPhoneNumber();
    printf("\nEnter Name : ");
    temp->Data.Student.Name = ValidName();
    printf("\nEnter Password : ");
    temp->Data.Student.Password = CheckingPasswordStrength();
    printf("\nEnter E-mail : ");
    temp->Data.Student.Mail = CheckMailValidation();
    printf("\nEnter Gender : ");
    temp->Data.Student.Gender = ValidateGender();
    printf("\nEnter Age : ");
    temp->Data.Student.Age = ValidateStudentAge();

    // Ask Admin For Student_Degrees Data

    printf("\nEnter Digital_Circuits Degree : ");
    temp->Data.Subject.DigitalCircuits.Degree = ValidateSubjectDegree();
    printf("\nEnter Control_System Degree : ");
    temp->Data.Subject.ControlSystem.Degree = ValidateSubjectDegree();
    printf("\nEnter Data_Structure Degree : ");
    temp->Data.Subject.DataStructure.Degree = ValidateSubjectDegree();
    printf("\nEnter Electronics Degree : ");
    temp->Data.Subject.Electronics.Degree = ValidateSubjectDegree();
    printf("\nEnter Programming Degree : ");
    temp->Data.Subject.Programming.Degree = ValidateSubjectDegree();
    printf("\nEnter Measurements Degree : ");
    temp->Data.Subject.Measurements.Degree = ValidateSubjectDegree();

    // Assign Subject Grade

    temp->Data.Subject.DigitalCircuits.Rate = CalcSubjectGrade(temp->Data.Subject.DigitalCircuits.Degree);
    temp->Data.Subject.ControlSystem.Rate   = CalcSubjectGrade(temp->Data.Subject.ControlSystem.Degree);
    temp->Data.Subject.DataStructure.Rate   = CalcSubjectGrade(temp->Data.Subject.DataStructure.Degree);
    temp->Data.Subject.Electronics.Rate     = CalcSubjectGrade(temp->Data.Subject.Electronics.Degree);
    temp->Data.Subject.Programming.Rate     = CalcSubjectGrade(temp->Data.Subject.Programming.Degree);
    temp->Data.Subject.Measurements.Rate    = CalcSubjectGrade(temp->Data.Subject.Measurements.Degree);

    // Assign Student Total Degree

    temp->Data.TotalDegree = CalcTotalDegree(temp);

    // Assign Student Total Grade

    temp->Data.TotalGrade = CalcTotalGrade(temp->Data.TotalDegree);

    // Assign Student GPA

    temp->Data.GPA = CalcGPA(temp->Data.TotalDegree);

    if (*Head == NULL) {
        *Head = temp;
    }else {
        StudentNode *curr = *Head;
        while (curr->Link != NULL) {
            curr = curr->Link;
        }
        curr->Link = temp;
    }
    return "\n\"Student Added Successfully\"\n";
}


// Modify Student Degree


char *ModifyStudentGrade(StudentNode *head){

    long ID;
    printf("Enter ID : ");
    ID = CheckStudentID(head);
    if(ID > 0) {

        int Choice1, Choice2, NewDegree;
        struct StudentNode *ptr = NULL;
        do {

            ptr = head;
            while (ptr != NULL) {
                if (ptr->Data.Student.ID == ID) {

                    Choice1 = ChoiceSubjectValidate();
                    printf("\nEnter new Degree : ");
                    NewDegree = ValidateSubjectDegree();
                    switch (Choice1) {
                        case 1 :
                            ptr->Data.Subject.DigitalCircuits.Degree = NewDegree;
                            ptr->Data.Subject.DigitalCircuits.Rate = CalcSubjectGrade(NewDegree);
                            break;
                        case 2 :
                            ptr->Data.Subject.ControlSystem.Degree = NewDegree;
                            ptr->Data.Subject.ControlSystem.Rate = CalcSubjectGrade(NewDegree);
                            break;
                        case 3 :
                            ptr->Data.Subject.DataStructure.Degree = NewDegree;
                            ptr->Data.Subject.DataStructure.Rate = CalcSubjectGrade(NewDegree);
                            break;
                        case 4 :
                            ptr->Data.Subject.Electronics.Degree = NewDegree;
                            ptr->Data.Subject.Electronics.Rate = CalcSubjectGrade(NewDegree);
                            break;
                        case 5 :
                            ptr->Data.Subject.Programming.Degree = NewDegree;
                            ptr->Data.Subject.Programming.Rate = CalcSubjectGrade(NewDegree);
                            break;
                        case 6 :
                            ptr->Data.Subject.Measurements.Degree = NewDegree;
                            ptr->Data.Subject.Measurements.Rate = CalcSubjectGrade(NewDegree);
                            break;
                    }
                    ptr->Data.TotalDegree = CalcTotalDegree(ptr);
                    ptr->Data.TotalGrade = CalcTotalGrade(ptr->Data.TotalDegree);
                    ptr->Data.GPA = CalcGPA(ptr->Data.TotalDegree);

                    Choice2 = ChoiceAnotherSubjectValidate();
                }
                ptr = ptr->Link;
            }
        } while (Choice2 == 1);
        free(ptr);
        ptr = NULL;

        return "\n\"Student Grade Edited Successfully\"\n";
    }
    else return "";
}


// Delete Student


char *DeleteStudent(StudentNode** head){


    // get ID from admin

    long ID;
    printf("Enter ID : ");
    ID = CheckStudentID(*head);
    if(ID > 0) {

        // find position

        int pos = 0;
        StudentNode *ptr = NULL;
        ptr = *head;
        while (ptr != NULL) {
            pos++;
            if (ptr->Data.Student.ID == ID) break;
            ptr = ptr->Link;
        }

        StudentNode *current = *head, *previous = *head;

        if (pos == 1) {
            *head = current->Link;
            free(current);
            current = NULL;
        } else {
            while (pos != 1) {
                previous = current;
                current = current->Link;
                pos--;
            }
            previous->Link = current->Link;
            free(current);
            current = NULL;
        }
        return "\n\"Student Removed Successfully\"\n";
    }
    else return "";
}

// Edit Student Name

char *EditAdminName(AdminNode *Head,long ID){

    AdminNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            printf("\n  ------------<<Edit Your Name>>------------  \n"
                   "Enter your Name : " );

            Current->Data.Name = ValidName();
        }
        Current = Current->Link;
    }
    WriteToAdminFile(Head);
    return "\n\"Name Edited Successfully\"\n\n";
}

// Edit Student password

char *EditAdminPassword(AdminNode *Head,long ID){

    AdminNode *Current=NULL;
    Current = Head;
    while(Current != NULL)
    {
        if(ID == Current->Data.ID)
        {
            printf("\n  -----------<<Edit Your Password>>-----------  \n"
                   "Enter your password : ");

            Current->Data.Password = CheckingPasswordStrength();
        }
        Current = Current->Link;
    }
    WriteToAdminFile(Head);
    return "\n\"Password Edited Successfully\"\n\n";
}


// Choose Admin Features

void  ChooseAdminFeatures(AdminNode *AdminHead, StudentNode **StudentHead, long ID){

    while(1) {
        printf("\n*------------------------<<<<Hello, %s>>>>--------------------------*\n\n", AdminName(AdminHead, ID));
        printf("\n\nEnter Appropriate Choice...\n");
        int choice1;
        char *temp;
        do {
            printf("\n1. Student Affairs\t\t\t2. Edit your information\t\t\t3. Quit\nYour Choice Number : ");
            fflush(stdout);
            temp = SetString();
            choice1 = atoi(temp);
        } while ((choice1 != 1 && choice1 != 2 && choice1 != 3) && printf("Invalid Choice! please try again..\n"));

        if (choice1 == 1) {
            while (1) {
                int choice = StudentAffairsValidate();
                bool Quit = false;
                switch (choice) {
                    case 1:
                        printf("%s",AddNewStudent(StudentHead));
                        WriteToStudentFile(*StudentHead);
                        break;
                    case 2:
                        printf("%s",DeleteStudent(StudentHead));
                        WriteToStudentFile(*StudentHead);
                        break;
                    case 3:
                        PrintStudentInfo_ForAdmin(*StudentHead, ID);
                        break;
                    case 4:
                        PrintAllRecords(*StudentHead);
                        break;
                    case 5:
                        printf("%s",ModifyStudentGrade(*StudentHead));
                        WriteToStudentFile(*StudentHead);
                        break;
                    case 6:
                        Quit = true; break;

                }
                if (Quit) break;
            }
        } else if (choice1 == 2) {
            while (1) {
                int choice = EditAdminInfoValidate(AdminHead, ID);
                bool Quit = false;
                switch (choice) {
                    case 1:
                        printf("%s", EditAdminName(AdminHead, ID));
                        break;
                    case 2:
                        printf("%s", EditAdminPassword(AdminHead, ID));
                        break;
                    case 3:
                        Quit = true;
                        break;
                }
                if (Quit) break;
            }
        }
        else break;
    }
}


// Admin Log In

void AdminMode(AdminNode *AdminHead,StudentNode **StudentHead){
    printf("\nEnter your ID : ");
    long ID = CheckAdminID(AdminHead);
    if(ID > 0) {
        printf("\nEnter your Password : ");
        if (CheckAdminPassword(AdminHead, ID)) ChooseAdminFeatures(AdminHead, StudentHead, ID);
    }
}