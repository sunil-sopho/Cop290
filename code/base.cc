#include <gtkmm.h>

int main(int argc, char *argv[])
{
  // auto app =
  //   Gtk::Application::create(argc, argv,
  //     "org.gtkmm.examples.base");

  // Gtk::Window window;
    GtkWidget *wind;
    gtk_init(&argc,&argv);
    wind = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(wind);
    gtk_main();
  Gtk::Box box;

  // window.set_default_size(200, 200);

  // return app->run(window);
}
