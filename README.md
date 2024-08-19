# Student Record System

## Overview

The Student Record System is a C-based application designed to manage and maintain student records. It has Admin mode and Student mode. It supports adding, modifying, deleting, and retrieving student data.

## Video Demonstration

Watch the video for a demonstration of the Student Record System:

[Watch the video on Google Drive](https://drive.google.com/file/d/1BEloE4FKND3Jvtgly2Qz8zsb2glRNj-y/view?usp=sharing)


## Features

- **Student Features**:
  - **View Own Records**: Students can retrieve their own records using their unique student ID and password.
  - **Edit Own Information**: Students can update their personal information.
  
- **Administrator Features**:
  - **Add New Student**: Administrators can add new student records with details like name, ID, Notional ID, and contact information.
  - **View Specific Student Record**: Administrators can search for and view the records of individual students using their ID.
  - **View All Records**: Administrators can view a complete list of all student records.
  - **Delete Student**: Administrators can remove student records from the system.
  - **Edit Own Information**: Administrators can update their personal information.

## File Handling
- **Overview**
  - This project uses file handling to manage student and admin data. The system maintains separate files for students and administrators to ensure data is organized and easily accessible.

 - **Student Data File**:
   - **Filename**: StudentDatabase.txt
   - **Description**: This file stores student ID, name, password, age, gender, Notional ID, contact information and his grades.
 - **Admin Data File**:
   - **Filename**: AdminDatabase.txt
   - **Description**: This file stores admin ID, name, password, age, gender, Notional ID and contact information.

## Installation

1. **Clone the Repository**:

   ```sh
   git clone https://github.com/om4rrr/Student_Record_System.git
