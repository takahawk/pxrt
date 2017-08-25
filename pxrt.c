#include <gtk/gtk.h>

typedef struct {
	GtkWidget *root;
	GtkNotebook *image_tabs;
} PxrtWindow;


void
file_new(GtkMenuItem *item, gpointer user_data);

void
file_open(GtkMenuItem *item, gpointer user_data);

void
file_save(GtkMenuItem *item, gpointer user_data);

void
file_save_as(GtkMenuItem *item, gpointer user_data);

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
file_new(GtkMenuItem *item, gpointer user_data)
{
}

void
file_open(GtkMenuItem *item, gpointer user_data)
{
}

void
file_save(GtkMenuItem *item, gpointer user_data)
{
}

void
file_save_as(GtkMenuItem *item, gpointer user_data)
{
}

void
pxrt_window_init(PxrtWindow *window)
{
	GtkBuilder *builder;
	GtkMenuItem *menu_file_new;
	GtkMenuItem *menu_file_save;
	GtkMenuItem *menu_file_save_as;
	GtkMenuItem *menu_file_open;
	GtkMenuItem *menu_file_quit;

	// creation and binding
	builder = gtk_builder_new_from_resource("/io/github/takahawk/pxrt/pxrt_window.glade");
	window->root = GTK_WIDGET(gtk_builder_get_object(builder, "pxrt_window"));
	window->image_tabs = GTK_NOTEBOOK(gtk_builder_get_object(builder, "image_tabs"));
	
	menu_file_new = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_file_new"));
	menu_file_save = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_file_save"));
	menu_file_save_as = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_file_save_as"));
	menu_file_open = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_file_open"));
	menu_file_quit = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_file_quit"));
	
	g_object_unref(builder);
	
	// signals
	g_signal_connect(menu_file_new, "activate", G_CALLBACK(file_new), NULL);
	g_signal_connect(menu_file_save, "activate", G_CALLBACK(file_save), NULL);
	g_signal_connect(menu_file_save_as, "activate", G_CALLBACK(file_save_as), NULL);
	g_signal_connect(menu_file_open, "activate", G_CALLBACK(file_open), NULL);
	g_signal_connect(menu_file_quit, "activate", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(window->root, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	

	gtk_widget_show(window->root);
	
	while (gtk_notebook_get_n_pages(window->image_tabs) != 0)
		gtk_notebook_remove_page(window->image_tabs, 0);
}
