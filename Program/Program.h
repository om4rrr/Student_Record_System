#ifndef PROGRAM_H
#define PROGRAM_H

#include "../Linked_List/Linked_List.h"

double CalcTotalDegree(StudentNode *head);

char *CalcTotalGrade(double TotalDegree);

char *CalcSubjectGrade(double TotalDegree);

double CalcGPA(double TotalDegree);

size_t Strlen(const char *s);

char *SetString();

void PrintSupportingMessage(char *str);

#endif