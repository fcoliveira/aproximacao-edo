#include "euler_explicito.h"

void euler_explicito (double t_minimo, double t_maximo, double (*f_edo)(double, double),
                        int quantidade_passos, double condicao_contorno){

    FILE *saida;

    char arq[15];
    int k;
    double y, t;
    int passo;
    double incremento = (t_maximo - t_minimo) / quantidade_passos;

    sprintf(arq, "exp%d.txt", quantidade_passos); /*UM ARQUIVO DIFERENTE PARA CADA QUANTIDADE DE PASSOS*/
    saida = fopen(arq, "w");

    y = condicao_contorno;
    t = t_minimo;

    fprintf(saida, "%.10f %.10f\n", t, y);

    for(passo = 1; passo <= quantidade_passos; passo++){

        t = t_minimo + passo * incremento;
        y = y + incremento * f_edo(t, y);
        fprintf(saida, "%.10f %.10f\n", t, y);

    }

    fclose(saida);
}
