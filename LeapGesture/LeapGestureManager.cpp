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
#include "include/LeapGestureManager.h"

namespace LeapClient {
LeapGestureManager::LeapGestureManager(void) {
	_gesture_count = 0;
}


LeapGestureManager::~LeapGestureManager(void) {
}


int LeapGestureManager::register_gesture(void) {
	return 0;
}


int LeapGestureManager::gesture_type(void) {
	return 0;
}

}