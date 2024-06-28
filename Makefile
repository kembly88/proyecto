# Variables
CC = gcc  # Define el compilador a usar, en este caso gcc para C.
CFLAGS = $(shell pkg-config --cflags gtk+-3.0)  # Opciones de compilación para incluir las cabeceras de GTK+ 3.0.
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)  # Opciones de enlace para incluir las bibliotecas de GTK+ 3.0.
LMFLAGS = -lm  # Opciones de enlace para incluir la biblioteca matemática estándar de C.
TARGET1 = exe # Nombre del archivo ejecutable para el primer proyecto.
TARGET2 = exe # Nombre del archivo ejecutable para el segundo proyecto.
SOURCE1 = Proyecto1.c  # Nombre del archivo fuente para el primer proyecto.
SOURCE2 = proyecto2.c  # Nombre del archivo fuente para el segundo proyecto.

# Objetivo predeterminado que compila ambos proyectos.
all: p1 p2

# Compila el primer proyecto generando el ejecutable definido en TARGET1.
p1: $(SOURCE1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCE1) $(LDFLAGS)

# Compila el segundo proyecto generando el ejecutable definido en TARGET2.
p2: $(SOURCE2)
	$(CC) -o $(TARGET2) $(SOURCE2) $(LMFLAGS)

# Borra los archivos generados por la compilación.
clean:
	rm -f $(TARGET1) $(TARGET2) *.o *.dat *.png *.gnuplot

# Declara all, p1, p2 y clean como objetivos ficticios.
.PHONY: all p1 p2 clean

