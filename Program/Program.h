#ifndef PROGRAM_H
#define PROGRAM_H

#include "../Linked_List/Linked_List.h"
#include "../Libraries/Libraries.h"
#include "../Linked_List/Struct.h"
#include "../Validation/Validation.h"

#define MAX_STRING_LENGTH 50

double CalcTotalDegree(StudentNode *head);

char *CalcTotalGrade(double TotalDegree);

char *CalcSubjectGrade(double TotalDegree);

double CalcGPA(double TotalDegree);

size_t Strlen(const char *s);

char *SetString();

char* SetPassword();

int StringToInt(char* StringNum);

void PrintSupportingMessage(char *str);

char *StoreStudentCorrectPassword(StudentNode *ptr,long ID);

void StoreStudentNewPassword(StudentNode *Head,long ID, char *Password);

char *StudentName(StudentNode *ptr,long ID);

char *StoreStudentNationalID(StudentNode *ptr,long ID);

long StoreStudentPhoneNumber(StudentNode *ptr,long ID);

char *StoreStudentMail(StudentNode *ptr,long ID);

char *StoreAdminCorrectPassword(AdminNode *ptr,long ID);

void StoreAdminNewPassword(AdminNode *Head,long ID, char *Password);

char *AdminName(AdminNode *ptr,long ID);

char *StoreAdminNationalID(AdminNode *ptr,long ID);

long StoreAdminPhoneNumber(AdminNode *ptr,long ID);

char *StoreAdminMail(AdminNode *ptr,long ID);

char *RandomString(char *str, int Num);


#endif