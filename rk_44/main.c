#include "rk_44.h"

/*EDO A SER RESOLVIDA*/
double f_xy(double t, double y){

    return -0.5 * y;
}

/*SOLUÇÃO ANALÍTICA A SER IMPLEMENTADA - CASO DE TESTE DE CONVERGÊNCIA*/
double sol_analitica (double t){

    return exp(-0.5 * t);
}

double (*edo)(double, double) = &f_xy;
double t_min = 0.0;
double t_max = 5.0;
double contorno = 1.0;

int main(void){

	int cont;
	int n_passos;

	for (cont = 1; cont <= 12; cont++){

		n_passos = pow(2, cont);
		runge_kutta (t_min, t_max, edo,n_passos, contorno);

	}

return 0;
}
