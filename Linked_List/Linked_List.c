#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Program/Program.h"
#include "Linked_List.h"
#include "../Validation/Validation.h"
#define MAX_STRING_LENGTH 50
// Search for Existing Student

void SearchForStudent(StudentNode *head, long ID){
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
            printf(" Data_Structure  \t\t  %d \t\t  %s\n",ptr->Data.Subject.Programming.Degree    ,ptr->Data.Subject.Programming.Rate);
            printf(" Electronics     \t\t  %d \t\t  %s\n",ptr->Data.Subject.Programming.Degree    ,ptr->Data.Subject.Electronics.Rate);
            printf(" Programming     \t\t  %d \t\t  %s\n",ptr->Data.Subject.DataStructure.Degree  ,ptr->Data.Subject.DataStructure.Rate);
            printf(" Measurements     \t\t  %d \t\t  %s\n",ptr->Data.Subject.Measurements.Degree    ,ptr->Data.Subject.Measurements.Rate);
            printf("______________________________________________________\n");
            PrintSupportingMessage(ptr->Data.TotalGrade);
            break;
        }
        ptr = ptr->Link;
    }
}


// Adding New Student

StudentNode* AddNewStudent(StudentNode *ptr, StudentNode *head){
    StudentNode *temp = NULL;
    temp = malloc(sizeof(StudentNode));

    temp->Data.Student.Name     = malloc(MAX_STRING_LENGTH*sizeof(char));
    // Ask Admin For Student Data

    printf("\nEnter Student ID \"Only digits are allowed\" : ");
    temp->Data.Student.ID = CheckExistingID(head);
    printf("\nEnter Student Name : ");
    while(getchar()!='\n');
    temp->Data.Student.Name = ValidName();
    printf("\nEnter Student Password : ");
    temp->Data.Student.Password = CheckingPasswordStrength();
    printf("\nEnter Student Gender : ");
    temp->Data.Student.Gender = ValidateGender();
    printf("\nEnter Student Age : ");
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
    temp->Data.Subject.Measurements.Rate     = CalcSubjectGrade(temp->Data.Subject.Measurements.Degree);

    // Assign Student Total Degree

    temp->Data.TotalDegree = CalcTotalDegree(temp);

    // Assign Student Total Grade

    temp->Data.TotalGrade = CalcTotalGrade(temp->Data.TotalDegree);

    // Assign Student GPA

    temp->Data.GPA = CalcGPA(temp->Data.TotalDegree);


    temp->Link = NULL;
    ptr->Link = temp;
    return temp;
}



// Add New Node In Linked List

StudentNode* AddNewNode(StudentNode *ptr1, StudentInfo Data)
{
    StudentNode *ptr = NULL;
    ptr = malloc(sizeof(StudentNode));

    ptr->Data = Data;
    ptr->Link = NULL;
    ptr1->Link = ptr;
    return ptr;
}