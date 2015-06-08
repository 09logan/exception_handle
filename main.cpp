#include <iostream>
#include "MyTime.h"
#include "OutOfRangeException.h"
using namespace std;

int main()
{
    int hour,minute,second,choice;
    MyTime time;
    cout << "Enter time in hour:Minute:Second format ";
    while(cin>>hour>>minute>>second)
        {
           try
            {
                time.setTime(hour,minute,second);
                break;
            }

            catch (OutOfRangeException &OutOfRangeException){
            cout << "Invalid Entry !!! " << OutOfRangeException.what() << endl;
            }
        }

        int entry;
        cout <<"\n\nEntering into choice menu mode\n";
        cout <<"Enter 1 for after-time and 0 for before-time\n";
        cin>>choice;
        if (choice==1)
        {
            cout <<"Enter 1 for hour,2 for minute and 3 for second\n";
            cin>>entry;
            switch (entry)
            {
           case 1:
               {
                   time.nextHour();
                   cout << "\nAfter one hour, time will be   ->" << time.toString() << endl;
                   break;
               }

           case 2:
               {
                   time.nextMinute();
                   cout << "\nAfter one minute, time will be ->" << time.toString() << endl;
                   break;
               }


           case 3:
               {
                   time.nextSecond();
                   cout << "\nAfter one second, time will be ->" << time.toString() << endl;
                   break;
               }

               }
        }
        else if(choice==0)
        {

            cout <<"Enter 1 for hour,2 for minute and 3 for second\n";
            cin>>entry;
            switch (entry)
            {
                case 1:
                    {
                        time.previousSecond();
                        cout << "\nBefore one second, time was    ->" << time.toString() << endl;
                         break;

                    }

                case 2:
                    {
                        time.previousMinute();
                        cout << "\nBefore one minute, time was    ->" << time.toString() << endl;
                        break;
                    }

                case 3:
                    {
                        time.previousSecond();
                        cout << "\nBefore one second, time was    ->" << time.toString() << endl;
                        break;
                    }

             }
        }
        else
            cout<<"Invalid entry ,Better luck next time :D";

}

