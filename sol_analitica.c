/*UTILIZADO PARA ANÁLISE DE CONVERGÊNCIA DO MÉTODO NUMÉRICO*/
/*CASO A SOLUÇÃO ANALÍTICA SEJA DESCONHECIDA, PREENCHER COM "return 1.0"
E DESCONSIDERAR OS RESULTADOS OBTIDOS PARA OS ARQUIVOS yanalitico.txt E convergencia*/

#include "sol_analitica.h"

double sol_analitica (double t){

    return exp(-0.5 * t);
}

    analitico = &sol_analitica;
    f_edo = &f_xy;
    derivada_edo = &df_dy;


void resolve_analitico (double (*analitico_f)(double), double h[ ]){ /*SOLUÇÃO ANALÍTICA*/

    FILE *saida;
    double k;
    double max_passo = (g_t_max-g_t_min) / h[g_teto - 1];
    double y = g_y_contorno;
    double t = g_t_min;

    saida = fopen("y_analitico.txt", "w");
    fprintf(saida, "%.10f %.10f\n", t, y);

    for (k = 1; k <= max_passo; k++){

        t = g_t_min + k * h[g_teto - 1];
        y = analitico_f(t);
        fprintf(saida, "%.10f %.10f\n", t, y);

    }
    ultimo_y_analitico = y;

    fclose(saida);
}
