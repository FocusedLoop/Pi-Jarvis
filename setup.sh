#!/bin/bash

# Exit on error
set -e

echo "Starting Pi_Jarvis setup..."

# Update and install essential packages
echo "Updating system and installing required packages..."
sudo apt update
sudo apt install -y \
    build-essential cmake git ninja-build \
    libboost-all-dev libssl-dev libfmt-dev libspdlog-dev \
    libcurl4-openssl-dev libjsoncpp-dev xinput-calibrator \
    libgtk-4-dev libgtkmm-4.0-dev \
    libssh-dev

# Run touchscreen calibration
echo "Running touchscreen calibration..."
if xinput_calibrator > /tmp/calibration.txt; then
    echo "Calibration completed."
else
    echo "Calibration failed or did not run."
fi
echo "DEBUG: Reached post-calibration."

# Verify installations
echo "Verifying installations..."
cmake --version
pkg-config --modversion gtk4 gtkmm-4.0 libcurl
find /usr/local/include /usr/include -name "curl.h" 2>/dev/null
find /usr/local/include /usr/include -name "gtkmm.h" 2>/dev/null

echo -e "\nPi_Jarvis setup complete! Please reboot to apply changes."