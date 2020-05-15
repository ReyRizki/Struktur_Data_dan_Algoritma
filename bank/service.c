#include "service.h"

Service createService(u int n)
{
    Service service;
    u int i;

    service.staffNumber = n;
    service.staffs = (Staff *) malloc(service.staffNumber * sizeof(Staff));
    
    REP(i, 0, service.staffNumber)
        *(service.staffs + i) = createStaff(createTime(0, 0, 0), 0, 0);

    service.queue = createQueue();

    return service;
}

bool areQueuesEmpty(Service *service)
{
    u int i;
    REP(i, 0, 2)
        if (not isQueueEmpty((service+i)->queue))
            return 0;

    return 1;
}

void unassignStaffs(Service *services, TIME time)
{
    u int i, j;

    REP(i, 0, 2)
    {
        Staff *current = (services + i)->staffs;
        REP(j, 0, (services + i)->staffNumber)
            if ((JGT(time, (current + j)->available) or JEQ(time, (current + j)->available)) and ((current + j)->serving == 1))
                (*(current + j)).serving = 0;
    }
}