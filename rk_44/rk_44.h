#ifndef RK_44_H_INCLUDED
#define RK_44_H_INCLUDED


    #include <stdio.h>
    #include <math.h>

    void runge_kutta (double t_minimo, double t_maximo, double (*f_edo)(double, double),
                                            int quantidade_passos, double condicao_contorno);

#endif // RK_44_H_INCLUDED
