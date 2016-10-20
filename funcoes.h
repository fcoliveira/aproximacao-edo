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

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

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

void verifica_info(  );

void inicializa_vetores(double n[ ], double h[ ]);

void resolve_analitico (double (*analitico_f)(double), double h[ ]);

void teste_convergencia (FILE *saida, double ytf[][g_teto], int metodo);

#endif
