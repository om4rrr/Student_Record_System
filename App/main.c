#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Validation/Validation.h"
#include "../Filehandling/Filehandling.h"
#include "App.h"



int main()
{
    StudentNode *HeadStudent = NULL;
    AdminNode *HeadAdmin = NULL;
    ReadStudentFile(&HeadStudent);
    ReadAdminFile(&HeadAdmin);

    StartApp(&HeadStudent, HeadAdmin);

    WriteToStudentFile(HeadStudent);
    WriteToAdminFile(HeadAdmin);
    DeallocateStudent(&HeadStudent);
    DeallocateAdmin(&HeadAdmin);
    return 0;
}