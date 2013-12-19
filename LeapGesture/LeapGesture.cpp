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

namespace LeapClient {

LeapGesture::LeapGesture(void) {
}

LeapGesture::~LeapGesture(void) {
}

int LeapGesture::get_hand_mode(void) {
    return _hand_mode;
}

void LeapGesture::set_hand_mode(int hand_mode) {
    _hand_mode = hand_mode;
}

void LeapGesture::initialize_gesture( const Hand hand ) {
	std::cout << "to do" << std::endl;
}

}