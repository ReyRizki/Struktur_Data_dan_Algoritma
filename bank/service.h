#ifndef SERVICE_H_
#define SERVICE_H_

#include "staff.h"
#include "dynamicQueue.h"

typedef struct
{
    Staff *staffs;
    Queue queue;
    u int staffNumber;
} Service;

Service createService(u int n);
bool areQueuesEmpty(Service *service);

void unassignStaffs(Service *services, TIME time);

#endif