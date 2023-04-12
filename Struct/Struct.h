#ifndef STRUCT_H
#define STRUCT_H
#include "../Libraries/Libraries.h"

typedef struct UserInfo{
    long ID;
    char *NationalID;
    long PhoneNumber;
    int  Age;
    char *Name;
    char *Password;
    char *Gender;
    char *Mail;
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
    struct SubjectsGrades Subject;  // StudentInfo ob;   ob.Subject.DigitalCircuits.Degree = 100, ob.Subject.DigitalCircuits.Rate = "A+"
                                   //  ob.Student.Id = 123456789  ob.TotalDegree = 700
    double GPA;
    double TotalDegree;
    char *TotalGrade;
}StudentInfo;

#endif