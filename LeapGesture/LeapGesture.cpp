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
#include <vector>
#include "include/LeapGesture.h"
#include "include/PimVector.h"
#include "include/LeapUtility.h"

namespace LeapClient {

LeapGesture::LeapGesture(void) {
	set_hand_id( UNKNOWN_ID );
	set_thumb_id( UNKNOWN_ID );
	set_forefinger_id( UNKNOWN_ID );
	set_middle_finger_id( UNKNOWN_ID );
	set_ring_finger_id( UNKNOWN_ID );
	set_little_finger_id( UNKNOWN_ID );
}

LeapGesture::~LeapGesture(void) {
}

hand_mode_t LeapGesture::get_hand_mode(void) {
    return _hand_mode;
}

void LeapGesture::set_hand_mode(hand_mode_t hand_mode) {
    _hand_mode = hand_mode;
}

void LeapGesture::set_hand_id(int id) {
	my_hand.id = id;
}

int LeapGesture::get_hand_id(void) {
	return my_hand.id;
}

void LeapGesture::set_thumb_id(int id) {
	my_hand.thumb.id = id;
}
		
int LeapGesture::get_thumb_id(void) {
	return my_hand.thumb.id;
}
		
void LeapGesture::set_forefinger_id(int id) {
	my_hand.forefinger.id = id;
}
		
int LeapGesture::get_forefinger_id(void) {
	return my_hand.forefinger.id;
}
		
void LeapGesture::set_middle_finger_id(int id) {
	my_hand.middle_finger.id = id;
}
		
int LeapGesture::get_middle_finger_id(void) {
	return my_hand.middle_finger.id;
}
		
void LeapGesture::set_ring_finger_id(int id) {
	my_hand.ring_finger.id = id;
}
		
int LeapGesture::get_ring_finger_id(void) {
	return my_hand.ring_finger.id;
}
		
void LeapGesture::set_little_finger_id(int id) {
	my_hand.little_finger.id = id;
}
		
int LeapGesture::get_little_finger_id(void) {
	return my_hand.little_finger.id;
}

initialize_gesture_result_t LeapGesture::initialize_gesture( const Hand hand ) {
	const FingerList fingers = hand.fingers();
	std::vector<int> id_in_sequence;

	if( fingers.count() != 5)
	{
		//During the initialize, we always assume the best situation.
		goto initialize_fail;
	}

	//TODO: need to check the middle finger is pointing the front, otherwise the rest code would be wrong

	if( get_hand_id() == UNKNOWN_ID )
	{
		//first time to be recognized
		set_hand_id( hand.id() );

		if( get_hand_mode() == HAND_MODE_AUTO )
		{
			const Finger left_finger = hand.fingers().leftmost();
			const Finger right_finger = hand.fingers().rightmost();
			if( left_finger.width() > right_finger.width() )
			{
				set_hand_mode( HAND_MODE_RIGHT_HAND );
			} else {
				set_hand_mode( HAND_MODE_LEFT_HAND );
			}
		}
	} else if( get_hand_id() != hand.id() )
	{
		//not the previously recognized hand
		//since the id will be reused, not very effective
		goto initialize_fail;
	}

	//populate _my_hand
	//this seems unneccssary but it seperate the hand and finger from the platform we are using
	//all our algorith can be run platform independently

	//TODO:this is just an example, need to have more info set, probably in a seperate function
	my_hand.set_palm_position( _my_leap_utility.vector_translate_from_leap_to_pim( hand.palmPosition()) );
	
	id_in_sequence = _my_leap_utility.sort_fingers_based_on_position_x( fingers );

	//TODO:this is just an example, need to have more info set, probably in a seperate function
	if( get_thumb_id() == UNKNOWN_ID )
	{
		set_thumb_id( id_in_sequence[0] );
	} else if( get_thumb_id() != id_in_sequence[0] )
	{
		goto initialize_fail;
	}
	my_hand.thumb.set_tip_position( _my_leap_utility.vector_translate_from_leap_to_pim( hand.finger( id_in_sequence[0] ).tipPosition() ) );

	if( get_forefinger_id() == UNKNOWN_ID )
	{
		set_forefinger_id( id_in_sequence[1] );
	} else if( get_forefinger_id() != id_in_sequence[1] )
	{
		goto initialize_fail;
	}
	my_hand.forefinger.set_tip_position( _my_leap_utility.vector_translate_from_leap_to_pim( hand.finger( id_in_sequence[1] ).tipPosition() ) );

	if( get_middle_finger_id() == UNKNOWN_ID )
	{
		set_middle_finger_id( id_in_sequence[2] );
	} else if( get_middle_finger_id() != id_in_sequence[2] )
	{
		goto initialize_fail;
	}
	my_hand.middle_finger.set_tip_position( _my_leap_utility.vector_translate_from_leap_to_pim( hand.finger( id_in_sequence[2] ).tipPosition() ) );

	if( get_ring_finger_id() == UNKNOWN_ID )
	{
		set_ring_finger_id( id_in_sequence[3] );
	} else if( get_ring_finger_id() != id_in_sequence[3] )
	{
		goto initialize_fail;
	}
	my_hand.ring_finger.set_tip_position( _my_leap_utility.vector_translate_from_leap_to_pim( hand.finger( id_in_sequence[3] ).tipPosition() ) );

	if( get_little_finger_id() == UNKNOWN_ID )
	{
		set_little_finger_id( id_in_sequence[4] );
	} else if( get_little_finger_id() != id_in_sequence[4] )
	{
		goto initialize_fail;
	}
	my_hand.little_finger.set_tip_position( _my_leap_utility.vector_translate_from_leap_to_pim( hand.finger( id_in_sequence[4] ).tipPosition() ) );

	return INITIALIZE_GESTURE_SUCCESS;

initialize_fail:
	set_hand_id( UNKNOWN_ID );
	set_thumb_id( UNKNOWN_ID );
	set_forefinger_id( UNKNOWN_ID );
	set_middle_finger_id( UNKNOWN_ID );
	set_ring_finger_id( UNKNOWN_ID );
	set_little_finger_id( UNKNOWN_ID );
	return INITIALIZE_GESTURE_FAILED;
}

}