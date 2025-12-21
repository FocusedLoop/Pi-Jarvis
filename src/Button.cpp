#include "PiJ.h"
#include "Button.h"
#include "CommandMapping.h"

MyButton::MyButton(const ButtonConfig& config) : paired_button(nullptr), config(config)
{
    set_label(config.label);
    set_margin(config.margin);
    set_size_request(config.width, config.height);
    signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));
    //pair_with(this, true); REMOVE?
}

void MyButton::pair_with(MyButton* other_button, bool disable_other)
{
    paired_button = other_button;
    set_sensitive(disable_other);
    if (other_button)
        other_button->paired_button = this;
}

void MyButton::on_button_clicked()
{
    CommandMapping command_map;
    std::cout << "Button clicked: " << get_label() << std::endl;
    
	if (config.type == "esp32")
    {
        std::cout << command_map.ESP32Connection(config.command) << std::endl;
	}
    else if (config.type == "ssh")
    {
        std::cout << command_map.SSHConnection() << std::endl;
    }
    
    if (paired_button)
    {
        set_sensitive(false);
        paired_button->set_sensitive(true);
    }
}