#include "PiJ.h"
#include "MainWindow.h"
#include "CommandMapping.h"

int main(int argc, char* argv[])
{
	// Set environment variables for accessibility
    setenv("NO_AT_BRIDGE", "1", 1);
    setenv("GTK_A11Y", "none", 1);

	// Initialize GTK and Command Mapping
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.gtkmm.example");
    CommandMapping::read_config(nullptr);

    return app->make_window_and_run<MainWindow>(argc, argv);
}

/*
TODO:
- Run HTTP/SHH commands asynchronously to avoid blocking the UI.
- Create status indicators for device connection state and SSH status.
- Implement basic nvidia-smi monitoring and htop integration (look at perf).

*/