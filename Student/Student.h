#ifndef STUDENT_H
#define STUDENT_H
#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Validation/Validation.h"
#include "../Program/Program.h"
#include "../Linked_List/Linked_List.h"

void StdIdCheck(StudentNode *head);
void StdPassCheck(StudentNode *head);
void StdMode(struct StudentNode *CurrentStd);
void StdRec(struct StudentNode *CurrentStd);
void EditStdPass(struct StudentNode *CurrentStd);
void EditStdName(struct StudentNode *CurrentStd);

#endif
