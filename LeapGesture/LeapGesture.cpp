/******************************************************************************\
* Copyright 2013 Chen Cheng & Huang Weichao

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
\******************************************************************************/
#include "include/LeapGesture.h"
#include "include/PimVector.h"
#include "include/LeapUtility"
#include <iterator>

namespace LeapClient {

LeapGesture::LeapGesture(void) {
	set_hand_id( MY_HAND_ID_IS_UNKNOWN );
}

LeapGesture::~LeapGesture(void) {
}

hand_mode_t LeapGesture::get_hand_mode(void) {
    return _hand_mode;
}

void LeapGesture::set_hand_mode(hand_mode_t hand_mode) {
    _hand_mode = hand_mode;
}

void LeapGesture::set_hand_id(int id)
{
	_my_hand_id = id;
}

int LeapGesture::get_hand_id(void)
{
	return _my_hand_id;
}

int LeapGesture::initialize_gesture( const Hand hand ) {
	if( get_hand_id() == MY_HAND_ID_IS_UNKNOWN )
	{
		//first time to be recognized
		set_hand_id( hand.id() );
	} else if( get_hand_id() != hand.id() )
	{
		//not the previously recognized hand
		//since the id will be reused, not very effective
		set_hand_id( MY_HAND_ID_IS_UNKNOWN );
		return 1;
	}

	//initialize or check hand mode
	//this should be done only in the first time to be recognized
	//but it is possible to have a new hand with the same id later...
	hand_mode_t expect_hand_mode = HAND_MODE_UNKNOWN;
	const Finger left_finger = hand.fingers().leftmost();
	const Finger right_finger = hand.fingers().rightmost();
	if( left_finger.width() > right_finger.width() )
	{
		expect_hand_mode = HAND_MODE_RIGHT_HAND;
	} else {
		expect_hand_mode = HAND_MODE_LEFT_HAND;
	}
	if( get_hand_mode() == HAND_MODE_AUTO )
	{
		set_hand_mode( expect_hand_mode );
	} else if ( get_hand_mode() != expect_hand_mode )
	{
		//wrong hand
		return 1;
	}

	//populate _my_hand
	//this seems unneccssary but it seperate the hand and finger from the platform we are using
	//all our algorith can be run platform independently
	PimClient::PimVector my_palm_position;
	my_palm_position.x = hand.palmPosition().x;
	my_palm_position.y = hand.palmPosition().y;
	my_palm_position.z = hand.palmPosition().z;
	_my_hand.set_palm_position( my_palm_position );

	const FingerList fingers = hand.fingers();
	int i=0;

	for (FingerList::const_iterator it=fingers.begin();it != fingers.end(),i < fingers.count();++it,++i) {
		std::cout << *it << " " << fingers[i].tipPosition().x << " " << std::endl;
	}
	std::cout << std::endl;

	Finger* tmp = const_cast<Finger*>(&fingers[i]);
	std::cout << tmp->tipPosition().x << std::endl;

	int num_fingers = fingers.count();
	Finger **pointer_list = new Finger* [num_fingers];
	LeapUtility::list_sort<FingerList,Finger>(fingers,pointer_list,fingers.count());

	for (FingerList::const_iterator it=fingers.begin();it != fingers.end();++it) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	
	//TODO: populate the _my_hand in details
	

	return 0;
}

}