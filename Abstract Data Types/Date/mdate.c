#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main()
{
    DATE D1, D2;
    
    BacaDate(&D1);
    BacaDate(&D2);

    SelisihDate(D1, D2);
}