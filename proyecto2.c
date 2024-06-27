/*
 * Proyecto, Parte 2: Error esperado (graficando con gnuplot)
 * [Kembly Anyelik Torres Barrera C07816]
 * [Pareja de proyecto:Cristhian Rojas Alvarez  C16760]
 * Descripción: Este programa recibe dos funciones cuadráticas y un porcentaje de error. Encuentra
 *              el subdominio donde la diferencia entre ambas funciones no supere el porcentaje de error.
 *              Luego, grafica ambas curvas y el subdominio utilizando gnuplot.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función para calcular el valor de una función cuadrática
double quadratic(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Función para encontrar los subdominios
void find_subdomains(double a1, double b1, double c1, double a2, double b2, double c2, double error, FILE *sub_fp) {
    double x;
    double f1, f2, diff, perc_diff;
    int in_subdomain = 0;
    double start, end;
    int found_subdomain = 0;

    for (x = -100000; x <= 100000; x += 0.1) {
        f1 = quadratic(a1, b1, c1, x);
        f2 = quadratic(a2, b2, c2, x);
        diff = fabs(f1 - f2);
        perc_diff = (diff / fabs(f1)) * 100;

        if (perc_diff <= error) {
            if (!in_subdomain) {
                start = x;
                in_subdomain = 1;
            }
            end = x;
        } else {
            if (in_subdomain) {
                fprintf(sub_fp, "%lf %lf\n", start, end);
                in_subdomain = 0;
                found_subdomain = 1;
            }
        }
    }
    if (in_subdomain) {
        fprintf(sub_fp, "%lf %lf\n", start, end);
        found_subdomain = 1;
    }

    if (!found_subdomain) {
        printf("No se encontraron subdominios donde la diferencia entre las funciones sea menor al porcentaje de error especificado.\n");
    }
}

// Función para generar el archivo de datos para gnuplot
void generate_data_file(double a1, double b1, double c1, double a2, double b2, double c2) {
    FILE *fp = fopen("data.dat", "w");
    double x;
    for (x = -100; x <= 100; x += 0.1) {
        fprintf(fp, "%lf %lf %lf\n", x, quadratic(a1, b1, c1, x), quadratic(a2, b2, c2, x));
    }
    fclose(fp);
}

// Función para generar el script de gnuplot
void generate_gnuplot_script() {
    FILE *gp = fopen("plot.gnuplot", "w");
    fprintf(gp, "set terminal png size 1200,800\n");
    fprintf(gp, "set output 'plot.png'\n");
    fprintf(gp, "set style rect fc lt -1 fillstyle solid 0.15\n");

    FILE *sub_fp = fopen("subdomain.dat", "r");
    double start, end;
    int rect_id = 1;
    while (fscanf(sub_fp, "%lf %lf", &start, &end) == 2) {
        fprintf(gp, "set object %d rect from %lf, graph 0 to %lf, graph 1\n", rect_id++, start, end);
    }
    fclose(sub_fp);

    fprintf(gp, "plot 'data.dat' using 1:2 with lines title 'Función 1', \\\n");
    fprintf(gp, "     'data.dat' using 1:3 with lines title 'Función 2'\n");
    fclose(gp);
}

//cambio 
int main() {
    double a1, b1, c1, a2, b2, c2, error;

    // Entrada de coeficientes para la primera función cuadrática
    printf("Ingrese los coeficientes de la primera función cuadrática (a b c):\n");
    printf("a: ");
    while (scanf("%lf", &a1) != 1) {
        while (getchar() != '\n'); // Limpiar el buffer
        printf("Entrada inválida. Ingrese nuevamente 'a': ");
    }
    printf("b: ");
    while (scanf("%lf", &b1) != 1) {
        while (getchar() != '\n'); // Limpiar el buffer
        printf("Entrada inválida. Ingrese nuevamente 'b': ");
    }
    printf("c: ");
    while (scanf("%lf", &c1) != 1) {
        while (getchar() != '\n'); // Limpiar el buffer
        printf("Entrada inválida. Ingrese nuevamente 'c': ");
    }

    // Entrada de coeficientes para la segunda función cuadrática
    printf("\nIngrese los coeficientes de la segunda función cuadrática (d e f):\n");
    printf("d: ");
    while (scanf("%lf", &a2) != 1) {
        while (getchar() != '\n'); // Limpiar el buffer
        printf("Entrada inválida. Ingrese nuevamente 'd': ");
    }
    printf("e: ");
    while (scanf("%lf", &b2) != 1) {
        while (getchar() != '\n'); // Limpiar el buffer
        printf("Entrada inválida. Ingrese nuevamente 'e': ");
    }
    printf("f: ");
    while (scanf("%lf", &c2) != 1) {
        while (getchar() != '\n'); // Limpiar el buffer
        printf("Entrada inválida. Ingrese nuevamente 'f': ");
    }

    // Entrada del porcentaje de error
    printf("Ingrese el porcentaje de error (0-100): ");
    while (scanf("%lf", &error) != 1  || error < 0 || error > 100) {
        while (getchar() != '\n'); // Limpiar el buffer
        printf("Entrada inválida. Ingrese nuevamente el porcentaje de error (0-100): ");
    }

    // Generar los archivos de datos y el script de gnuplot
    generate_data_file(a1, b1, c1, a2, b2, c2);

    FILE *sub_fp = fopen("subdomain.dat", "w");
    find_subdomains(a1, b1, c1, a2, b2, c2, error, sub_fp);
    fclose(sub_fp);

    generate_gnuplot_script();

    // Ejecutar gnuplot para generar la gráfica
    if (system("gnuplot plot.gnuplot") == -1) {
        fprintf(stderr, "Error al ejecutar gnuplot.\n");
        return 1;
    }

    printf("Gráfica generada en 'plot.png'. Utiliza un visor de imágenes para abrir 'plot.png'.\n");

    return 0;
}
