#ifndef CAR_H_
#define CAR_H_

#include <string.h>
#include "Time.h"

typedef struct {
    char name[10];
    char code[3];
    int timeSize;
    TIME arrivalTime;
    TIME services;
    TIME finish;
    int cooldown;
} Car;

void carInput(Car *c);

void carPrint(Car c);

void carWash(Car *c, TIME *time);

void washDelay(TIME *time, int cooldown);

int carTimeSize(Car c);

int carCooldown(Car c);

#endif