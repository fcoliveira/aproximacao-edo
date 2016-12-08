#include "euler_implicito.h"

/*EDO A SER RESOLVIDA*/
double f_xy(double t, double y){

    return -0.5 * y;
}

/*SOLUÇÃO ANALÍTICA A SER IMPLEMENTADA - CASO DE TESTE DE CONVERGÊNCIA*/
double sol_analitica (double t){

    return exp(-0.5 * t);
}


/*DERIVADA DA FUNÇÃO FORNECIDA ACIMA EM RELAÇÃO A Y*/
//apenas euler implicito
double df_dy(double t, double y){ 

    return -0.5;
}

double (*edo)(double, double) = &f_xy;
double t_min = 0.0;
double t_max = 5.0;
double contorno = 1.0;
double (*dy_edo)(double, double) = &df_dy;
double epsilon = 1E-8;

int main(void){

	int cont;
	int n_passos;

	for (cont = 1; cont <= 12; cont++){

		n_passos = pow(2, cont);
		euler_implicito (t_min, t_max, edo, dy_edo, n_passos, contorno, epsilon, 30);

	}

return 0;
}
