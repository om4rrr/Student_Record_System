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
    StudentNode *HeadStudent = NULL;
    ReadFromFile(&HeadStudent);



    printf("\nEnter your ID : ");
    long ID = CheckStudentID(HeadStudent);
    printf("\nEnter your Password : ");
    if (CheckStudentPassword(HeadStudent, ID)) printf("");
    else printf("");

    printf("\n\n%s\n",HeadStudent->Data.Student.Password);
    //PrintStudentInfo(HeadStudent,123456789);


    WriteToFile(HeadStudent);
    deallocate(&HeadStudent);
    return 0;
}