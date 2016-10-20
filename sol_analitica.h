#ifndef SOL_ANALITICA_H_INCLUDED
#define SOL_ANALITICA_H_INCLUDED

    double sol_analitica (double t);
    double (*analitico)(double);
    void resolve_analitico (double (*analitico_f)(double), double h[ ]);

#endif // SOL_ANALITICA_H_INCLUDED
