#include <stdio.h>
#include <stdlib.h>
#include "date.h"

void MakeDate(DATE *D)
{
    (*D).Tgl = 1;
    (*D).Bln = 1;
    (*D).Thn = 1900;
}

DATE CreateDate(int Tanggal, int Bulan, int Tahun)
{
    DATE D;

    D.Tgl = Tanggal;
    D.Bln = Bulan;
    D.Thn = Tahun;

    return D;
}

int GetTgl(DATE D)
{
    return D.Tgl;
}

int GetBln(DATE D)
{
    return D.Bln;
}

int GetThn(DATE D)
{
    return D.Thn;
}

void SetTgl(int NewTgl, DATE *D)
{
    (*D).Tgl = NewTgl;
}

void SetBln(int NewBln, DATE *D)
{
    (*D).Bln = NewBln;
}

void SetThn(int NewThn, DATE *D)
{
    (*D).Thn = NewThn;
}

void BacaDate(DATE *D)
{
    int tgl, bln, thn;
    do
    {
        scanf("%d %d %d", &tgl, &bln, &thn);

        SetTgl(tgl, &(*D));
        SetBln(bln, &(*D));
        SetThn(thn, &(*D));
    } while (!isValid(*D));
}

boolean isValid(DATE D)
{
    if ((GetBln(D) < 1) || (GetBln(D) > 12))
        return false;

    if ((GetTgl(D) < 1) || (GetTgl(D) > 31))
        return false;

    switch (GetBln(D))
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (GetTgl(D) > 31)
            return false;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if (GetTgl(D) > 30)
            return false;
        break;

    case 2:
        if (GetThn(D) % 4 == 0)
        {
            if (GetTgl(D) > 29)
                return false;
        }
        else
        {
            if (GetTgl(D) > 28)
                return false;
        }
        break;

    default:
        break;
    }

    return true;
}

void PrintDate(DATE D)
{
    printf("%d/%d/%d\n", GetTgl(D), GetBln(D), GetThn(D));
}

boolean isKabisat(DATE D)
{
    return (GetTgl(D) == 29) && (GetBln(D) == 2) && (GetThn(D) % 4 == 0);
}

int TglAkhir(DATE D)
{
    switch (GetBln(D))
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
        if (GetThn(D) % 4 == 0)
            return 29;
        else
            return 28;
        break;
    }
}

void DateBefore(DATE D)
{
    SetTgl(GetTgl(D) - 1, &D);
    if (GetTgl(D) == 0)
    {
        SetBln(GetBln(D) - 1, &D);
        if (GetBln(D) == 0)
        {
            SetThn(GetThn(D) - 1, &D);
            SetBln(12, &D);
        }
        SetTgl(TglAkhir(D), &D);
    }

    PrintDate(D);
}

void NextDate(DATE D)
{
    SetTgl(GetTgl(D) + 1, &D);
    if (GetTgl(D) > TglAkhir(D))
    {
        SetBln(GetBln(D) + 1, &D);
        if (GetBln(D) == 13)
        {
            SetThn(GetThn(D) + 1, &D);
            SetBln(1, &D);
        }
        SetTgl(1, &D);
    }

    PrintDate(D);
}

void SelisihDate(DATE D1, DATE D2)
{
    int diff;
    int convert = 0;

    if (GetThn(D1) > GetThn(D2))
    {
        swapDate(&D1, &D2);
    }
    else if (GetThn(D1) == GetThn(D2))
    {
        if (GetBln(D1) > GetBln(D2))
        {
            swapDate(&D1, &D2);
        }
        else if (GetBln(D1) == GetBln(D2))
        {
            if (GetTgl(D1) > GetTgl(D2))
            {
                swapDate(&D1, &D2);
            }
        }
    }

    while ((GetThn(D1) != GetThn(D2)) || (GetBln(D1) != GetBln(D2)))
    {
        SetBln(GetBln(D2)-1, &D2);
        convert += TglAkhir(D2);
        if (GetBln(D2) == 0)
        {
            SetThn(GetThn(D2)-1, &D2);
            SetBln(12, &D2);
        }
    }
    convert += GetTgl(D2);

    diff = convert - GetTgl(D1);
    printf("%d\n", diff);
}

void swapDate(DATE *D1, DATE *D2)
{
    DATE temp;

    temp = *D1;
    *D1 = *D2;
    *D2 = temp;
}