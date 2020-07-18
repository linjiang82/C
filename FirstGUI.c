// Include gtk
#include <gtk/gtk.h>

void changeText(GtkWidget *wid, gpointer ptr){
  static int count=0;
  char buffer[30];
  count++;
  sprintf(buffer,"clicked %d times",count);
  gtk_label_set_text(ptr,buffer);
}
static void on_activate (GtkApplication *app) {
  // Create a new window
  GtkWidget *window = gtk_application_window_new (app);
  GtkWidget *label = gtk_label_new ("Label");
  GtkWidget *box = gtk_box_new (GTK_ORIENTATION_VERTICAL,5); 
  // Create a new button 
  GtkWidget *button = gtk_button_new_with_label ("Close");
  GtkWidget *btn2 = gtk_button_new_with_label ("Tap Me");
   // When the button is clicked, destroy the window passed as an argument
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  g_signal_connect (btn2, "clicked", G_CALLBACK (changeText), label);
  gtk_box_pack_start((GtkBox *)box,label,TRUE,TRUE,1);
  gtk_box_pack_start((GtkBox *)box,btn2,TRUE,TRUE,1);
  gtk_box_pack_start((GtkBox *)box,button,TRUE,TRUE,1);
  gtk_container_add (GTK_CONTAINER (window), box);
  gtk_widget_show_all (window);
}

int main (int argc, char *argv[]) {
  // Create a new application
  GtkApplication *app = gtk_application_new ("com.example.GtkApplication",
                                             G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
  return g_application_run (G_APPLICATION (app), argc, argv);
}
