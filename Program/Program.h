#ifndef PROGRAM_H
#define PROGRAM_H

#include "../Linked_List/Linked_List.h"
#define MAX_STRING_LENGTH 50

double CalcTotalDegree(StudentNode *head);

char *CalcTotalGrade(double TotalDegree);

char *CalcSubjectGrade(double TotalDegree);

double CalcGPA(double TotalDegree);

size_t Strlen(const char *s);

char *SetString();

void PrintSupportingMessage(char *str);

char *StoreCorrectPassword(StudentNode *ptr,long ID);

void StoreNewPassword(StudentNode *ptr,long ID, char *Password);

char *StoreNationalID(StudentNode *ptr,long ID);

long StorePhoneNumber(StudentNode *ptr,long ID);

char *StoreStudentMail(StudentNode *ptr,long ID);

char *RandomString(char *str, int Num);

#endif