#include "Logging.h"

namespace PimClient {

Logging::Logging(void)
{
}

Logging::~Logging(void)
{
}

int Logging::get_log_level() {
	return Logging::_log_level;
}

int Logging::set_log_level(int value) {
	Logging::_log_level = value;
	return Logging::_log_level;
}

/*
	 * name: log
	 * description: use to output the log information,
	 * usage: Logging::log(1, "i am feel really panic!");
	 * parameter string log msg
	 */
int Logging::log(int msg_level, std::string msg, int _line = __LINE__, char* _file = __FILE__) {
	if (msg_level <= _log_level) {
		time_t _time_tmp = std::time(0);
		char* _time_str = std::ctime(&_time_tmp);
		fprintf(LOG_OUTPUT, "[%s][%s:%d] %s", _time_tmp, _file, _line, msg.c_str());
	}

	return 0;
}

}