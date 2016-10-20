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
