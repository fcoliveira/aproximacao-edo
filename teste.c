#include "euler_explicito.h"
#include "euler_implicito.h"
#include "rk_44.h"
#include <math.h>

double edo (double t, double y){

    return -exp(-0.5 * t);
}

int main(void){

    double (*fxy)(double, double);

    fxy = &edo;

    euler_explicito(0.0, 5.0, fxy, 32, 0.6);


return 0;
}
