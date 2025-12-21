#ifndef COMMAND_MAPPING_H
#define COMMAND_MAPPING_H

#include <string>

class CommandMapping
{
public:
	std::string ESP32Connection(const u_int8_t command);
	std::string SSHConnection();
	static const Json::Value& read_config(const char* command);
};

#endif