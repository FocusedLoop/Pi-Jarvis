#include "PiJ.h"
#include "DeviceWidget.h"
#include "Button.h"
#include "LabelledWidget.h"
#include <algorithm>
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
    set_halign(Gtk::Align::FILL);
    set_valign(Gtk::Align::START);
    set_margin(10);

    /*ButtonConfig config_enable{ "TEST", "ssh", 1, 10, 350, 100 };
    auto button1 = Gtk::make_managed<MyButton>(config_enable);*/

    auto button1 = Gtk::make_managed<MyButton>(MakeEnableSshButtonConfig());

    // Create status indicators
    status_bar(ssh_dot, ssh_status);
    status_bar(esp32_dot, esp32_status);
    auto dot_row = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 10);
    dot_row->set_margin(8);
    dot_row->append(*Gtk::make_managed<LabelledWidget>(ssh_dot, "SSH"));
    dot_row->append(*Gtk::make_managed<LabelledWidget>(esp32_dot, "ESP32"));

    auto dot_frame = Gtk::make_managed<Gtk::Frame>();
    dot_frame->set_halign(Gtk::Align::END);
    dot_frame->set_child(*dot_row);
    append(*dot_frame);

    button1->set_halign(Gtk::Align::CENTER);
    append(*button1);
}

// Configure a dot and draw it in the colour of the referenced status
void DeviceWidget::status_bar(Gtk::DrawingArea& dot, const ConnectionStatus& status)
{
    dot.set_content_width(20);
    dot.set_content_height(20);
    dot.set_halign(Gtk::Align::CENTER);
    dot.set_draw_func([&status](const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
        set_colour(cr, status);
        cr->arc(width / 2.0, height / 2.0, std::min(width, height) / 2.0 - 1, 0, 2 * std::acos(-1.0));
        cr->fill();
    });
}

// TODO: ON STATE CHANGED
