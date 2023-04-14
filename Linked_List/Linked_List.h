#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Libraries/Libraries.h"
#include "Struct.h"

#define MAX_STRING_LENGTH 50


typedef struct StudentNode{
    StudentInfo Data;
    struct StudentNode* Link;
}StudentNode;

typedef struct AdminNode{
    UserInfo Data;
    struct AdminNode* Link;
}AdminNode;


int AddStudentNode(StudentNode ** Head, StudentInfo Data);

int AddAdminNode(AdminNode ** Head, UserInfo Data);

void DeallocateStudent(StudentNode ** Head);

void DeallocateAdmin(AdminNode ** Head);


#endif