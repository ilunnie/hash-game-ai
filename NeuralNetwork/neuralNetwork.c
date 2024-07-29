#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structures.h"
#include "activationFunctions.h"

double neuron_output(Neuron *n, double* values) {
    double result = 0;
    for (int i = 0; i < n->inputs; i++)
        result += values[i] * n->weights[i];
    result += n->bias;
    
    return n->activate(result);
}