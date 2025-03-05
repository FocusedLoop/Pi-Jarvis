#include "PiJ.h"
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    setenv("NO_AT_BRIDGE", "1", 1);
    setenv("GTK_A11Y", "none", 1);
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.gtkmm.example");
    return app->make_window_and_run<MainWindow>(argc, argv);
}