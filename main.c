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

#include <stdio.h>
#include <math.h>

double SOL_ANALITICA (double t){ /*UTILIZADO PARA ANÁLISE DE CONVERGÊNCIA DO MÉTODO NUMÉRICO*/
/*CASO A SOLUÇÃO ANALÍTICA SEJA DESCONHECIDA, PREENCHER COM "return 1.0"
E DESCONSIDERAR OS RESULTADOS OBTIDOS PARA OS ARQUIVOS yanalitico.txt E convergencia*/

    return exp(-0.5 * t);
}

double F_XY(double t, double y){ /*EDO*/

    return -0.5 * y;
}

double dFdY(double t, double y){ /*DERIVADA DA FUNÇÃO FORNECIDA ACIMA EM RELAÇÃO A Y*/

    return -0.5;
}

#define t_MIN 0.0
#define t_MAX 5.0
#define y_contorno SOL_ANALITICA (t_MIN)

/*UTILIZADO NO MÉTODO DE NEWTON-RAPHSON PARA EULER-IMPLICITO*/
#define EPSILON 1e-8
#define MAXIMO_ITERACAO 30

#define TETO 10 /* nPassos = 2^k , com 1<k<=TETO*/



/*NÃO ALTERAR O CÓDIGO A PARTIR DESTE PONTO*/
/*NÃO ALTERAR O ARQUIVO funcoes.h*/


/* ** ATENÇÃO! ** */
/*É NECESSÁRIO QUE O ARQUIVO funcoes.h ESTEJA NA MESMA PASTA QUE O CÓDIGO-FONTE.*/
/*NELES ESTÃO CONTIDAS TODAS AS FUNÇÕES DE AJUSTE UTILIZADAS NO PROJETO*/

#include "funcoes.h"

int main (void){

    double passos[TETO];        /*QUANTIDADE DE PASSOS (nPassos) A SER DADO*/
    double deltaT[TETO];        /*deltaT CORRESPONDENTE A CADA nPassos*/

    double (*analitico)(double);
    double (*fxy)(double, double);
    double (*df)(double, double);

    analitico = &SOL_ANALITICA;
    fxy = &F_XY;
    df = &dFdY;

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
