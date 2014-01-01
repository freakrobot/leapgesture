#include "include/Logging.h"

namespace PimClient {

Logging::Logging(void)
{
}

Logging::~Logging(void)
{
}

log_level_t Logging::_log_level = NO_LOG;

log_level_t Logging::get_log_level() {
	return PimClient::Logging::_log_level;
}

log_level_t Logging::set_log_level(log_level_t value) {
	Logging::_log_level = value;
	return PimClient::Logging::_log_level;
}

/*
 * name: log
 * description: use to output the log information,
 * usage: Logging::log(1, "i am feel really panic!");
 * parameter string log msg
 */
int Logging::log(log_level_t msg_level, std::string msg, int _line, char* _file) {
	if (msg_level <= PimClient::Logging::_log_level) {
#if (!LOG_OUTPUT_CONSOLE)
		FILE* LOG_OUTPUT;
		LOG_OUTPUT = fopen("pim.log","w");
#endif
		time_t _time_tmp = std::time(0);
		char* _time_str = std::ctime(&_time_tmp);
		fprintf(LOG_OUTPUT, "[%s][%s:%d] %s", _time_tmp, _file, _line, msg.c_str());
#if (!LOG_OUTPUT_CONSOLE)
		fclose(LOG_OUTPUT);
#endif
	}

	return 0;
}

}