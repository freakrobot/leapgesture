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
#ifndef _LEAP_UTILITY_H_
#define _LEAP_UTILITY_H_
#include <vector>
#include "Leap.h"
#include "PimVector.h"
using namespace Leap;

namespace LeapClient {
class LeapUtility {
public:
	PimClient::PimVector vector_translate_from_leap_to_pim( Vector leap_vector );
	std::vector<int> sort_fingers_based_on_position_x( FingerList fingers );
};
}
#endif