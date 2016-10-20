#ifndef EULER_EXPLICITO_H_INCLUDED
#define EULER_EXPLICITO_H_INCLUDED

    #include <stdio.h>

    void euler_explicito (double t_minimo, double t_maximo, double (*f_edo)(double, double),
                                                        int quantidade_passos, double condicao_contorno);

#endif // EULER_EXPLICITO_H_INCLUDED
