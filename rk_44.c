
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
