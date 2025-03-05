#include "PiJ.h"
#include "CommandMapping.h"

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
    if (res != CURLE_OK)
    {
        std::cerr << "CURL failed: " << curl_easy_strerror(res) << std::endl;
    }
    else
    {
        std::cout << "Request sent successfully!" << std::endl;
    }
    curl_easy_cleanup(curl);
    return 0;
}

// Read the json file and parse commands
std::string parse_command(const u_int8_t command)
{
    Json::Value root;
    std::ifstream file("commands.json");
    file >> root;

    const char* device_ip = root["devices"][0].asCString();
    const char* device_command = root["commands"][command].asCString();
    std::string url = "http://" + std::string(device_ip) + ":8000";
    handle_http(url.c_str(), device_command);
    return url + " " + device_command;
}