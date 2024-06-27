/*
 * # Parte 2: Error esperado (graficando con gnuplot)
 *
 * ## Este programa fue realizado en lenguaje C. Este programa permite encontrar un subdominio donde la diferencia entre dos funciones cuadráticas,
 * ingresadas por el usuario, no supere un porcentaje de error especificado. Seguidamente se grafican ambas curvas utilizando gnuplot, mostrando claramente
 * el rango donde la diferencia entre las curvas es menor al error proporcionado.
 *
 * Como requisitos para correr el programa, se recomienda contar con GNU Compiler Collection (GCC) y tener la Biblioteca Gnuplot instalada (\gnuplot\) para lo que se recomienda el comando "sudo apt-get install gnuplot"
 *
 * Aclaraciones sobre la  compilación y ejecución del programa
 *    Se usa el siguiente comando para compilar el programa:
 *      \\\`bash
 *      gcc -Wall -O2 -o exe proyecto2.c -lm
 *      \\\`
 *     Eso procederá a generar un ejecutable llamado \exe\.
 *    Una vez compilado, se ejecuta el programa con el siguiente comando:
 *      \\\`bash
 *      ./exe
 *      \\\`
 * El programa le solicitará los coeficientes de las dos funciones cuadráticas y un porcentaje de error (de 0 a 100). Después de ingresar los datos requeridos,
 * el programa calculará el subdominio donde la diferencia entre las funciones es menor al porcentaje de error especificado y generará una gráfica utilizando Gnuplot.
 * Para la representación gráfica de las funciones cuadráticas, se redujo el dominio de (-100000, 100000) a (-100, 100). Esto con el fin de mejorar la legibilidad y
 * comprensión de la gráfica, ya que el rango original era demasiado extenso para visualizar efectivamente en una escala estándar. Pero cabe recalcar que el cálculo
 * del subdominio donde la diferencia entre las funciones es menor al porcentaje de error especificado sigue realizándose con precisión utilizando el rango completo de
 * (-100000, 100000). Como se puede observar en el código.
 *
 * Se generan los siguientes archivos
 * - plot.png: Archivo de imagen que contiene la gráfica generada.
 * - data.dat: Archivo de datos utilizado por Gnuplot para graficar.
 * - subdomain.dat: Archivo de datos que define el subdominio donde la diferencia entre las funciones es menor al error especificado.
 */
