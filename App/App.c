#include "App.h"

// Start App


void StartApp(StudentNode **StudentHead, AdminNode *AdminHead){
    while(1){
        int choice = ChooseModeValidate();
        bool EOP = false;
        switch (choice) {
            case 1: StudentMode(*StudentHead); break;
            case 2: AdminMode(AdminHead,StudentHead);break;
            case 3: EOP = true;    break;
        }
        if(EOP) break;
    }
}
