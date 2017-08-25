#include <gtk/gtk.h>

typedef struct {
	GtkWidget *root;
	GtkNotebook *image_tabs;
} PxrtWindow;

void
pxrt_window_init(PxrtWindow *window);


int
main(int argc, char **argv)
{
	PxrtWindow window;
	
	gtk_init(&argc, &argv);
	pxrt_window_init(&window);
	gtk_main();
	
	return 0;
}

void
pxrt_window_init(PxrtWindow *window)
{
	GtkBuilder *builder;
	
	builder = gtk_builder_new_from_resource("/io/github/takahawk/pxrt/pxrt_window.glade");
	window->root = GTK_WIDGET(gtk_builder_get_object(builder, "pxrt_window"));
	window->image_tabs = GTK_NOTEBOOK(gtk_builder_get_object(builder, "image_tabs"));

	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show(window->root);
	g_signal_connect(window->root, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	while (gtk_notebook_get_n_pages(window->image_tabs) != 0)
		gtk_notebook_remove_page(window->image_tabs, 0);
}
