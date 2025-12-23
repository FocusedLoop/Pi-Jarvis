#include "ConnectionState.h"

ConnectionState& ConnectionState::instance()
{
	static ConnectionState instance;
	return instance;
}

ConnectionStatus ConnectionState::ssh_status() const
{
	std::lock_guard<std::mutex> lock(memebr_);
	return ssh_;
}

ConnectionStatus ConnectionState::esp32_status() const
{
	std::lock_guard<std::mutex> lock(memebr_);
	return esp32_;
}

void ConnectionState::set_ssh_status(ConnectionStatus state)
{
	std::lock_guard<std::mutex>lock(memebr_);
	ssh_ = state;
}

void ConnectionState::set_esp32_status(ConnectionStatus state)
{
	std::lock_guard<std::mutex>lock(memebr_);
	esp32_ = state;
}

