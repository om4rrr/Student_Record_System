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
    StudentNode *HeadStudent =NULL;
    ReadFromFile(&HeadStudent);


    printf("Enter your ID : ");
    long ID = CheckStudentID(HeadStudent);
    printf("Enter your Password : ");
    char *Password = CheckStudentPassword(HeadStudent, ID);


    WriteToFile(HeadStudent);
    return 0;
}