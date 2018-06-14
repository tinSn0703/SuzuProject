
#pragma once

typedef IO::ModeBitIn Sensor;
typedef Sensor LimitSensor;
typedef Sensor PhotoSensor;

typedef IO::ModeBitOut LED;
typedef IO::ModeBitOut Vacuum;

typedef FourOmuni Mechanum;

class TimerCounter
{
public:
	
	TimerCounter();
	
	YesNo Is_finish_wait(YesNo _is_start, mSecond _wait_time);
	
private:
	
	CountValue _timer;
};
