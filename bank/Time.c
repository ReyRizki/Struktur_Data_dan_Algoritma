#include "Time.h"

void MakeTIME (TIME *J, int HH, int MM, int SS)
{
    (*J).Hour = HH;
    (*J).Minute = MM;
    (*J).Second = SS;
}

TIME createTime(int hour, int minute, int second)
{
    TIME time;
    
    time.Hour = hour;
    time.Minute = minute;
    time.Second = second;

    return time;
}

int GetHour(TIME J)
{
    return J.Hour;
}

int GetMinute(TIME J)
{
    return J.Minute;
}

int GetSecond(TIME J)
{
    return J.Second;
}

void SetHour(TIME *J, int newHour)
{
    (*J).Hour = newHour;
    calibrate(J);
}

void SetMinute(TIME *J, int newMinute)
{
    (*J).Minute = newMinute;
    calibrate(J);
}

void SetSecond(TIME *J, int newSecond)
{
    (*J).Second = newSecond;
    calibrate(J);
}

void calibrate(TIME *J)
{
    if ((*J).Second >= 60)
    {
        (*J).Minute++;
        (*J).Second -= 60;
    }

    if ((*J).Minute >= 60)
    {
        (*J).Hour++;
        (*J).Minute -= 60;
    }

    if ((*J).Hour >= 24)
        (*J).Hour = 0;
}

void ReadTIME (TIME *J)
{
    TIME new;
    do
    {
        scanf("%d %d %d", &new.Hour, &new.Minute, &new.Second);
    } while (!IsJValid(new.Hour, new.Minute, new.Second));

    *J = new;
}

void PrintTIME (TIME J)
{
    printf("%d:%d:%d", J.Hour, J.Minute, J.Second);
}

bool IsJValid (int H, int M, int S)
{
    return ((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59));
}

bool JEQ(TIME J1, TIME J2)
{
    return (J1.Hour == J2.Hour) && (J1.Minute == J2.Minute) && (J1.Second == J2.Second);
}

bool JNEQ(TIME J1, TIME J2)
{
    return !JEQ(J1, J2);
}

bool JLT(TIME J1, TIME J2)
{
    if (JNEQ(J1, J2))
    {
        if (J1.Hour > J2.Hour)
            return false;
        else if (J1.Hour < J2.Hour)
            return true;
        else
        {
            if (J1.Minute > J2.Minute)
                return false;
            else if (J1.Minute < J2.Minute)
                return true;
            else
            {
                if (J1.Second > J2.Second)
                    return false;
                else
                    return true;
            }
        }
    }
    else
        return false;
}

bool JGT(TIME J1, TIME J2)
{
    return JNEQ(J1, J2) && !JLT(J1, J2);
}

TIME NextDetik (TIME J)
{
    J.Second += 1;
    if (J.Second == 60)
    {
        J.Minute += 1;
        J.Second = 0;
    }

    if (J.Minute == 60)
    {
        J.Hour += 1;
        J.Minute = 0;
    }

    if (J.Hour == 24)
        J.Hour = 0;

    return J;
}

TIME PrevDetik (TIME J)
{
    J.Second -= 1;

    if (J.Second == -1)
    {
        J.Minute -= 1;
        J.Second = 59;
    }

    if (J.Minute == -1)
    {
        J.Hour -= 1;
        J.Minute = 59;
    }

    if (J.Hour == -1)
        J.Hour = 23;

    return J;
}

TIME JPlus(TIME J1, TIME J2)
{
    TIME J;
    J.Second = J1.Second + J2.Second;
    J.Minute = J1.Minute + J2.Minute;
    J.Hour = J1.Hour + J2.Hour;

    if (J.Second >= 60)
    {
        J.Minute++;
        J.Second -= 60;
    }

    if (J.Minute >= 60)
    {
        J.Hour++;
        J.Minute -= 60;
    }

    if (J.Hour >= 24)
        J.Hour = 0;

    return J;
}

TIME JMinus(TIME J1, TIME J2)
{
    TIME J;
    J.Second = J1.Second - J2.Second;
    J.Minute = J1.Minute - J2.Minute;
    J.Hour = J1.Hour - J2.Hour;

    if (J.Second < 0)
    {
        J.Minute--;
        J.Second += 60;
    }

    if (J.Minute < 0)
    {
        J.Hour--;
        J.Minute += 60;
    }

    if (J.Hour < 0)
        J.Hour += 24;

    return J;
}

TIME NextNDetik (TIME J, int N)
{
    J.Second += N;

    if (J.Second >= 60)
    {
        J.Minute++;
        J.Second -= 60;
    }

    if (J.Minute >= 60)
    {
        J.Hour++;
        J.Minute -= 60;
    }

    if (J.Hour >= 24)
        J.Hour = 0;

    return J;
}

TIME PrevNDetik (TIME J, int N)
{
    J.Second -= N;

    if (J.Second < 0)
    {
        J.Minute--;
        J.Second += 60;
    }

    if (J.Minute < 0)
    {
        J.Hour--;
        J.Minute += 60;
    }

    if (J.Hour < 0)
        J.Hour += 24;

    return J;
}

long int Durasi (TIME Jaw , TIME JAkh)
{
    return TimeToDetik(JAkh) - TimeToDetik(Jaw);
}

long int TimeToDetik (TIME J)
{
    return 3600 * J.Hour + 60 * J.Minute + J.Second;
}

TIME DetikToTIME (long int N)
{
    TIME J;

    J.Hour = N / 3600;
    N %= 3600;

    J.Minute = N/60;
    N %= 60;

    J.Second = N;

    return J;
}