#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"

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

void AddNewStudent(StudentNode **Head);

int AddStudentNode(StudentNode ** root, StudentInfo Data);

int AddAdminNode(AdminNode ** root, UserInfo Data);

void ModifyStudentGrade(StudentNode *head, long ID);

void DeleteStudent(StudentNode** head, long ID);

void DeallocateStudent(StudentNode ** root);

void DeallocateAdmin(AdminNode ** root);


#endif