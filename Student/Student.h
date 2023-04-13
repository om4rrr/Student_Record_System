#ifndef STUDENT_H
#define STUDENT_H

#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Linked_List/Linked_List.h"
#include "../Validation/Validation.h"
#include "../Program/Program.h"

#define MAX_STRING_LENGTH 50


void StudentMode(StudentNode *Head);



void StdMode(StudentNode *CurrentStd);
void StdRec(StudentNode *CurrentStd);
void EditStdPass(StudentNode *CurrentStd);
void EditStdName(StudentNode *CurrentStd);

#endif