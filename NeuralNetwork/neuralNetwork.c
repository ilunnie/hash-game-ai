#include <stdlib.h>
#include <math.h>

#include "neuralNetwork.h"
#include "structures.h"
#include "activationFunctions.h"

double neuron_output(Neuron *n, double* values) {
    double result = 0;
    for (int i = 0; i < n->inputs; i++)
        result += values[i] * n->weights[i];
    result += n->bias;
    
    return n->activate(result);
}

double* layer_output(Layer *l, double* values) {
    double *output = (double*)malloc(l->count * sizeof(double));
    for (int i = 0; i < l->count; i++)
        output[i] = neuron_output(&l->neurons[i], values);
    return output;
}