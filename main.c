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
    AdminNode *HeadAdmin = NULL;
    ReadStudentFile(&HeadStudent);
    ReadAdminFile(&HeadAdmin);


    while(1){
        int choice = ChooseModeValidate();
        bool EOP = false;
        switch (choice) {
            case 1: StudentMode(HeadStudent); break;
            case 2: AdminMode(HeadAdmin,&HeadStudent);   break;
            case 3: EOP = true;    break;
        }
        if(EOP) break;
    }



    WriteToStudentFile(HeadStudent);
    WriteToAdminFile(HeadAdmin);
    DeallocateStudent(&HeadStudent);
    DeallocateAdmin(&HeadAdmin);
    return 0;
}