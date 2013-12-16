#pragma once

namespace LeapClient
{

class LeapGesture
{
public:
	LeapGesture(void);
	~LeapGesture(void);
	virtual int recognize(void);
	bool isRightHand(void);
private:
	bool is_right_hand;
	int forefinger_id;
};

}