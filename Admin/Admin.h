#ifndef ADMIN_H
#define ADMIN_H

#include "../Libraries/Libraries.h"
#include "../Struct/Struct.h"
#include "../Linked_List/Linked_List.h"
#include "../Validation/Validation.h"
#include "../Program/Program.h"

char *EditAdminName(AdminNode *Head,long ID);

char *EditAdminPassword(AdminNode *Head,long ID);

void  ChooseAdminFeatures(AdminNode *AdminHead, StudentNode **StudentHead,long ID);

void AdminMode(AdminNode *AdminHead,StudentNode **StudentHead);


#endif


