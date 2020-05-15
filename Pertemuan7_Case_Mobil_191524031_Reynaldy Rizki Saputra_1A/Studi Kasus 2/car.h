#ifndef CAR_H_
#define CAR_H_

typedef struct {
    char name[10];
    int timeSize;
    int arrivalTime;
    int services;
    int finish;
} Car;

void carInput(Car *c);

void carPrint(Car c);

void carWash(Car *c, int *time);

void washDelay(int *time);

#endif