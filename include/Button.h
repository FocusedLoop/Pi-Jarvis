#ifndef BUTTON_H
#define BUTTON_H

#include <gtkmm.h>
#include <string>

struct ButtonConfig {
    std::string label = "C";
    std::string type = "esp32";
    int margin = 10;
    int width = 100;
    int height = 50;
};

class MyButton : public Gtk::Button
{
    public:
        MyButton(const ButtonConfig& config);
        void pair_with(MyButton* other_button, bool disable_other);
    protected:
        void on_button_clicked();
    private:
        MyButton* paired_button;
		ButtonConfig config;
};

#endif