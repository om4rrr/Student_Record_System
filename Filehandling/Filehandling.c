#include "Filehandling.h"

// Writing to Student file

void WriteToStudentFile(StudentNode* ptr) {
    FILE* file = fopen("StudentDatabase.txt", "w");
    if (file == NULL) { printf("Unable to write"); exit(1); }

    StudentNode* current = NULL;
    current = ptr;
    while(current != NULL)
    {
        fprintf(file,"%ld, %s, %ld, %d, %s, %s, %s, %s, %d, %s, %d, %s, %d, %s, %d, %s, %d, %s, %d, %s, %lf, %s, %lf,\n",
                current->Data.Student.ID,current->Data.Student.NationalID,current->Data.Student.PhoneNumber,
                current->Data.Student.Age,current->Data.Student.Name,current->Data.Student.Password,
                current->Data.Student.Gender,current->Data.Student.Mail,
                current->Data.Subject.DigitalCircuits.Degree,current->Data.Subject.DigitalCircuits.Rate,
                current->Data.Subject.ControlSystem.Degree  ,current->Data.Subject.ControlSystem.Rate,
                current->Data.Subject.DataStructure.Degree  ,current->Data.Subject.DataStructure.Rate,
                current->Data.Subject.Electronics.Degree    ,current->Data.Subject.Electronics.Rate,
                current->Data.Subject.Programming.Degree    ,current->Data.Subject.Programming.Rate,
                current->Data.Subject.Measurements.Degree   ,current->Data.Subject.Measurements.Rate,
                current->Data.TotalDegree,current->Data.TotalGrade,current->Data.GPA);

        current = current->Link;
    }
    fclose(file);
    free(current);
    current = NULL;
}

// Read from Student file

void ReadStudentFile(StudentNode **ptr) {

    FILE* file = fopen("StudentDatabase.txt", "r");
    if (file == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }
    StudentNode *current = NULL;
    current = (StudentNode *)malloc(sizeof(StudentNode));
    do{
        current->Data.Student.NationalID     = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Student.Name     = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Student.Password = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Student.Mail     = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Student.Gender   = malloc(7*sizeof(char));
        current->Data.TotalGrade       = malloc(2*sizeof(char));
        current->Data.Subject.DigitalCircuits.Rate  = malloc(2*sizeof(char));
        current->Data.Subject.DataStructure.Rate    = malloc(2*sizeof(char));
        current->Data.Subject.ControlSystem.Rate    = malloc(2*sizeof(char));
        current->Data.Subject.Electronics.Rate      = malloc(2*sizeof(char));
        current->Data.Subject.Programming.Rate      = malloc(2*sizeof(char));
        current->Data.Subject.Measurements.Rate     = malloc(2*sizeof(char));

    }while(fscanf(file, "%ld, %49[^,], %ld, %d, %49[^,], %49[^,], %49[^,], %49[^,], %d, %49[^,], %d, %49[^,], %d, %49[^,],"
                        "%d, %49[^,], %d, %49[^,], %d, %49[^,], %lf, %49[^,], %lf,\n",
                  &current->Data.Student.ID,current->Data.Student.NationalID,&current->Data.Student.PhoneNumber,
                  &current->Data.Student.Age,current->Data.Student.Name,current->Data.Student.Password,
                  current->Data.Student.Gender,current->Data.Student.Mail,
                  &current->Data.Subject.DigitalCircuits.Degree,current->Data.Subject.DigitalCircuits.Rate,
                  &current->Data.Subject.ControlSystem.Degree  ,current->Data.Subject.ControlSystem.Rate,
                  &current->Data.Subject.DataStructure.Degree  ,current->Data.Subject.DataStructure.Rate,
                  &current->Data.Subject.Electronics.Degree    ,current->Data.Subject.Electronics.Rate,
                  &current->Data.Subject.Programming.Degree    ,current->Data.Subject.Programming.Rate,
                  &current->Data.Subject.Measurements.Degree   ,current->Data.Subject.Measurements.Rate,
                  &current->Data.TotalDegree,current->Data.TotalGrade,&current->Data.GPA) > 0 &&  AddStudentNode(ptr,current->Data));
    fclose(file);
    free(current);
    current = NULL;

}

// Writing to Admin file

void WriteToAdminFile(AdminNode* ptr) {
    FILE* file = fopen("AdminDatabase.txt", "w");
    if (file == NULL) { printf("Unable to write"); exit(1); }

    AdminNode *current = NULL;
    current = ptr;
    while(current != NULL)
    {
        fprintf(file,"%ld, %s, %ld, %d, %s, %s, %s, %s,\n",
                current->Data.ID,current->Data.NationalID,current->Data.PhoneNumber,
                current->Data.Age,current->Data.Name,current->Data.Password,
                current->Data.Gender,current->Data.Mail);

        current = current->Link;
    }
    fclose(file);
    free(current);
    current = NULL;
}

// Read from Admin file

void ReadAdminFile(AdminNode **ptr) {

    FILE* file = fopen("AdminDatabase.txt", "r");
    if (file == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }


    AdminNode *current = NULL;
    current = (AdminNode *)malloc(sizeof(AdminNode));
    do{
        current->Data.NationalID = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Name       = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Password   = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Mail       = malloc(MAX_STRING_LENGTH*sizeof(char));
        current->Data.Gender     = malloc(7*sizeof(char));

    }while(fscanf(file, "%ld, %49[^,], %ld, %d, %49[^,], %49[^,], %49[^,], %49[^,],\n",
                  &current->Data.ID,current->Data.NationalID,&current->Data.PhoneNumber,
                  &current->Data.Age,current->Data.Name,current->Data.Password,
                  current->Data.Gender,current->Data.Mail) > 0 &&  AddAdminNode(ptr,current->Data));
    fclose(file);
    free(current);
    current = NULL;
}