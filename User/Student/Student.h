#ifndef STUDENT_H
#define STUDENT_H

#include "../../Libraries/Libraries.h"
#include "../../Linked_List/Struct.h"
#include "../../Linked_List/Linked_List.h"
#include "../../Validation/Validation.h"
#include "../../Program/Program.h"
#include "../../Filehandling/Filehandling.h"

#define MAX_STRING_LENGTH 50


void StudentMode(StudentNode *Head);

char *EditStudentName(StudentNode *Head,long ID);

void PrintStudentInfo(StudentNode *head, long ID);


#endif