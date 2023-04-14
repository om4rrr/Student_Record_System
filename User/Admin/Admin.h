#ifndef ADMIN_H
#define ADMIN_H

#include "../../Linked_List/Linked_List.h"
#include "../../Libraries/Libraries.h"
#include "../../Linked_List/Struct.h"
#include "../../Program/Validation/Validation.h"
#include "../../Program/Program.h"
#include "../../Filehandling/Filehandling.h"


char *EditAdminName(AdminNode *Head,long ID);

char *EditAdminPassword(AdminNode *Head,long ID);

void  ChooseAdminFeatures(AdminNode *AdminHead, StudentNode **StudentHead,long ID);

void AdminMode(AdminNode *AdminHead,StudentNode **StudentHead);


#endif


