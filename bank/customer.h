// Program		: customer.h
// Author		: Rey Rizki
// Description	: Costumer ADT header file
// Date			: Saturday, 18 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Time.h"

typedef struct
{
    char purpose;
    TIME arrivalTime;
    u int duration;
} Customer;

Customer createCustomer(char purpose, TIME arrivalTime, u int duration);

void scanCustomer(Customer *customer);
void printCustomer(Customer customer);

#endif