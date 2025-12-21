#ifndef DEVICE_WIDGET_H
#define DEVICE_WIDGET_H

#include <gtkmm.h>

class DeviceWidget : public Gtk::Box
{
public:
    DeviceWidget();

private:
    Gtk::Box m_button_box;
};

#endif