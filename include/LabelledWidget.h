#ifndef LABELLED_WIDGET_H
#define LABELLED_WIDGET_H

#include <gtkmm.h>

// Wraps any widget with a small caption above it
class LabelledWidget : public Gtk::Box
{
    public:
        LabelledWidget(Gtk::Widget& child, const Glib::ustring& text);
        void set_text(const Glib::ustring& text);

    private:
        Gtk::Label m_label;
};

#endif
