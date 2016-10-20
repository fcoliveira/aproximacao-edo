#include <stdio.h>
#include <math.h>

extern double g_epsilon;
extern int g_maximo_iteracao;
extern int g_teto;

void euler_implicito (double (*fxy)(double, double), double (*df)(double, double), double n[ ], double h[ ]){

    FILE *saida;
    FILE *convergencia;

    char arq[15];

    double erro;
    int passo, k, iteracao;

    double y_implicito;
    double t;
    double chute_inicial = (g_t_max - g_t_min) / 2.0;
    double y1, y2;

    for (k = 0; k < g_teto; k++){ /*PERCORRE TODO O VETOR DE INCREMENTOS*/

        sprintf(arq, "imp%d.txt", (int)pow(2, k + 1));
        saida = fopen(arq, "w");

        y1 = chute_inicial;
        y_implicito = g_y_contorno;
        t = g_t_min;
        fprintf(saida, "%.10f %.10f\n", t, y_implicito);

        for(passo = 1; passo <= n[k]; passo++){

            t = g_t_min + passo * h[k];
            erro = 1 / g_epsilon; /*VALOR SEGURAMENTE MAIOR QUE g_epsilon QUALQUER QUE SEJA ELE*/
            iteracao = 1;
            while (erro > g_epsilon){ /*METODO DE NEWTON*/

                if(iteracao > g_maximo_iteracao){
                    printf ("Newton-Raphson: Atingiu maximo de iteracoes determinado!\n");
                    break;
                }

                y2 = y1 - (y1 - y_implicito - h[k] * fxy(t, y1)) / (1 - h[k] * df(t, y1));
                erro = fabs(y2 - y1);
                y1 = y2;
                iteracao++;
            }
            y_implicito = y1;

            fprintf(saida, "%.10f %.10f\n", t, y_implicito);
        }
        fclose(saida);
        ytf[1][k] = y_implicito;
    }

    convergencia = fopen("conv_imp.txt", "w");
    teste_convergencia(convergencia, ytf, 1);

    fclose(convergencia);
}
