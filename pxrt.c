#include <gtk/gtk.h>

int
main(int argc, char **argv)
{
	GtkBuilder *builder;
	GtkWidget *window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_resource("/io/github/takahawk/pxrt/pxrt_window.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "pxrt_window"));
	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show(window);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_main();
	
	return 0;
}
