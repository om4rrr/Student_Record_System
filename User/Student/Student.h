#ifndef STUDENT_H
#define STUDENT_H

#include "../../Libraries/Libraries.h"
#include "../../Linked_List/Struct.h"
#include "../../Linked_List/Linked_List.h"
#include "../../Program/Validation/Validation.h"
#include "../../Program/Program.h"
#include "../../Filehandling/Filehandling.h"

#define MAX_STRING_LENGTH 50


void StudentMode(StudentNode *Head);

char *EditStudentName(StudentNode *Head,long ID);


#endif