#include "PiJ.h"
#include "Button.h"
#include "CommandMapping.h"
#include "DeviceConnect.h"

MyButton::MyButton(const ButtonConfig& config) : paired_button(nullptr), config(config)
{
    set_label(config.label);
    set_margin(config.margin);
    set_size_request(config.width, config.height);
    signal_clicked().connect(sigc::mem_fun(*this, &MyButton::on_button_clicked));
    pair_with(this, true);
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
    std::cout << "Button clicked: " << get_label() << std::endl;
    
	if (config.type == "esp32")
    {
        std::cout << parse_command(1) << std::endl;
	}
	else if (config.type == "ssh")
	{
        test_ssh();
	}
    
    set_sensitive(false);
    if (paired_button)
    {
        paired_button->set_sensitive(true);
    }
}