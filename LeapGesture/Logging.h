#pragma once
#include <cstdio>
#include <string>
#include <ctime>

#define LOG_OUTPUT stderr

namespace PimClient {

class Logging
{
public:
	Logging(void);
	~Logging(void);

	/*
	 * name: log
	 * description: use to output the log information,
	 * usage: Logging::log(1, "i am feel really panic!");
	 * parameter string log msg
	 */
	static int log(int log_level, std::string, int _line = __LINE__, char* _file = __FILE__);
	static int set_log_level(int);
	static int get_log_level();
private:
	/*
	 * 0 - no logging at all. Not very necessary as long as we keep level 1 concise
	 * 1 - debug. Anything you want to check, but SHOULD NOT checkin.
	 * 2 - panic. Something must mess up, such as malloc fails
     * 3 - recording. Very critical info such as "the system is initialized". Used to quickly locate which part is finished and which is next.
	 * 4 - error. Unexpected but known issue, such as the error reported from leap
     * 5 - warning. Undesired but okay issue such as "high network delay" or "one hand is missing".
	 */
	static int _log_level;
	
};

}