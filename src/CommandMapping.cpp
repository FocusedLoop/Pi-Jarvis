#include "PiJ.h"
#include "CommandMapping.h"

// Read json
Json::Value read_json(const char* device)
{
	Json::Value root;
	std::ifstream file("commands.json");
	file >> root;
	return root[device];
}

// Send http
int handle_http(const char* url, const char* command)
{
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, command);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return 0;
}

// Parse ESP32 commands
std::string CommandMapping::ESP32Connection(const u_int8_t command)
{
	Json::Value root = read_json("esp32");

    const char* device_ip = root["ip"].asCString();
    const char* device_command = root["commands"][command].asCString();
    std::string url = "http://" + std::string(device_ip);
	handle_http(url.c_str(), device_command);
    return "\n" + url + " " + device_command;
}

// Parse SHH commands
std::string CommandMapping::SSHConnection()
{
	Json::Value root = read_json("ssh");

	ssh_session my_ssh_session;
	int rc;
	int port = root["port"].asInt();
	const char* ip = root["ip"].asCString();
	const char* user = root["user"].asCString();
	const char* password = root["password"].asCString();

	my_ssh_session = ssh_new();
	if (my_ssh_session == NULL) { return 0; }

	ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, ip);
	ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &port);
	ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, user);

	rc = ssh_connect(my_ssh_session);
	if (rc != SSH_OK)
	{
		fprintf(stderr, "Error connecting: %s\n", ssh_get_error(my_ssh_session));
		ssh_free(my_ssh_session);
		return 0;
	}

	ssh_userauth_password(my_ssh_session, NULL, password);
	if (rc != SSH_AUTH_SUCCESS) {
		fprintf(stderr, "Error authenticating with password: %s\n", ssh_get_error(my_ssh_session));
		ssh_disconnect(my_ssh_session);
		ssh_free(my_ssh_session);
		return 0;
	}

	printf("SSH Connection Successful\n");
	ssh_disconnect(my_ssh_session);
	ssh_free(my_ssh_session);
	return "ssh " + std::string(user) + "@" + ip;
}