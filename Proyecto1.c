#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>
// IE-0117 Plataformas abiertas
// Proyecto: Parte 1, TikTakToe
// Estudiantes: Cristhian Rojas Álvarez C16760
// Kembly Torres 
// Fecha: 27 de junio 2024
// ------------------------------------------
// struct de datos del juego
typedef struct {
    GtkWidget *botones[3][3]; // matriz de botones, puntero a GtkWidget
    char tablero[3][3]; // matriz para estado del tablero
    char jugador_actual; // jugador actual
    GtkWidget *ventana; // puntero a ventana
} gato; // struct gato

// crear función de reinicio
void reinicio_gato(gato *juego) { // función para reiniciar el juego apuntando a la estructura gato
    for (int n = 0; n < 3; n++) { // ciclo for para limpiar tablero "externo"
        for (int m = 0; m < 3; m++) { // ciclo for para limpiar tablero "interno"
            juego->tablero[n][m] = ' '; // limpiar tablero, inicializa las celdas con espacios vacíos
            //  funciones de la biblioteca gtk-3
            // elimina cualquier texto que se muestre en el botón
            gtk_button_set_label(GTK_BUTTON(juego->botones[n][m]), " "); // limpiar botones
            //true el widget se habilita, permite interacción del usuario
            // false el widget se deshabilita, no permite interacción del usuario
            gtk_widget_set_sensitive(juego->botones[n][m], TRUE); // habilitar botones
        }
    }
    juego->jugador_actual = 'X'; // jugador actual es X
}
// función para verificar si hay un ganador
bool verificar_ganador(gato *juego) { 
    for (int n = 0; n < 3; n++) { // ciclo for para verificar si hay un ganador
    // verifica si hay un ganador en las filas
    // si hay tres celdas iguales en una fila, hay un ganador y retorna true para indicar que hay un ganador
        if (juego->tablero[n][0] == juego->tablero[n][1] && juego->tablero[n][1] == juego->tablero[n][2] && juego->tablero[n][0] != ' ') { // verificar si hay un ganador
            return true; // si hay un ganador
        }
    }
    // verifica si hay un ganador en las columnas
    // si hay tres celdas iguales en una columna, hay un ganador y retorna true para indicar que hay un ganador
    for (int n = 0; n < 3; n++) { // ciclo for para verificar si hay un ganador
        if (juego->tablero[0][n] == juego->tablero[1][n] && juego->tablero[1][n] == juego->tablero[2][n] && juego->tablero[0][n] != ' ') { // verificar si hay un ganador
            return true; // si hay un ganador
        }
    }

    // verifica si hay un ganador en las diagonales
    //primera diagonal
    if (juego->tablero[0][0] == juego->tablero[1][1] && juego->tablero[1][1] == juego->tablero[2][2] && juego->tablero[0][0] != ' ') { // verificar si hay un ganador
        return true; // si hay un ganador
    }
    //segunda diagonal
    if (juego->tablero[0][2] == juego->tablero[1][1] && juego->tablero[1][1] == juego->tablero[2][0] && juego->tablero[0][2] != ' ') { // verificar si hay un ganador
        return true; // si hay un ganador
    }
    return false; // si no hay un ganador
}
// función para verificar si hay un empate
bool verificar_empate(gato *juego) { 
    // recorremos filas con for externo y columnas con for interno
    for (int n = 0; n < 3; n++) { 
        for (int m = 0; m < 3; m++) { 
            if (juego->tablero[n][m] == ' ') { // si hay un espacio vacío la partida no ha terminado
            // por tanto no hay empate retornamos false
                return false; 
            }
        }
    }
    // no ha habido ganador y todas las celdas están llenas, implica empate
    return true; // retornamos true si hay un empate
}
// función para manejar el clic en un botón
// parametros a recibir: puntero a widget (boton) clickeado y un puntero dirigido a struct gato
void click_boton(GtkWidget *boton, gpointer datos) { 
    // se convierte el puntero datos a un puntero tipo gato, y ese es el struct que contiene la info
    gato *juego = (gato *)datos; 
    // ciclo for para recorrer la matriz de botones
    for (int n = 0; n < 3; n++) { 
        for (int m = 0; m < 3; m++) { 
            if (boton == juego->botones[n][m]) { // si el botón clickeado es igual al botón en la posición n,m,
            // entonces se continua con la logica del juego
            //ahora, se verifica si la celda está vacía
                if (juego->tablero[n][m] == ' ') { // si la celda está vacía, se procede a:
                    juego->tablero[n][m] = juego->jugador_actual; // actualizar la celda, toma el valor del jugador actual
                    gtk_button_set_label(GTK_BUTTON(boton), juego->jugador_actual == 'X' ? "X" : "O"); // se muestra en el botón el valor del jugador actual
                    gtk_widget_set_sensitive(boton, FALSE); // deshabilita el botón para evitar más clicks

                    if (verificar_ganador(juego)) { // llamado a la función por si hay un ganador mostrarlo
                        // crear cuadro de dialogo para mostrar mensaje de ganador
                        GtkWidget *cuadrod = gtk_message_dialog_new(GTK_WINDOW(juego->ventana), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%c ha ganado!", juego->jugador_actual);
                        gtk_dialog_run(GTK_DIALOG(cuadrod)); // muestra el mensaje
                        gtk_widget_destroy(cuadrod); // destruye el mensaje
                        reinicio_gato(juego); // reinicia el juego invocando la func
                    } else if (verificar_empate(juego)) { // llamar funcion de verificar empate
                        // crear cuadro de dialogo para mostrar mensaje de empate
                        GtkWidget *cuadrod = gtk_message_dialog_new(GTK_WINDOW(juego->ventana), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Empate!");
                        gtk_dialog_run(GTK_DIALOG(cuadrod)); // muestra el mensaje
                        gtk_widget_destroy(cuadrod); // destruye el mensaje
                        reinicio_gato(juego); // reinicia el juego con la func
                    } else { // si no hay ganador ni empate cambia el jugador
                        if (juego->jugador_actual == 'X') { // si el jugador actual es X
                            juego->jugador_actual = 'O'; // cambia a O
                        } else { // si el jugador actual es O
                            juego->jugador_actual = 'X'; // cambia a X
                        }
                    }
                }
            }
        }
    }
}
// funcion principal main
int main(int argc, char *argv[]) { 
    GtkBuilder *constructor; // puntero a GtkBuilder
    GError *error = NULL; // puntero a GError
    gtk_init(&argc, &argv); // inicializa gtk
    // creamos un objeto gtkbuilder que permite crear interfaces de usuario con glade
    constructor = gtk_builder_new();
    // cargar el archivo glade y verificar si hay errores
    if (!gtk_builder_add_from_file(constructor, "cuadriculatkt.glade", &error)) {
        g_critical("Error al cargar el archivo: %s", error->message);
        g_error_free(error); // libera la memoria 
        return 1; // retorna 1 para indicar que hubo un error
    }
    // se crea un objeto tipo gato
    gato juego; 
    // el objeto ventana principal se obtiene del constructor y se asigna a la variable juego.ventana
    juego.ventana = GTK_WIDGET(gtk_builder_get_object(constructor, "ventana"));
    if (!juego.ventana) { // si no se encuentra la ventana en el archivo glade, se  muestra un mensaje de error
        g_critical("No se pudo encontrar el objeto ventana en el archivo Glade.");
        return 1; // se retorna 1 para indicar que hubo un error
    }
    // se conecta la señal destroy con la función gtk_main_quit por si se cierra la ventana
    g_signal_connect(juego.ventana, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // vamos a configurar los botones del tablero
    const char *boton_ids[3][3] = { 
        {"boton00", "boton01", "boton02"},
        {"boton10", "boton11", "boton12"},
        {"boton20", "boton21", "boton22"}
    };
    // ahora vamos a recorrer la matriz de botones para asignar los botones del constructor a la matriz de botones
    for (int c = 0; c < 3; ++c) {
        for (int d = 0; d < 3; ++d) {
            // se obtiene el boton del constructor y se asigna a la matriz de botones
            juego.botones[c][d] = GTK_WIDGET(gtk_builder_get_object(constructor, boton_ids[c][d]));
            if (!juego.botones[c][d]) { // preguntamos si se encontró el botón en el archivo glade
                // si no se encuentra el botón, se muestra un mensaje de error
                g_critical("No se pudo encontrar el objeto %s en el archivo Glade.", boton_ids[c][d]);
                return 1;
            }
            // se conecta la señal clicked con la función click_boton  
            g_signal_connect(juego.botones[c][d], "clicked", G_CALLBACK(click_boton), &juego);
        }
    }
    // se llama a la función reinicio_gato para inicializar el juego
    reinicio_gato(&juego);
    // se muestra la ventana
    gtk_widget_show_all(juego.ventana);
    gtk_main(); // se inicia el bucle principal de la aplicació
    return 0; // se retorna 0 para indicar que la aplicacion terminó correctamente
}   // finaaaaaaaaal chan chan chan



