#include <string>
using namespace std;

class Clock
{
public:
  Clock();
  Clock(int hour, int minute);

  ~Clock();

  void setHour(int hour);
  void setMinute(int minute);

  int getHour();
  int getMinute();

  string getHourString();
  string getMinuteString();

  void incrementClock();
  void decrementClock();

  string toString();
private:
  int hour;
  int minute;

  void incrementHour();
  void incrementMinute();

  void decrementHour();
  void decrementMinute();
};