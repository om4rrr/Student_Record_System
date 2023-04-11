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

char *StoreStudentName(StudentNode *ptr,long ID);

long StoreNationalID(StudentNode *ptr,long ID);

long StorePhoneNumber(StudentNode *ptr,long ID);

char *StoreStudentMail(StudentNode *ptr,long ID);

void RandomString(char *str, int Num);

bool CheckStudentData(StudentNode *ptr,long ID);

#endif