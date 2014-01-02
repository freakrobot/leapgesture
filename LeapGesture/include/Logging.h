#pragma once
#include <cstdio>
#include <string>
#include <ctime>

#define LOG_OUTPUT_CONSOLE 1

#if LOG_OUTPUT_CONSOLE
  #define LOG_OUTPUT stderr
#else
  #define LOG_OUTPUT log_file_handler
#endif

namespace PimClient {

typedef enum {
	NO_LOG=0,
	LOG_LEVEL_DEBUG=1,
	LOG_LEVEL_PANIC=2,
	LOG_LEVEL_RECORDING=3,
	LOG_LEVEL_ERROR=4,
	LOG_LEVEL_WARNING=5
} log_level_t;

class Logging
{
public:
	Logging(void);
	~Logging(void);

	/*
	 * name: log
	 * description: use to output the log information,
	 * usage: Logging::log(LOG_LEVEL_DEBUG, "i am feel really panic!");
	 * parameter string log msg
	 */
	static int log(log_level_t log_level, std::string, int _line = __LINE__, char* _file = __FILE__);
	static log_level_t set_log_level(log_level_t);
	static log_level_t get_log_level();

private:
	/*
	 * 0 - no logging at all. Not very necessary as long as we keep level 1 concise
	 * 1 - debug. Anything you want to check, but SHOULD NOT checkin.
	 * 2 - panic. Something must mess up, such as malloc fails
     * 3 - recording. Very critical info such as "the system is initialized". Used to quickly locate which part is finished and which is next.
	 * 4 - error. Unexpected but known issue, such as the error reported from leap
     * 5 - warning. Undesired but okay issue such as "high network delay" or "one hand is missing".
	 */
	static log_level_t _log_level;	
#if (!LOG_OUTPUT_CONSOLE)
	FILE* LOG_OUTPUT;
#endif
	
};

}