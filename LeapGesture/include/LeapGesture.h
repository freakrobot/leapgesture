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
#ifndef _LEAP_GESTURE_H_
#define _LEAP_GESTURE_H_
#pragma once
#include <iostream>
#include "Leap.h"
#include "include/PimHand.h"
#include "include/LeapUtility.h"
using namespace Leap;

namespace LeapClient {

typedef enum {
    HAND_MODE_UNKNOWN,
    HAND_MODE_RIGHT_HAND,
    HAND_MODE_LEFT_HAND,
    HAND_MODE_AUTO,
} hand_mode_t;

typedef enum {
	INITIALIZE_GESTURE_SUCCESS,
	INITIALIZE_GESTURE_FAILED,
} initialize_gesture_result_t;

class LeapGesture {
public:
        LeapGesture(void);
        ~LeapGesture(void);
        hand_mode_t get_hand_mode(void);
        void set_hand_mode(hand_mode_t hand_mode);
        void set_hand_id(int id);
        int get_hand_id(void);
		void set_thumb_id(int id);
		int get_thumb_id(void);
		void set_forefinger_id(int id);
		int get_forefinger_id(void);
		void set_middle_finger_id(int id);
		int get_middle_finger_id(void);
		void set_ring_finger_id(int id);
		int get_ring_finger_id(void);
		void set_little_finger_id(int id);
		int get_little_finger_id(void);
        initialize_gesture_result_t initialize_gesture( const Hand hand );

		static const int UNKNOWN_ID = -1;
		PimClient::PimHand my_hand;
private:
        hand_mode_t _hand_mode;
		LeapClient::LeapUtility _my_leap_utility;
};

}

#endif