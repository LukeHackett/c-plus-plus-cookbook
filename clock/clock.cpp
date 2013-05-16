#include <string>
#include <sstream>
#include "clock.h"

using namespace std;


/**
 * Default Constructor
 */
Clock::Clock()
{
  // provide some defaults
  hour = 0;
  minute = 0;
}

/**
 * Additional Constructor
 *
 * @param  newHour    the inital hour value of the clock
 * @param  newMinute  the inital minute value of the clock
 */
Clock::Clock(int newHour, int newMinute)
{ 
  // provide some defaults
  hour = 0;
  minute = 0;

  // Set the time to the desired amount(if valid)
  setHour(newHour);
  setMinute(newMinute);
}

/**
 * This method will set the hour of the clock. For an update to be accepted, 
 * the hour must be between 0 and 23 (inclusive). All values outside this will 
 * be ignored.
 *
 * @param  newHour  the value of the minute hand
 */
void Clock::setHour(int newHour)
{
  if(newHour >= 0 && newHour <= 23)
    hour = newHour;
}

/**
 * This method will set the minute of the clock. For an update to be accepted, 
 * the minute must be between 0 and 59 (inclusive). All values outside this 
 * will be ignored.
 *
 * @param  newminute  the value of the minute hand
 */
void Clock::setMinute(int newMinute)
{
  if(newMinute >= 0 && newMinute <= 59)
    minute = newMinute;
}

/**
 * This method will return the current hour value
 *
 * @return int
 */
int Clock::getHour()
{
  return hour;
}

/**
 * This method will return the current minute value
 *
 * @return int
 */
int Clock::getMinute()
{
  return minute;
}

/**
 * This method will return the current hour value as a string
 *
 * @return string
 */
string Clock::getHourString()
{
  // Convert the hour int to an hour string
  string str = static_cast<ostringstream*>(&(ostringstream() << hour))->str();

  // Add the trailing 0 to the hour if needed
  if(hour < 10)
    str = "0" + str;

  return str;
}

/**
 * This method will return the current minute value as a string
 *
 * @return string
 */
string Clock::getMinuteString()
{
  // Convert the minute int to a minute string
  string str = static_cast<ostringstream*>(&(ostringstream() << minute))->str();

  // Add the trailing 0 to the minute if needed
  if(minute < 10)
    str = "0" + str;

  return str;
}

/**
 * This method will increment the entire clock. If the minute value will cause
 * the hour value to increment, then the hour will be incremented at the same 
 * time.
 */
void Clock::incrementClock()
{ 
  // Increment the hour if the minute will 'tick over'
  if(minute == 59)
  {
    incrementHour();
  }

  // Increment the minute by default
  incrementMinute();  
}

/**
 * This method will increment the hour value only using a 24 hour clock.
 */
void Clock::incrementHour()
{
  if(hour == 23)
    hour = 0;
  else
    hour += 1;
}

/**
 * This method will increment the minute value only.
 */
void Clock::incrementMinute()
{
  if(minute == 59)
    minute = 0;
  else
    minute += 1;
}

/**
 * This method will decrement the entire clock. If the minute value will cause
 * the hour value to decrement, then the hour will be decremented at the same 
 * time.
 */
void Clock::decrementClock()
{
  // decrement the hour if the minute will 'tick over'
  if(minute == 0)
  {
    decrementHour();
  }

  // Increment the minute by default
  decrementMinute();  
}

/**
 * This method will decrement the hour value only.
 */
void Clock::decrementHour()
{
  if(hour == 0)
    hour = 23;
  else
    hour -= 1;
}

/**
 * This method will decrement the minute value only.
 */
void Clock::decrementMinute()
{
  if(minute == 0)
    minute = 59;
  else
    minute -= 1;
}

/**
 * This method will return a string representation of the current state of the
 * object.
 *
 * @return string
 */
string Clock::toString()
{ 
  return getHourString() + ":" + getMinuteString();
}