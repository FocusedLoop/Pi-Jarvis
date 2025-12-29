#include "PiJ.h"
#include "DeviceWidget.h"
#include "Button.h"
#include <cmath>

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

	// Set colour based on connection status
    void set_colour(const Cairo::RefPtr<Cairo::Context>& cr, ConnectionStatus status) {
        switch (status) {
            case ConnectionStatus::CONNECTED:cr->set_source_rgb(0.1, 0.8, 0.1); break; // Green
			case ConnectionStatus::DISCONNECTED:cr->set_source_rgb(0.9, 0.2, 0.2); break; // Red
			default: cr->set_source_rgb(0.5, 0.5, 0.5); break; // Grey
        }
    }
}

// TODO: IMPLEMENT DEVICE DOT
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

// TODO: IMPLEMENT DEVICE DOT SETUP


// TODO: ON STATE CHANGED


// TODO: DRAW DOT