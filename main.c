/*
 Projeto de C�lculo Num�rico
Prof. Alexandre Roma (IME-USP)

        IAG-USP
         2015

F�bio Oliveira - 7978417
Jess� Stenico - 9051932

Resolu��o de E.D.O. pelos m�todos:
Euler Expl�cito,
Euler Impl�cito e
Runge-Kutta Cl�ssico.

Os resultados obtidos ser�o comparados com a solu��o anal�tica conhecida previamente.

Caso de calibragem: Decaimento Radioativo

y'=-Lambda*y
y=exp(-Lambda*t)

onde "Lambda" depende do material radioativo em quest�o.
*/
#include <stdio.h>
#include <math.h>

double SOL_ANALITICA (double t){ /*UTILIZADO PARA AN�LISE DE CONVERG�NCIA DO M�TODO NUM�RICO*/
/*CASO A SOLU��O ANAL�TICA SEJA DESCONHECIDA, PREENCHER COM "return 1.0"
E DESCONSIDERAR OS RESULTADOS OBTIDOS PARA OS ARQUIVOS yanalitico.txt E convergencia*/

    return exp(-0.5*t);
}

double F_XY(double t, double y){ /*EDO*/

    return -0.5*y;
}

double dFdY(double t, double y){ /*DERIVADA DA FUN��O FORNECIDA ACIMA EM RELA��O A Y*/

    return -0.5;
}

#define t_MIN 0.0
#define t_MAX 5.0
#define y_contorno SOL_ANALITICA (t_MIN)

/*UTILIZADO NO M�TODO DE NEWTON-RAPHSON PARA EULER-IMPLICITO*/
#define EPSILON 1e-8
#define MAXIMO_ITERACAO 30

#define TETO 10 /* nPassos = 2^k , com 1<k<=TETO*/



/*N�O ALTERAR O C�DIGO A PARTIR DESTE PONTO*/
/*N�O ALTERAR O ARQUIVO funcoes.h*/


/* ** ATEN��O! ** */
/*� NECESS�RIO QUE O ARQUIVO funcoes.h ESTEJA NA MESMA PASTA QUE O C�DIGO-FONTE.*/
/*NELES EST�O CONTIDAS TODAS AS FUN��ES DE AJUSTE UTILIZADAS NO PROJETO*/

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

    resolve_analitico (analitico, deltaT); /*CRIA ARQUIVO COM A SOLU��O ANAL�TICA*/

    printf("\nCalculando aproximacoes numericas...\n");

    /*AS TR�S FUN��ES ABAIXO S�O OS METODOS UTILIZADOS NO TRABALHO*/
    euler_explicito (fxy, passos, deltaT);

    euler_implicito (fxy, df, passos, deltaT);

    runge_kutta (fxy, passos, deltaT);

    return 0;
}
