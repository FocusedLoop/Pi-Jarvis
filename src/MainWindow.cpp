#include "PiJ.h"
#include "MainWindow.h"
#include "ToggleWidget.h"
#include "DeviceWidget.h"

MainWindow::MainWindow()
{
    set_title("Pi Jarvis");
    set_default_size(600, 600);
    char* widget1 = "Toggle Power";
    char* widget2 = "Device Monitor";

    // Main Layout 
    m_main_box.set_orientation(Gtk::Orientation::HORIZONTAL);
    m_main_box.set_spacing(10);
    m_main_box.set_margin(20);

    // Sidebar
    m_sidebar.set_orientation(Gtk::Orientation::VERTICAL);
    m_sidebar.set_size_request(200, -1);
    m_sidebar.set_vexpand(true);
    m_sidebar_label.set_text("Menu");
    m_sidebar_label.set_margin(10);
    m_sidebar_label.set_xalign(0.0);

    auto list_store = Gtk::StringList::create({ widget1, widget2 });
    auto selection = Gtk::SingleSelection::create(list_store);
    auto list_view = Gtk::make_managed<Gtk::ListView>(selection, create_list_factory());

    list_view->set_vexpand(true);

    m_scrolled_sidebar.set_child(*list_view);
    m_scrolled_sidebar.set_policy(Gtk::PolicyType::NEVER, Gtk::PolicyType::AUTOMATIC);
    m_scrolled_sidebar.set_vexpand(true);
    m_scrolled_sidebar.set_size_request(200, 400);
    m_sidebar.append(m_sidebar_label);
    m_sidebar.append(m_scrolled_sidebar);

    // Widgets
    m_stack.set_hexpand(true);
    m_stack.set_vexpand(true);
    auto toggle_widget = Gtk::make_managed<ToggleWidget>();
    auto device_widget = Gtk::make_managed<DeviceWidget>();

    m_stack.add(*toggle_widget, widget1);
    m_stack.add(*device_widget, widget2);
    m_stack.set_visible_child(widget1);

    selection->property_selected().signal_changed().connect(
        [this, selection, list_store]() {
            auto index = selection->get_selected();
            if (index < list_store->get_n_items()) {
                auto selected_item = list_store->get_string(index);
                m_stack.set_visible_child(selected_item);
            }
        }
    );
    m_main_box.set_orientation(Gtk::Orientation::HORIZONTAL);

    // Create the window
    m_main_box.append(m_sidebar);
    m_main_box.append(m_stack);
    set_child(m_main_box);
}


// RE DO THIS
// Custom List Factory Implementation
Glib::RefPtr<Gtk::SignalListItemFactory> MainWindow::create_list_factory()
{
    auto factory = Gtk::SignalListItemFactory::create();

    // Create row structure
    factory->signal_setup().connect([](const Glib::RefPtr<Gtk::ListItem>& list_item)
        {
            auto label = Gtk::make_managed<Gtk::Label>();
            label->set_margin(10);
            label->set_hexpand(true);
            list_item->set_child(*label);
        });

    // Bind the data (menu text) to the label
    factory->signal_bind().connect([](const Glib::RefPtr<Gtk::ListItem>& list_item)
        {
            auto item = list_item->get_item();
            auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());

            if (label && item)
            {
                auto string_object = std::dynamic_pointer_cast<Gtk::StringObject>(item);
                if (string_object)
                {
                    label->set_text(string_object->get_string());
                }
            }
        });

    return factory;
}