#include "PiJ.h"
#include "DeviceConnect.h"

// read shh

#include <iostream>
#include <libssh/libssh.h>

int test_ssh() {
    ssh_session session = ssh_new();
    if (session == nullptr)
    {
        std::cerr << "Failed to create SSH session" << std::endl;
        return 1;
    }
    std::cout << "libssh is working!" << std::endl;
    ssh_free(session);
    return 0;
}


int SSHConnection()
{
	return 0;
}

int ESP32Connection()
{
	return 0;
}