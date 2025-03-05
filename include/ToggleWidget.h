#ifndef TOGGLE_WIDGET_H
#define TOGGLE_WIDGET_H

#include <gtkmm.h>

class ToggleWidget: public Gtk::Box
{
public:
    ToggleWidget();

private:
    Gtk::Box m_button_box;
};

#endif