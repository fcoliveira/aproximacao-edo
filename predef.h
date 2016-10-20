#ifndef PREDEF_INCLUDED
#define PREDEF_INCLUDED

    #include <stdio.h>
    #include <math.h>
    #include <stdbool.h>
    #include "euler_explicito.h"
    #include "euler_implicito.h"
    #include "rk_44.h"

    extern double g_t_min;
    extern double g_t_max;
    extern double g_y_contorno;// = sol_analitica(g_t_min);
    extern int g_teto;

    double f_xy(double t, double y); //edo

    double df_dy(double t, double y); //derivada edo

    void verifica_info();

    void inicializa_vetores(double n[], double h[]);

    void resolve_analitico (double (*analitico_f)(double), double h[ ]);

    void teste_convergencia (FILE *saida, double y_tf[][g_teto], int metodo);

    #include "sol_analitica.h"
    #include "funcoes.h"

#endif // PREDEF_INCLUDED
