cmake_minimum_required(VERSION 3.24)
project(Student_Record_System C)

set(CMAKE_C_STANDARD 99)

add_executable(Student_Record_System App/main.c Program/Program.c Filehandling/Filehandling.c Program/Validation/Validation.c User/Student/Student.c Linked_List/Linked_List.c User/Admin/Admin.c App/App.c App/App.h)
