#pragma once
#include "leapgesture.h"

namespace LeapClient
{

class Tracking :
	public LeapGesture
{
public:
	Tracking(void);
	~Tracking(void);
};

}