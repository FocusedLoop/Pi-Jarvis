#include "PiJ.h"
#include "ToggleWidget.h"
#include "Button.h"

ToggleWidget::ToggleWidget() : Gtk::Box(Gtk::Orientation::VERTICAL, 10)
{
    set_expand(true);
    set_halign(Gtk::Align::CENTER);
    set_valign(Gtk::Align::START);
    set_margin(10);

    ButtonConfig config_enable{ "Enable", "esp32", 1, 10, 350, 100};
    ButtonConfig config_disable{ "Disable", "esp32", 2, 10, 350, 100 };
    auto button1 = Gtk::make_managed<MyButton>(config_enable);
    auto button2 = Gtk::make_managed<MyButton>(config_disable);
    button1->pair_with(button2, true);
    button2->pair_with(button1, false);
    append(*button1);
    append(*button2);
}