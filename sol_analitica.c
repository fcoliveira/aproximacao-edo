/*UTILIZADO PARA ANÁLISE DE CONVERGÊNCIA DO MÉTODO NUMÉRICO*/
/*CASO A SOLUÇÃO ANALÍTICA SEJA DESCONHECIDA, PREENCHER COM "return 1.0"
E DESCONSIDERAR OS RESULTADOS OBTIDOS PARA OS ARQUIVOS yanalitico.txt E convergencia*/

double sol_analitica (double t){

    return exp(-0.5 * t);
}
