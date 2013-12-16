#pragma once

namespace LeapClient
{

class LeapGestureManager
{
public:
	LeapGestureManager(void);
	~LeapGestureManager(void);
private:
	int gestureCount;
public:
	vector<LeapGesture> gesture_list;
	LeapComm gesture_comm;
	int registerGesture(void);
	int gestureType(void);
};

}