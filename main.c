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




    WriteToFile(HeadStudent);
    return 0;
}