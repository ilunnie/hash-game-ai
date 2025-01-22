#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "initializers.h"

static void __attribute__((constructor)) initialize_random() {
    srand((unsigned int)time(NULL));
}

double random_normal(double mean, double standard_deviation) {
    double U = (double)rand() / RAND_MAX;
    return mean + standard_deviation * sqrt(-2 * log(U)) * cos(2 * M_PI * U);
}