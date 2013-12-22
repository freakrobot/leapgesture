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
#include <iostream>
#include "include/LeapGestureManager.h"

namespace LeapClient {
LeapGestureManager::LeapGestureManager(void) : Listener() {
    //TODO: May pass config info as the argument
    config_gestures();
	set_manager_state( MANAGER_STATE_UNKNOWN );
}

LeapGestureManager::~LeapGestureManager(void) {
}

int LeapGestureManager::config_gestures(void) {
    //TODO: May pass config info as the argument or read from some config file
    gesture_list.clear(); //always clear the list first, so this function can be called even not in the class constructor
    
    //Hard code temporarily
    LeapGesture first_gesture;
    first_gesture.set_hand_mode( HAND_MODE_AUTO );
    gesture_list.push_back( first_gesture );
    return 0;
}

void LeapGestureManager::set_manager_state( manager_state_t state )
{
	std::cout << "Manager state switch from " << _manager_state << " to " << state << std::endl;
	_manager_state = state;
}

manager_state_t LeapGestureManager::get_manager_state( void )
{
	return _manager_state;
}

recognizing_state_state_t LeapGestureManager::recognizing_gestures( const Frame frame )
{
	const HandList hands = frame.hands();
	if( hands.count() != gesture_list.size() )
	{
		goto reconizing_failed;
	}

	for( int i = 0; i < hands.count(); i++ )
	{
		//TODO: Current loop is wrong.
		//Need to traverse the hands based on their positions
		Hand hand = hands[0];
		if( hand.fingers().count() != 5 )
		{
			goto reconizing_failed;
		}

		if( gesture_list[i].initialize_gesture( hand ) )
		{
			config_gestures(); //reset all gestures in the list
			goto reconizing_failed;
		}
	}

	return RECOGNIZING_STATE_SUCCESS;

reconizing_failed:
		return RECOGNIZING_STATE_FAILED;
}

void LeapGestureManager::onFrame( const Controller& controller ) {
	const Frame frame = controller.frame();
	switch(get_manager_state()) {
		case MANAGER_STATE_UNKNOWN: {
			static int success_time = 0;
			int recognizing_result = RECOGNIZING_STATE_UNKNOWN;
			recognizing_result = recognizing_gestures( frame );
			if( recognizing_result == RECOGNIZING_STATE_FAILED )
			{
				success_time = 0;
			} else if ( recognizing_result == RECOGNIZING_STATE_SUCCESS )
			{
				success_time++;
			}
			if( success_time > RECOGNIZING_THRESHOLD )
			{
				set_manager_state( MANAGER_STATE_RECOGNIZED );
			}
			break;
		}
		case MANAGER_STATE_RECOGNIZED: {
			break;
		}
		case MANAGER_STATE_LOST: {
			break;
		}
		default: {
			std::cout << "Unknow state!!!" << std::endl;
			break;
		}
	}

}

}