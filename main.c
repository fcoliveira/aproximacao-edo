/***************************************************************************************************************
* Projeto inicialmente desenvolvido para a disciplina "MAP0214 - Calculo Numerico com Aplicacoes em Fisica",
* ministrada pelo Professor Dr. Alexandre Roma, Instituto de Matematica e Estat�stica - USP.
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
*   Euler Expl�cito, Euler Impl�cito e Runge-Kutta Cl�ssico (4,4)
*
* Altera��es feitas por Fabio Oliveira (fcoliveira).
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
//#include <stdio.h>

int main (void){

    char check_analitico_implementado;
    bool check;
    //Comum aos tres metodos.
//    double passos[g_teto];        /*QUANTIDADE DE PASSOS (nPassos) A SER DADO*/
//    double deltaT[g_teto];        /*deltaT CORRESPONDENTE A CADA nPassos*/

    do{

        printf("Solucao analitica implementada? 's' ou 'n': ");
        scanf("%c", check_analitico_implementado);
        check = ((check_analitico_implementado != 's') && (check_analitico_implementado != 'n'));
        if(check){
            printf("Resposta invalida. Tente novamente.\n");
        }
    }while(check);

    //Vetor para solucao analitica
    //double (*analitico)(double); //sol analitica


//    double (*f_edo)(double, double); //edo
//    double (*derivada_edo)(double, double); //derivada da edo

//    analitico = &sol_analitica;
//    f_edo = &f_xy;
//    derivada_edo = &df_dy;

    verifica_info( );

    printf("Inicializando vetores..\n");

    inicializa_vetores(passos, deltaT);/*INICIALIZA OS VETORES COM AS QUANTIDADES DE PASSOS E OS VALORES DE dT*/
                                       /*PARA CADA nPassos CORRESPONDENTE*/

    resolve_analitico (analitico, deltaT); /*CRIA ARQUIVO COM A SOLU��O ANAL�TICA*/

    printf("\nCalculando aproximacoes numericas...\n");

    /*AS TR�S FUN��ES ABAIXO S�O OS METODOS UTILIZADOS NO TRABALHO*/
    euler_explicito (f_edo, passos, deltaT);

    euler_implicito (f_edo, derivada_edo, passos, deltaT);

    runge_kutta (f_edo, passos, deltaT);

    return 0;
}
