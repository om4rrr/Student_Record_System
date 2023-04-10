#ifndef VALIDATION_H
#define VALIDATION_H

#include "../Linked_List/Linked_List.h"
#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Linked_List/Linked_List.h"

long ValidateIDLength();

long CheckExistingID(StudentNode *head);

char* ValidName();

char *CheckingPasswordStrength();

int ValidateStudentAge();

char* ValidateGender();

int ValidateSubjectDegree();


#endif