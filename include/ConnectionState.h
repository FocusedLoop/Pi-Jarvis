#ifndef CONNECTION_STATE_H
#define CONNECTION_STATE_H

#include <mutex>

enum class ConnectionStatus
{
	DISCONNECTED,
	CONNECTED,
};

class ConnectionState {
	public:
		static ConnectionState& instance();

		ConnectionStatus ssh_status() const;
		void set_ssh_status(ConnectionStatus state);

		ConnectionStatus esp32_status() const;
		void set_esp32_status(ConnectionStatus state);
	
	private:
		ConnectionState() = default;

		mutable std::mutex memebr_;
		ConnectionStatus ssh_ = ConnectionStatus::DISCONNECTED;
		ConnectionStatus esp32_ = ConnectionStatus::DISCONNECTED;
};
#endif
