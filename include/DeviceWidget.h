#ifndef DEVICE_WIDGET_H
#define DEVICE_WIDGET_H

#pragma once // LOOK INTO MORE
#include <gtkmm.h>
#include "ConnectionState.h"

class DeviceWidget : public Gtk::Box
{
public:
    DeviceWidget();

private:
	// Status Indicators
    Gtk::DrawingArea ssh_dot_;
	Gtk::DrawingArea esp32_dot_;

    ConnectionStatus ssh_status_ = ConnectionStatus::DISCONNECTED;
	ConnectionStatus esp32_status_ = ConnectionStatus::DISCONNECTED;

	void on_state_changed(ConnectionSnapshot snapshot);
    void setup_dot(Gtk::DrawingArea& dot);

    void draw_dot(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height,, ConnectionStatus status)// Callback

    // Button
    Gtk::Box m_button_box;
};

#endif