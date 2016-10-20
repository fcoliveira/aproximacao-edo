
//double
double g_t_min = 0.0;
double g_t_max = 5.0;

// UTILIZADO NO MÉTODO DE NEWTON-RAPHSON PARA EULER-IMPLICITO:
extern double g_epsilon = 1E-8;
extern int g_maximo_iteracao = 30;
extern int g_teto = 10;  /* nPassos = 2^k , com 1 < k <= g_teto*/

double f_xy(double t, double y){ /*EDO*/

    return -0.5 * y;
}

double df_dy(double t, double y){ /*DERIVADA DA FUNÇÃO FORNECIDA ACIMA EM RELAÇÃO A Y*/

    return -0.5;
}

double sol_analitica (double t){

    return exp(-0.5 * t);
}
