#include "Libraries/Libraries.h"
#include "Struct/Struct.h"
#include "Validation/Validation.h"
#include "Linked_List/Linked_List.h"
#include "Program/Program.h"
#include "Admin/Admin.h"
#include "Student/Student.h"
#include "Filehandling/Filehandling.h"



int main()
{

    /*AdminNode *HeadAdmin =NULL;
    HeadAdmin = (AdminNode *)malloc(sizeof(AdminNode));
    HeadAdmin->Data.ID = 1234567 , HeadAdmin->Data.Age = 19, HeadAdmin->Data.Name = "Raghad", HeadAdmin->Data.Password = "*#300#*" , HeadAdmin->Data.Gender = "female";
    HeadAdmin->Link= NULL;

    AdminNode *current = (AdminNode *)malloc(sizeof(AdminNode));
    current->Data.ID = 1114111 , current->Data.Age = 20, current->Data.Name = "omar", current->Data.Password = "*#100#*" , current->Data.Gender = "male";
    current->Link= NULL;
    HeadAdmin->Link=current;*/


    StudentNode *HeadStudent =NULL;
    HeadStudent = (StudentNode *)malloc(sizeof(StudentNode));
    HeadStudent->Data.Student.ID = 123444321 , HeadStudent->Data.Student.Age = 19, HeadStudent->Data.Student.Name = "Nabil", HeadStudent->Data.Student.Password = "Nabil88" , HeadStudent->Data.Student.Gender = "male";
    HeadStudent->Data.Subject.Measurements.Degree    = 102 , HeadStudent->Data.Subject.Measurements.Rate    = CalcSubjectGrade(102);
    HeadStudent->Data.Subject.Programming.Degree     = 115 , HeadStudent->Data.Subject.Programming.Rate     = CalcSubjectGrade(115);
    HeadStudent->Data.Subject.Electronics.Degree     = 110 , HeadStudent->Data.Subject.Electronics.Rate     = CalcSubjectGrade(110);
    HeadStudent->Data.Subject.ControlSystem.Degree   = 120 , HeadStudent->Data.Subject.ControlSystem.Rate   = CalcSubjectGrade(120);
    HeadStudent->Data.Subject.DigitalCircuits.Degree = 100 , HeadStudent->Data.Subject.DigitalCircuits.Rate = CalcSubjectGrade(100);
    HeadStudent->Data.Subject.DataStructure.Degree   = 108 , HeadStudent->Data.Subject.DataStructure.Rate   = CalcSubjectGrade(108);
    HeadStudent->Data.TotalDegree = CalcTotalDegree(HeadStudent); HeadStudent->Data.TotalGrade = CalcTotalGrade(HeadStudent->Data.TotalDegree);
    HeadStudent->Data.GPA = CalcGPA(HeadStudent->Data.TotalDegree);
    HeadStudent->Link= NULL;

    StudentNode *currentStudent =NULL;
    currentStudent = (StudentNode *)malloc(sizeof(StudentNode));
    currentStudent->Data.Student.ID = 111444444 , currentStudent->Data.Student.Age = 19, currentStudent->Data.Student.Name = "Marwa", currentStudent->Data.Student.Password = "Marwa44" , currentStudent->Data.Student.Gender = "female";
    currentStudent->Data.Subject.Measurements.Degree    = 105 , currentStudent->Data.Subject.Measurements.Rate    = CalcSubjectGrade(105);
    currentStudent->Data.Subject.Programming.Degree     = 100 , currentStudent->Data.Subject.Programming.Rate     = CalcSubjectGrade(100);
    currentStudent->Data.Subject.Electronics.Degree     = 122 , currentStudent->Data.Subject.Electronics.Rate     = CalcSubjectGrade(122);
    currentStudent->Data.Subject.ControlSystem.Degree   = 113 , currentStudent->Data.Subject.ControlSystem.Rate   = CalcSubjectGrade(113);
    currentStudent->Data.Subject.DigitalCircuits.Degree = 111 , currentStudent->Data.Subject.DigitalCircuits.Rate = CalcSubjectGrade(111);
    currentStudent->Data.Subject.DataStructure.Degree   = 120 , currentStudent->Data.Subject.DataStructure.Rate   = CalcSubjectGrade(120);
    currentStudent->Data.TotalDegree = CalcTotalDegree(currentStudent); currentStudent->Data.TotalGrade = CalcTotalGrade(currentStudent->Data.TotalDegree);
    currentStudent->Data.GPA = CalcGPA(currentStudent->Data.TotalDegree);
    currentStudent->Link= NULL;
    HeadStudent->Link=currentStudent;


   // currentStudent = AddNewStudent(currentStudent,HeadStudent);
    WriteToFile(HeadStudent);


    printf("hello");
    StdIdCheck(HeadStudent);
   // StdRec(HeadStudent);
    //EditStdName( HeadStudent);

    //ReadFromFile(HeadStudent);
    //SearchForStudent(HeadStudent,111444444);


    return 0;
}
