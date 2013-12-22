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
#ifndef _PIM_HAND_H_
#define _PIM_HAND_H_

#include "include/PimFinger.h"
#include "include/PimVector.h"

namespace PimClient {

class PimHand {
public:
        PimHand(void);
        ~PimHand(void);
		void set_palm_position( PimClient::PimVector position );

		PimClient::PimFinger thumb;
		PimClient::PimFinger forefinger;
		PimClient::PimFinger middle_finger;
		PimClient::PimFinger ring_finger;
		PimClient::PimFinger little_finger;
private:
		PimClient::PimVector _palm_position;
};

}

#endif