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
    int cooldown;
} Car;

void carInput(Car *c);

void carPrint(Car c);

void carWash(Car *c, int *time);

void washDelay(int *time, int cooldown);

int carTimeSize(Car c);

int carCooldown(Car c);

#endif