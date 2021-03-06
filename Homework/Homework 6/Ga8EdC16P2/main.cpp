#include <iostream>
#include "time.h"
#include "miltime.h"
using namespace std;

int main()
{
    int mt;
    int se;
    
    cout << "Enter the time in military format" << endl;
    cin >> mt;
   
    cout << "Enter the seconds" << endl;
    cin >> se;
    
    try
    {
    milTime mil(mt, se);
    cout << "Military time: " << mil.getHours() << ":" << mil.getSec() << endl;
    cout << "Standard time: " << mil.getStandHr() << ":" << mil.getMin() << ":" << mil.getSec() << endl;
    }
    catch(milTime::badHour)
    {
        cout << "Error, invalid hour" << endl;
    }
    catch(milTime::badSecond)
    {
        cout << "Error, invalid second" << endl;
    }
    return 0;
}

void milTime::setTime(int h, int s)
{
    if(h < 0 || h > 2359)
        throw badHour();
    else
        milHours = h;
    if(s < 0 || s > 59)
        throw badSecond();
    else
        milSeconds = s;
}

int milTime::getStandHr()
{
    int hr = getHour(); 
    switch(hr)
    {
        case 13: 
            hr = 1; break;
        case 14: 
            hr = 2; break;
        case 15: 
            hr = 3; break;
        case 16: 
            hr = 4; break;
        case 17: 
            hr = 5; break;
        case 18: 
            hr = 6; break;
        case 19: 
            hr = 7; break;
        case 20: 
            hr = 8; break;
        case 21: 
            hr = 9; break;
        case 22: 
            hr = 10; break;
        case 23: 
            hr = 11; break;
        case 0: 
            hr = 12; break;
    }
    return hr;
}