// Program		: staff.c
// Author		: Rey Rizki
// Description	: Staff ADT body implementation file
// Date			: Saturday, 18 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "staff.h"

Staff createStaff(TIME available, bool serving, u int count)
{
    Staff staff;
    
    staff.available = available;
    staff.serving = serving;
    staff.count = count;

    return staff;
}

void assignStaff(Staff *staff, TIME time)
{
    staff->available = time;
    staff->serving = 1;
    staff->count++;
}

void printStaff(Staff staff)
{
    PrintTIME(staff.available);
    printf("\n%d %u\n", staff.serving, staff.count);
}
