#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
    public:
        MainWindow();

    private:
        Gtk::Box m_main_box;
        Gtk::Box m_sidebar;
        Gtk::Label m_sidebar_label;
        Gtk::ScrolledWindow m_scrolled_sidebar;
        Gtk::Stack m_stack;

        Glib::RefPtr<Gtk::SignalListItemFactory> create_list_factory();
};
#endif