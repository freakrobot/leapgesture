#include "LeapGesture.h"
using namespace LeapClient;

LeapGesture::LeapGesture(void)
{
	forefinger_id = 0;
}


LeapGesture::~LeapGesture(void)
{
}


int LeapGesture::recognize(void)
{
	return 0;
}


bool LeapGesture::isRightHand(void)
{
	return false;
}
