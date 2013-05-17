/******************************************************************************
 *  Copyright 2013 Luke Hackett
 *  https://github.com/LukeHackett/
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *****************************************************************************/

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

  // decrement the time by 1 hour for testing purposes
  cout << endl << "Decrement the time by 60 minutes." << endl;
  for(int i = 0; i < 60; i++)
  {
    c->decrementClock();
    cout << "The time is now " << c->toString() << endl;
  }

  
  return 0;
}