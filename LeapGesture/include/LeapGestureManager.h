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
#define DEBUG 1

#pragma once
#include <vector>
#include <string>
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

#if DEBUG
typedef enum {
//Err LeapGestureManagerment -- recognition errs
	RECONIZING_STATE_FAILED,
//Err LeapGesture -- translation errs
	INITIALIZE_FAILED,
//Err PimHand
//Err PimFinger
//Err PimVector
//Err LeapComm -- communication error
} err_t;

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

#if DEBUG
		int set_log_level(int);
		int get_log_level();
		inline void errWrapper(std::string s, err_t) {
			if (get_log_level() > 0) {
				std::cout << "Error in: " << s << "  ";
				switch (err_t) {
					case RECONIZING_STATE_FAILED: std::cerr<< "RECONIZING_STATE_FAILED" << std::endl; break;
					case INITIALIZE_FAILED: std::cerr<< "INITIALIZE_FAILED" << std::endl; break;
					default: std::cerr << "UFO!UFO!" << std::endl;
				}
			}
		}
#endif

private:
        manager_state_t _manager_state;
#if DEBUG
		static int _log_level;
#endif
};

}

#endif