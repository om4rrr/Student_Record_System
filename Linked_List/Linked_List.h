#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"

typedef struct StudentNode{
    struct StudentInfo Data;
    struct StudentNode* Link;
}StudentNode;

typedef struct AdminNode{
    struct UserInfo Data;
    struct UserInfo* Link;
}AdminNode;


void PrintStudentInfo(StudentNode *head, long ID);

StudentNode* AddNewStudent(StudentNode *ptr, StudentNode *head);


int AddNewNode(StudentNode ** root, StudentInfo Data);

void ModifyStudentDegree(struct StudentNode *head, long ID);

void DelStudent(StudentNode** head, long ID);
void deallocate(StudentNode ** root);



#endif