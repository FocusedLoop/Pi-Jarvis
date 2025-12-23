#include "PiJ.h"
#include "DeviceWidget.h"
#include "Button.h"

// TODO: Add status indicators for device and SSH connection states

namespace {
    ButtonConfig MakeEnableSshButtonConfig() {
        ButtonConfig button;
        button.label = "TEST";
        button.type = "ssh";
        button.command = 1;
        button.margin = 10;
        button.width = 350;
        button.height = 100;
        return button;
    }
}

DeviceWidget::DeviceWidget() : Gtk::Box(Gtk::Orientation::VERTICAL, 10)
{
    set_expand(true);
    set_halign(Gtk::Align::CENTER);
    set_valign(Gtk::Align::START);
    set_margin(10);

    /*ButtonConfig config_enable{ "TEST", "ssh", 1, 10, 350, 100 };
    auto button1 = Gtk::make_managed<MyButton>(config_enable);*/

    auto button1 = Gtk::make_managed<MyButton>(MakeEnableSshButtonConfig());

    append(*button1);
}