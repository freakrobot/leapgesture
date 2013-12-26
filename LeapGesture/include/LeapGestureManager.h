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
#ifndef _LEAP_GESTURE_MANAGER_H_
#define _LEAP_GESTURE_MANAGER_H_
#pragma once
#include <vector>
#include "Leap.h"
#include "include/LeapGesture.h"
#include "include/LeapComm.h"
using namespace Leap;

namespace LeapClient {

typedef enum {
    MANAGER_STATE_UNKNOWN,
    MANAGER_STATE_RECOGNIZED,
    MANAGER_STATE_LOST,
} manager_state_t;

typedef enum {
	RECOGNIZING_STATE_UNKNOWN,
    RECOGNIZING_STATE_SUCCESS,
	RECOGNIZING_STATE_FAILED,
} recognizing_state_state_t;

#define RECOGNIZING_THRESHOLD 10 //TODO: may be configurable

class LeapGestureManager : public Listener {

public:
        LeapGestureManager(void);
        ~LeapGestureManager(void);
		virtual void onFrame(const Controller& controller);
        int config_gestures(void);
		void set_manager_state(manager_state_t state);
		manager_state_t get_manager_state(void);
		recognizing_state_state_t recognizing_gestures( const Frame frame );
        std::vector<LeapGesture> gesture_list;
private:
        manager_state_t _manager_state;
};

}

#endif