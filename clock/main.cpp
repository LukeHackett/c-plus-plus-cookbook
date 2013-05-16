#include <iostream>
#include "clock.h"

using namespace std;

int main()
{ 
  // hours and minutes
  int hrs, min;

  // obtain the hour value
  cout << "Please enter the hour value:" << endl;
  cout << "> ";
  cin >> hrs;

  // obtain the minute value
  cout << "Please enter the minute value:" << endl;
  cout << "> ";
  cin >> min;

  // Setup a new Clock object
  Clock *c = new Clock(hrs, min);

  // Increment the time by 1 hour for testing purposes
  cout << "Incrementing the time by 60 minutes." << endl;
  for(int i = 0; i < 60; i++)
  {
    c->incrementClock();
    cout << "The time is now " << c->toString() << endl;
  }

  return 0;
}