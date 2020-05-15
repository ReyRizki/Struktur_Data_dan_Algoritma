#ifndef CAR_H_
#define CAR_H_

#include <string.h>

typedef struct {
    char name[10];
    char code[3];
    int timeSize;
    int arrivalTime;
    int services;
    int finish;
} Car;

void carInput(Car *c);

void carPrint(Car c);

void carWash(Car *c, int *time);

void washDelay(int *time);

int carTimeSize(Car c);

#endif