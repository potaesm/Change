#include "Arduino.h"
#include "Change.h"

Change::Change() {

}

void Change::IntervalSet(int input_interval) {
	interval = input_interval;
}

void Change::ThresholdSet(int input_threshold) {
	threshold = input_threshold;
}

bool Change::IsChange(int input_value) {
	changed = false;
	unsigned long currentMillis = millis();
	unsigned int currentValue = input_value;
	if (currentMillis - previousMillis > interval) {
		if (abs(currentValue - previousValue) >= threshold) {
			changed = true;
			previousValue = currentValue;
		}
	previousMillis = currentMillis;
	}
	return(changed);
}

bool Change::IsReach(int input_value, int input_threshold) {
	reached = false;
	if (IsChange(input_value) && input_value >= input_threshold) {
		reached = true;
	}
	return(reached);
}