#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Validation/Validation.h"
#include "../Program/Program.h"
#include "../Linked_List/Linked_List.h"
#include "Filehandling.h"


// Writing to file


void WriteToFile(struct StudentNode* ptr) {
    FILE* file = fopen("Data_base.txt", "w");
    if (file == NULL) exit(1);

    for (struct StudentNode* current = ptr; current != NULL; current = current->Link) {
        fprintf(file,"%ld, %d, %s, %s, %s, %d, %s, %d, %s, %d, %s, %d, %s, %d, %s, %d, %s, %lf, %s, %lf,\n",
                current->Data.Student.ID,current->Data.Student.Age,current->Data.Student.Name,
                current->Data.Student.Password,current->Data.Student.Gender,
                current->Data.Subject.DigitalCircuits.Degree,current->Data.Subject.DigitalCircuits.Rate,
                current->Data.Subject.ControlSystem.Degree,current->Data.Subject.ControlSystem.Rate,
                current->Data.Subject.DataStructure.Degree,current->Data.Subject.DataStructure.Rate,
                current->Data.Subject.Electronics.Degree,current->Data.Subject.Electronics.Rate,
                current->Data.Subject.Programming.Degree,current->Data.Subject.Programming.Rate,
                current->Data.Subject.Measurements.Degree,current->Data.Subject.Measurements.Rate,
                current->Data.TotalDegree,current->Data.TotalGrade,current->Data.GPA);
    }
    fclose(file);
    free(ptr);
}




void ReadFromFile(StudentNode *ptr) {

    FILE* file = fopen("Data_base.txt", "r");
    if (file == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }

    struct StudentNode *current = NULL;
    current = (StudentNode *)malloc(sizeof(StudentNode));

    do{
        current->Data.Student.Name     = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Student.Password = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Student.Gender   = malloc(7*sizeof(char));
        current->Data.TotalGrade       = malloc(2*sizeof(char));
        current->Data.Subject.DigitalCircuits.Rate  = malloc(2*sizeof(char));
        current->Data.Subject.DataStructure.Rate    = malloc(2*sizeof(char));
        current->Data.Subject.ControlSystem.Rate    = malloc(2*sizeof(char));
        current->Data.Subject.Electronics.Rate      = malloc(2*sizeof(char));
        current->Data.Subject.Programming.Rate      = malloc(2*sizeof(char));
        current->Data.Subject.Measurements.Rate     = malloc(2*sizeof(char));
        current->Link = NULL;
    }while(fscanf(file, "%ld, %d, %49[^,], %49[^,], %49[^,], %d, %49[^,], %d, %49[^,], %d, %49[^,],"
                        "%d, %49[^,], %d, %49[^,], %d, %49[^,], %lf, %49[^,], %lf,\n",
                  &current->Data.Student.ID,&current->Data.Student.Age,current->Data.Student.Name,
                  current->Data.Student.Password,current->Data.Student.Gender,
                  &current->Data.Subject.DigitalCircuits.Degree,current->Data.Subject.DigitalCircuits.Rate,
                  &current->Data.Subject.ControlSystem.Degree,current->Data.Subject.ControlSystem.Rate,
                  &current->Data.Subject.DataStructure.Degree,current->Data.Subject.DataStructure.Rate,
                  &current->Data.Subject.Electronics.Degree,current->Data.Subject.Electronics.Rate,
                  &current->Data.Subject.Programming.Degree,current->Data.Subject.Programming.Rate,
                  &current->Data.Subject.Measurements.Degree,current->Data.Subject.Measurements.Rate,
                  &current->Data.TotalDegree,current->Data.TotalGrade,&current->Data.GPA) > 0 && (ptr = AddNewNode(ptr,current->Data)));
    fclose(file);
}
