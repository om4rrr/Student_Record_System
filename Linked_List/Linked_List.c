#include "Linked_List.h"

// Add New Node In Student Linked List


int AddStudentNode(StudentNode ** root, StudentInfo Data) {
    StudentNode* NewNode = malloc(sizeof(StudentNode));
    if (NewNode == NULL) {
        exit(1);
    }
    NewNode->Link = NULL;
    NewNode->Data= Data;

    if (*root == NULL) {
        *root = NewNode;
        return 1;
    }

    StudentNode * curr = *root;
    while (curr->Link != NULL) {
        curr = curr->Link;
    }
    curr->Link = NewNode;
    return  1;
}


// Add New Node In Admin Linked List


int AddAdminNode(AdminNode ** root, UserInfo Data) {
    AdminNode * NewNode = malloc(sizeof(AdminNode));
    if (NewNode == NULL) {
        exit(1);
    }
    NewNode->Link = NULL;
    NewNode->Data = Data;

    if (*root == NULL) {
        *root = NewNode;
        return 1;
    }

    AdminNode *curr = *root;
    while (curr->Link != NULL) {
        curr = curr->Link;
    }
    curr->Link = NewNode;
    return  1;
}

// Deallocate Student Linked List


void DeallocateStudent(StudentNode ** root) {
    StudentNode * curr = *root;
    while (curr != NULL) {
        StudentNode * aux = curr;
        curr = curr->Link;
        free(aux);
    }
    *root = NULL;
}


// Deallocate Admin Linked List


void DeallocateAdmin(AdminNode ** root) {
    AdminNode * curr = *root;
    while (curr != NULL) {
        AdminNode * aux = curr;
        curr = curr->Link;
        free(aux);
    }
    *root = NULL;
}