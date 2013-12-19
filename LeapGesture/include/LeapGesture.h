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
using namespace Leap;

namespace LeapClient {

typedef enum {
    HAND_MODE_UNKNOWN,
    HAND_MODE_RIGHT_HAND,
    HAND_MODE_LEFT_HAND,
    HAND_MODE_AUTO,
} hand_mode_t;

class LeapGesture {
public:
        LeapGesture(void);
        ~LeapGesture(void);
        int get_hand_mode(void);
        void set_hand_mode(int hand_mode);
		void initialize_gesture( const Hand hand );
private:
        int _hand_mode;
};

}

#endif