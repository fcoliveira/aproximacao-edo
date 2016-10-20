#ifndef EULER_IMPLICITO_H_INCLUDED
#define EULER_IMPLICITO_H_INCLUDED

    #include <stdio.h>
    #include <math.h>

    void euler_implicito (double t_minimo, double t_maximo, double (*f_edo)(double, double),
                            double (*derivada_edo)(double, double), int quantidade_passos, double condicao_contorno, double epsilon, int max_iteracao);


#endif // EULER_IMPLICITO_H_INCLUDED
