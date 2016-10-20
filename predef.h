#ifndef PREDEF_INCLUDED
#define PREDEF_INCLUDED

    #include <stdio.h>
    #include <math.h>

    extern double g_t_min;
    extern double g_t_max;
    extern double g_y_contorno;// = sol_analitica(g_t_min);

    //#define g_y_contorno SOL_ANALITICA (g_t_min)

    double f_xy(double t, double y);

    double df_dy(double t, double y);

    double sol_analitica (double t);

    void verifica_info();

    void inicializa_vetores(double n[], double h[]);

    void resolve_analitico (double (*analitico_f)(double), double h[ ]);

    void teste_convergencia (FILE *saida, double y_tf[][g_teto], int metodo);

    void euler_explicito (double (*fxy)(double, double), double n[ ], double h[ ]);

    void euler_implicito (double (*fxy)(double, double), double (*df)(double, double), double n[ ], double h[ ]);

    void runge_kutta (double (*fxy)(double, double), double n[ ], double h[ ]);

    #include "funcoes.h"

#endif // PREDEF_INCLUDED
