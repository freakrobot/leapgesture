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
#include "include/LeapGesture.h"
#include "include/LeapComm.h"

namespace LeapClient {

class LeapGestureManager {

public:
	LeapGestureManager(void);
	~LeapGestureManager(void);
	std::vector<LeapGesture> gesture_list;
	LeapComm gesture_comm;
	int registered_gestures(void);
	int gesture_type(void);

private:
	int _gesture_count;
};

}

#endif