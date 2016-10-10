/*
 Projeto de Cálculo Numérico
Prof. Alexandre Roma (IME-USP)

        IAG-USP
         2015

Fábio Oliveira - 7978417
Jessé Stenico - 9051932

Resolução de E.D.O. pelos métodos:
Euler Explícito,
Euler Implícito e
Runge-Kutta Clássico.

Os resultados obtidos serão comparados com a solução analítica conhecida previamente.

Caso de calibragem: Decaimento Radioativo

y'=-Lambda*y
y=exp(-Lambda*t)

onde "Lambda" depende do material radioativo em questão.
*/
#include <stdio.h>
#include <math.h>

double SOL_ANALITICA (double t){ /*UTILIZADO PARA ANÁLISE DE CONVERGÊNCIA DO MÉTODO NUMÉRICO*/
/*CASO A SOLUÇÃO ANALÍTICA SEJA DESCONHECIDA, PREENCHER COM "return 1.0"
E DESCONSIDERAR OS RESULTADOS OBTIDOS PARA OS ARQUIVOS yanalitico.txt E convergencia*/

    return exp(-0.5*t);
}

double F_XY(double t, double y){ /*EDO*/

    return -0.5*y;
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

    analitico=&SOL_ANALITICA;
    fxy=&F_XY;
    df=&dFdY;

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
