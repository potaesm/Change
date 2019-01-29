#ifndef Change_h
#define Change_h
#include "Arduino.h"

class Change {

  public:

    Change();
    void IntervalSet(int input_interval);
    void ThresholdSet(int input_threshold);
    bool IsChange(int input_value);
    bool IsReach(int input_value, int input_threshold);
    
  private:

	long interval = 200;
	int threshold = 600;
	int previousValue = 0;
	long previousMillis = 0;
	bool changed = false;
  bool reached = false;
  bool checkReach = false;
	
};

#endif

    