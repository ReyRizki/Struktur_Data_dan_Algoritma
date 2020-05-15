// Program		: staff.h
// Author		: Rey Rizki
// Description	: Staff ADT header file
// Date			: Saturday, 18 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef STAFF_H
#define STAFF_H

#include "Time.h"

typedef struct
{
    TIME available;
    bool serving;
    u int count;
} Staff;

Staff createStaff(TIME available, bool serving, u int count);
void assignStaff(Staff *staff, TIME time);
void printStaff(Staff staff);

#endif