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


void SearchForStudent(StudentNode *head, long ID);

StudentNode* AddNewStudent(StudentNode *ptr, StudentNode *head);


StudentNode* AddNewNode(StudentNode *ptr1, StudentInfo Data);



#endif