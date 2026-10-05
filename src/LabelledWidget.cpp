#include "LabelledWidget.h"

// Bind label to GTK widget
LabelledWidget::LabelledWidget(Gtk::Widget& child, const Glib::ustring& text)
    : Gtk::Box(Gtk::Orientation::VERTICAL, 2)
{
    set_text(text);
    append(m_label);
    append(child);
}

// Apply label to object
void LabelledWidget::set_text(const Glib::ustring& text)
{
    m_label.set_markup("<small>" + Glib::Markup::escape_text(text) + "</small>");
}
