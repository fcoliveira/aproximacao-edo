#include <stdio.h>
#include <math.h>

void euler_implicito (double t_minimo, double t_maximo, double (*f_edo)(double, double),
                        double (*derivada_edo)(double, double), int quantidade_passos, double condicao_contorno, double epsilon, int max_iteracao){

    FILE *saida;

    char arq[15];

    double erro;
    int passo, k, iteracao;

    double y_implicito;
    double t;
    double chute_inicial = (t_maximo - t_minimo) / 2.0;
    double y1, y2;
    double incremento = (t_maximo - t_minimo) / quantidade_passos;

    sprintf(arq, "imp%d.txt", quantidade_passos);
    saida = fopen(arq, "w");

    y1 = chute_inicial;
    y_implicito = condicao_contorno;
    t = t_minimo;
    fprintf(saida, "%.10f %.10f\n", t, y_implicito);

    for(passo = 1; passo <= quantidade_passos; passo++){

        t = t_minimo + passo * incremento;
        erro = 1 / epsilon; /*VALOR SEGURAMENTE MAIOR QUE epsilon QUALQUER QUE SEJA ELE*/
        iteracao = 1;
        while (erro > epsilon){ /*METODO DE NEWTON*/

            if(iteracao > max_iteracao){
                printf ("Newton-Raphson: Atingiu maximo de iteracoes determinado!\n");
                break;
            }

            y2 = y1 - (y1 - y_implicito - incremento * f_edo(t, y1)) / (1 - incremento * derivada_edo(t, y1));
            erro = fabs(y2 - y1);
            y1 = y2;
            iteracao++;
        }
        y_implicito = y1;

        fprintf(saida, "%.10f %.10f\n", t, y_implicito);
    }


    fclose(saida);
}
