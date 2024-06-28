/*
Proyecto del curso de Programacion bajo Plataformas Abiertas IE-0117
Estudiantes:
Kembly Anyelik Torres Barrera C07816
Cristhian Rojas Álvarez C16760

Parte 1: Tiktaktoe (Biblioteca GTK+3.0)

Este programa implementa un juego TikTakToe desde el lenguaje de programación C, hace uso de la biblioteca GTK+3.0 para cargar la interfaz gráfica generada por Glade. El juego consta de una cuadricula 3x3 inicialmente vacía, y valores de variables a jugar “X” y “O”, en este caso el jugador inicial siempre será “X”, la ventana de juego va a tomar valores de estas variables hasta que se generen tres columnas o filas lógicamente adyacentes “con las mismas variables”, o bien para cuando una diagonal cumpla con la condición de contener tres variables iguales. Una vez generado el ganador, se muestra un mensaje indicando a este o en caso de que exista empate presente un mensaje relacionado a este.

Los requisitos para su ejecución:
- Compilador GCC
- GTK+3.0

Archivos necesarios:
- Proyecto1.c
- Archivo Glade

Nótese, que es necesario contener el archivo punto c y el punto glade en el mismo directorio que el Makefile para su ejecución.

Ejecución:
Abrir terminal y escribir make p1. Al hacer esto se compilará el archivo proyecto1.c a través de gcc y generará un archivo llamado exe. Una vez compilado se ejecuta el proyecto con el comando “./exe”.

Parte 2: Error esperado

Este programa fue realizado en lenguaje C con el fin de encontrar un subdominio donde la diferencia entre dos funciones cuadráticas, ingresadas por el usuario, no supere un porcentaje de error especificado. Seguidamente, se grafican ambas curvas utilizando gnuplot, mostrando claramente con una región rectangular el rango donde la diferencia entre las curvas es menor al error proporcionado.

Para correr el programa, se recomienda tener la biblioteca Gnuplot instalada. Para instalar Gnuplot, se recomienda usar el siguiente comando: sudo apt-get install gnuplot.

El programa solicitará los coeficientes de las dos funciones cuadráticas y un porcentaje de error (de 0 a 100). Después de que el usuario ingresa los datos requeridos, el programa calculará el subdominio donde la diferencia entre las funciones es menor al porcentaje de error especificado y generará una gráfica utilizando Gnuplot.

Para la representación gráfica de las funciones cuadráticas, se redujo el dominio de [-100000, 100000] a [-100, 100]. Esta decisión se basa en mejorar la legibilidad y comprensión de la gráfica, ya que el rango original era demasiado extenso para algunos valores para visualizarlos efectivamente en una escala estándar. Cabe aclarar que el cálculo del subdominio donde la diferencia entre las funciones es menor al porcentaje de error especificado sigue realizándose con precisión utilizando el rango completo de [-100000, 100000].

Se generan los siguientes archivos:
- plot.png: Archivo de imagen que contiene la gráfica generada.
- data.dat: Archivo de datos utilizado por Gnuplot para graficar.
- subdomain.dat: Archivo de datos que define el subdominio donde la diferencia entre las funciones es menor al error especificado.

Abrir terminal y escribir make p2. Al hacer esto se compilará el archivo proyecto2.c debido al código propuesto en el archivo Makefile y se generará un archivo llamado exe. Una vez compilado se ejecuta el proyecto con el comando “./exe”. Para poder observar la gráfica generada, utiliza el siguiente comando: xdg-open plot.png.
*/
