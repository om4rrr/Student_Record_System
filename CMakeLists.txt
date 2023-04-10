cmake_minimum_required(VERSION 3.24)
project(Student_Record_System C)

set(CMAKE_C_STANDARD 99)

add_executable(Student_Record_System main.c Program/Program.c Filehandling/Filehandling.c Validation/Validation.c Student/Student.c Linked_List/Linked_List.c)
