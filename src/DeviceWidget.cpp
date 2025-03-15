#include "PiJ.h"
#include "DeviceWidget.h"
#include "Button.h"

DeviceWidget::DeviceWidget() : Gtk::Box(Gtk::Orientation::VERTICAL, 10)
{
    set_expand(true);
    set_halign(Gtk::Align::CENTER);
    set_valign(Gtk::Align::START);
    set_margin(10);

    ButtonConfig config_enable{ "TEST", "ssh", 1, 10, 350, 100};
    auto button1 = Gtk::make_managed<MyButton>(config_enable);
    append(*button1);
}