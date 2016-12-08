#include "rk_44.h"

void runge_kutta (double t_minimo, double t_maximo, double (*f_edo)(double, double),
                                    int quantidade_passos, double condicao_contorno){

    FILE *saida;

    char arq[15];

    int passo;
    double K_1, K_2, K_3, K_4;
    double y_rk;
    double t;
    double incremento = (t_maximo - t_minimo) / quantidade_passos;


    sprintf(arq, "rk%d.txt", quantidade_passos);
    saida = fopen(arq, "w");

    y_rk = condicao_contorno;
    t = t_minimo;

    fprintf(saida, "%.10f %.10f\n", t, y_rk);

    for(passo = 1; passo <= quantidade_passos; passo++){

        K_1 = f_edo(t, y_rk);

        K_2 = f_edo(t + 0.5 * incremento, y_rk + (0.5 * incremento * K_1));

        K_3 = f_edo(t + 0.5 * incremento, y_rk + (0.5 * incremento * K_2));

        K_4 = f_edo(t + incremento,       y_rk + (incremento * K_3));

        y_rk = y_rk + (1.0 / 6.0) * incremento * (K_1 + K_2 + K_2 + K_3 + K_3 + K_4);

		t = t_minimo + passo * incremento;

        fprintf(saida, "%.10f %.10f\n", t, y_rk);

    }

    fclose(saida);
}
