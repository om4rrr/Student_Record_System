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


    printf("Enter your ID : ");
    CheckStudentID(HeadStudent);
    printf("Enter your Password : ");
    if (CheckStudentPassword(HeadStudent)) printf("\nhhhhhhhhhhhh\n");
    else printf("\nggggggg\n");





    //PrintStudentInfo(HeadStudent,123456789);


    WriteToFile(HeadStudent);

    deallocate(&HeadStudent);
    return 0;
}