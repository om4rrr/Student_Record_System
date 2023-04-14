#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "../Linked_List/Linked_List.h"
#include "../Libraries/Libraries.h"
#include "../Program/Program.h"
#include "../Linked_List/Struct.h"
#include "../Validation/Validation.h"

#define MAX_STRING_LENGTH 50

void WriteToStudentFile(StudentNode* ptr);

void ReadStudentFile(StudentNode **ptr);

void WriteToAdminFile(AdminNode* ptr);

void ReadAdminFile(AdminNode **ptr);


#endif