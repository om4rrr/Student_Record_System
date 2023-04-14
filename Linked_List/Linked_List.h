#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Libraries/Libraries.h"
#include "Struct.h"
#include "../Program/Validation/Validation.h"

#define MAX_STRING_LENGTH 50



typedef struct StudentNode{
    StudentInfo Data;
    struct StudentNode* Link;
}StudentNode;

typedef struct AdminNode{
    UserInfo Data;
    struct AdminNode* Link;
}AdminNode;


void PrintStudentInfo(StudentNode *head, long ID);

void PrintStudentInfo_ForAdmin(StudentNode *head, long ID);

void PrintAllRecords(StudentNode *head);

char *AddNewStudent(StudentNode **Head);

int AddStudentNode(StudentNode ** Head, StudentInfo Data);

int AddAdminNode(AdminNode ** Head, UserInfo Data);

char *ModifyStudentGrade(StudentNode *head, long ID);

char *DeleteStudent(StudentNode** head, long ID);

void DeallocateStudent(StudentNode ** Head);

void DeallocateAdmin(AdminNode ** Head);


#endif