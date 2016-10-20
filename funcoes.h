#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#define max_indice pow(2, g_teto) + 1
//double ultimo_y_analitico;
//double ytf[3][g_teto];

/***************************************************************************************************************
*
*   Nesse caso,
*       ytf[0][j] - euler explicito
*       ytf[1][j] - euler implicito
*       ytf[2][j] - runge kutta
*
***************************************************************************************************************/

void verifica_info(  );

void inicializa_vetores(double n[ ], double h[ ]);

void resolve_analitico (double (*analitico_f)(double), double h[ ]);

void teste_convergencia (FILE *saida, double ytf[][g_teto], int metodo);

#endif
