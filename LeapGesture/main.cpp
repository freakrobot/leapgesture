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
#include "include\LeapGestureManager.h"
#include "Leap.h"
//#include "LeapComm.h"
using namespace Leap;

int main() {
 // LeapClient::LeapComm leapComm;
 // int ret = leapComm.lc_initialize();
 // if (ret == -1) exit(-1);
 // while ( 1 ) {
	//char get_char_c_to_continue;
	//std::cin >> get_char_c_to_continue;
	//if ( get_char_c_to_continue == 'c' ) {
	//	leapComm.lc_send("hellow");
	//}
 // }
    LeapClient::LeapGestureManager leapGestureManager;
	Controller controller;

	controller.addListener( leapGestureManager );

	std::cin.get();

	controller.removeListener( leapGestureManager );

	std::cin.get();
    return 0;
}
