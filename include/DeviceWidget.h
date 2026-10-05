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
    Gtk::DrawingArea ssh_dot;
	Gtk::DrawingArea esp32_dot;

    ConnectionStatus ssh_status = ConnectionStatus::DISCONNECTED;
	ConnectionStatus esp32_status = ConnectionStatus::DISCONNECTED;

	//void on_state_changed(ConnectionSnapshot snapshot);
    void status_bar(Gtk::DrawingArea& dot, const ConnectionStatus& status);
    Gtk::Box* make_labelled(Gtk::DrawingArea& dot, const Glib::ustring& text);

    // Button
    Gtk::Box m_button_box;
};

#endif