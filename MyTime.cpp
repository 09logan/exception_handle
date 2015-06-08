#include <iostream>
#include "MyTime.h"
#include "OutOfRangeException.h"
#include <sstream>
using namespace std;

MyTime::MyTime(){
}

MyTime::MyTime(int hour, int minute, int second)
{
    setTime(hour,minute,second);
}


void MyTime::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);

}

int MyTime::getHour()
{
    return hour;
}

int MyTime::getMinute()
{
    return minute;

}

int MyTime::getSecond()
{
    return second;
}

void MyTime::setHour(int hour)
{
    if(hour>=0 && hour <=23)
    {
        this->hour = hour;
    }
    else
    {
        throw OutOfRangeException ("Hours value  must be between 0 to 24. Please enter another value: ");
    }
}

void MyTime::setMinute(int minute)
{
    if(minute>=0 && minute<=59)
    {
        this->minute = minute;
    }
    else
    {
        throw OutOfRangeException ("Minutes value must be between 0 to 59. Please enter another value: ");
    }
}

void MyTime::setSecond(int second)
{
    if(second>=0 && second<=59)
    {
        this->second = second;
    }
    else
    {
        throw OutOfRangeException ("Seconds value must be between 0 to 59. Please enter another value: ");
    }
}

string MyTime::toString()
{
    stringstream hour, minute, second;
    hour << getHour();
    minute << getMinute();
    second << getSecond();
    return  hour.str() + ":" + minute.str() + ":" + second.str();

}

MyTime MyTime::nextSecond()
{
    if(second == 59)
    {
        setSecond(0);
        minute++;
        if(minute ==60 )
            setMinute(0);
        hour++;
        if(hour == 24)
            setHour(0);
    }
    else
        setSecond(second++);

    return MyTime();
}

MyTime MyTime::nextMinute()
{
   if(minute == 59)
    {
        setMinute(0);
        hour++;
        if(hour == 24)
            setHour(0);
    }
    else
        setMinute(minute++);

    return MyTime();


}

MyTime MyTime::nextHour()
{
   if(hour == 24)
    {
        setHour(0);
    }
    else
        setHour(hour++);

    return MyTime();


}

MyTime MyTime::previousSecond()
{
    if(second == 0)
    {
        setSecond(59);
        minute--;
        if(minute == -1)
            setMinute(59);
        hour--;
        if(hour == -1)
            setHour(23);
    }
    else
        setSecond(second--);

        return MyTime();
}

MyTime MyTime::previousMinute()
{
    if(minute == 0)
    {
        setMinute(59);
        hour--;
        if(hour == -1)
            setHour(23);
    }
    else
        setMinute(minute--);

    return MyTime();


}

MyTime MyTime::previousHour()
{
    if(--hour == -1)
    {
        setHour(23);
    }
    else
        setHour(hour--);

    return MyTime();
}
