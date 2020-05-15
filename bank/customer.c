// Program		: customer.c
// Author		: Rey Rizki
// Description	: Costumer ADT body implementation file
// Date			: Saturday, 18 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "customer.h"

Customer createCustomer(char purpose, TIME arrivalTime, u int duration)
{
    Customer customer;
    
    customer.arrivalTime = arrivalTime;
    customer.duration = duration;
    customer.purpose = purpose;

    return customer;
}

void scanCustomer(Customer *customer)
{
    char special;
    scanf("%c%c", &special, &(customer->purpose));
    ReadTIME(&(customer->arrivalTime));
    scanf("%u", &(customer->duration));
}

void printCustomer(Customer customer)
{
    printf("%c ", customer.purpose);
    PrintTIME(customer.arrivalTime);
    printf(" %u\n", customer.duration);
}