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
#include <algorithm>
#include "include/LeapUtility.h"
#include "include/SortEntity.h"

namespace LeapClient {
PimClient::PimVector LeapUtility::vector_translate_from_leap_to_pim( Vector leap_vector )
{
	PimClient::PimVector pim_vector;
	pim_vector.x = leap_vector.x;
	pim_vector.y = leap_vector.y;
	pim_vector.z = leap_vector.z;

	return pim_vector;
}

std::vector<int> LeapUtility::sort_fingers_based_on_position_x( FingerList fingers )
{
	LeapClient::SortEntity sort_entity;
	std::vector<LeapClient::SortEntity> entities;
	std::vector<int> result;

	for( int i=0; i<fingers.count(); i++ )
	{
		sort_entity.id = fingers[i].id();
		sort_entity.position = fingers[i].tipPosition().x;
		entities.push_back( sort_entity );
	}

	sort( entities.begin(), entities.end() );

	for( int j=0; j<fingers.count(); j++ )
	{
		result.push_back( entities[j].id );
	}

	return result;
}
}