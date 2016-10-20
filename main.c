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

#include "predef.h"

int main (void){

    double passos[g_teto];        /*QUANTIDADE DE PASSOS (nPassos) A SER DADO*/
    double deltaT[g_teto];        /*deltaT CORRESPONDENTE A CADA nPassos*/

    double (*analitico)(double);
    double (*fxy)(double, double);
    double (*df)(double, double);

    analitico = &sol_analitica;
    fxy = &f_xy;
    df = &df_dy;

    verifica_info( );

    printf("Inicializando vetores..\n");

    inicializa_vetores(passos, deltaT);/*INICIALIZA OS VETORES COM AS QUANTIDADES DE PASSOS E OS VALORES DE dT*/
                                       /*PARA CADA nPassos CORRESPONDENTE*/

    resolve_analitico (analitico, deltaT); /*CRIA ARQUIVO COM A SOLUÇÃO ANALÍTICA*/

    printf("\nCalculando aproximacoes numericas...\n");

    /*AS TRÊS FUNÇÕES ABAIXO SÃO OS METODOS UTILIZADOS NO TRABALHO*/
    euler_explicito (fxy, passos, deltaT);

    euler_implicito (fxy, df, passos, deltaT);

    runge_kutta (fxy, passos, deltaT);

    return 0;
}
