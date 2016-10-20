/***************************************************************************************************************
* Projeto inicialmente desenvolvido para a disciplina "MAP0214 - Calculo Numerico com Aplicacoes em Fisica",
* ministrada pelo Professor Dr. Alexandre Roma, Instituto de Matematica e Estatística - USP.
*
* Titulo do Trabalho:
*   Resolucao de E.D.O's pelos metodos de Euler e Runge-Kutta e
*       analise do erro associado a cada metodo empregado.
*
* Professor Orientador:
*   Prof. Dr. Alexandre M. Roma
*
* Instituto de Astronomia, Geofisica e Ciencias Atmosfericas - Universidade de Sao Paulo, 2015
*
* Autores originais:
*   Fabio Oliveira (fcoliveira) - 7978417
*   Jesse Stenico               - 9051932
*
* Metodos de aproximacao empregados neste trabalho:
*   Euler Explícito, Euler Implícito e Runge-Kutta Clássico (4,4)
*
* Alterações feitas por Fabio Oliveira (fcoliveira).
* Obs.: no branch "original" constam todos os arquivos exatamente como foram entregues ao Professor no final do projeto.
*       Para mais informacoes a respeito da metodologia empregada, consulte o arquivo "relatorio_MAP0214.pdf"
***************************************************************************************************************/

/***************************************************************************************************************
*
*   IMPORTANTE: os arquivos funcoes.h e main.c devem estar juntos no mesmo diretorio para o funcionamento
*               adequado do programa.
*               Caso voce tenha obtido esse arquivo separadamente, acesse:
*               https://github.com/fcoliveira/aproximacao-edo
*
***************************************************************************************************************/

#define max_indice pow(2, g_teto) + 1

double ultimo_y_analitico;
double ytf[3][g_teto];

/***************************************************************************************************************
*
*   Nesse caso,
*       ytf[0][j] - euler explicito
*       ytf[1][j] - euler implicito
*       ytf[2][j] - runge kutta
*
***************************************************************************************************************/

void verifica_info(  ){

    printf  ("Intervalo: [%f, %f]\n"
             "Condicao de contorno: %f\n", g_t_min, g_t_max, g_y_contorno);

}

void inicializa_vetores(double n[ ], double h[ ]){

    int k;

    for(k = 0; k < g_teto; k++){

        n[k] = pow(2, k + 1);
        h[k] = (g_t_max - g_t_min) / n[k];

    }

    for (k = 0; k < g_teto; k++){

        printf("Passos: %4.f DeltaT: %4f\n", n[k], h[k]);

    }
}

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

void teste_convergencia (FILE *saida, double ytf[][g_teto], int metodo){

    int k;
    double a, b;

    a = ytf[metodo][0];

    for (k = 1; k < g_teto; k++){

        b = ytf[metodo][k];
        fprintf(saida, "%d %.10f\n", k, fabs( (a - ultimo_y_analitico) / (b - ultimo_y_analitico) ));
        a = b;

    }
}

void euler_explicito (double (*fxy)(double, double), double n[ ], double h[ ]){

    FILE *saida;
    FILE *convergencia;

    char arq[15];
    int k;
    double y, t;
    double passo;

    for (k = 0; k < g_teto; k++){

        sprintf(arq, "exp%d.txt", (int)pow(2, k + 1)); /*UM ARQUIVO DIFERENTE PARA CADA QUANTIDADE DE n PASSOS*/
        saida = fopen(arq, "w");

        y = g_y_contorno;
        t = g_t_min;
        fprintf(saida, "%.10f %.10f\n", t, y);

        for(passo = 1; passo <= n[k]; passo++){

            t = g_t_min + passo * h[k];
            y = y + h[k] * fxy(t, y);
            fprintf(saida, "%.10f %.10f\n", t, y);

        }
        fclose(saida);

        ytf[0][k] = y; /*ARMAZENA VALORES DE y(tf) EM UM VETOR SEPARADO*/
    }                              /*ÚTIL PARA TESTES DE CONVERGENCIA*/

    convergencia = fopen("conv_exp.txt", "w");
    teste_convergencia(convergencia, ytf, 0);

    fclose(convergencia);
}

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

void runge_kutta (double (*fxy)(double, double), double n[ ], double h[ ]){

    FILE *saida;
    FILE *convergencia;

    char arq[15];

    int k;

    double passo;
    double K_1, K_2, K_3, K_4;
    double y_rk;
    double t;

    for (k = 0; k < g_teto; k++){

        sprintf(arq, "rk%d.txt", (int)pow(2, k + 1));
        saida = fopen(arq, "w");

        y_rk = g_y_contorno;
        t = g_t_min;
        fprintf(saida, "%.10f %.10f\n", t, y_rk);

        for(passo = 1; passo <= n[k]; passo++){

            K_1 = fxy(t, y_rk);

            K_2 = fxy(t + 0.5 * h[k], y_rk + (0.5 * h[k] * K_1));

            K_3 = fxy(t + 0.5 * h[k], y_rk + (0.5 * h[k] * K_2));

            K_4 = fxy(t + h[k],       y_rk + (h[k] * K_3));

            y_rk = y_rk + (1.0 / 6.0) * h[k] * (K_1 + K_2 + K_2 + K_3 + K_3 + K_4);

			t = g_t_min + passo * h[k];

            fprintf(saida, "%.10f %.10f\n", t, y_rk);

        }
        ytf[2][k] = y_rk;

        fclose(saida);
    }

    convergencia = fopen("conv_rk.txt", "w");
    teste_convergencia(convergencia, ytf, 2);

    fclose(convergencia);
}
