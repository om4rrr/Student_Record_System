#ifndef STRUCT_H
#define STRUCT_H
#include "../Libraries/Libraries.h"

typedef struct UserInfo{
    long ID;
    int  Age;
    char *Name;
    char *Password;
    char *Gender;
}UserInfo;


typedef struct Grade{
    int Degree;
    char *Rate;

}Grade;


typedef struct SubjectsGrades{
    struct Grade Programming;
    struct Grade ControlSystem;
    struct Grade Electronics;
    struct Grade DigitalCircuits;
    struct Grade DataStructure;
    struct Grade Measurements;
}SubjectsGrades;


typedef struct StudentInfo{
    struct UserInfo Student;
    struct SubjectsGrades Subject;
    double GPA;
    double TotalDegree;
    char *TotalGrade;
}StudentInfo;

#endif