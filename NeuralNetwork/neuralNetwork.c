#include <stdlib.h>
#include <math.h>

#include "neuralNetwork.h"
#include "structures.h"
#include "activationFunctions.h"

double neuron_output(Neuron *n, double* inputs) {
    double result = 0;
    for (int i = 0; i < n->inputs; i++)
        result += inputs[i] * n->weights[i];
    result += n->bias;
    
    return n->activate(result);
}

double* layer_output(Layer *l, double* inputs) {
    double *output = (double*)malloc(l->count * sizeof(double));
    for (int i = 0; i < l->count; i++)
        output[i] = neuron_output(&l->neurons[i], inputs);
    return output;
}

double* network_output(Network *nn, double* inputs) {
    double* output = inputs;
    for (int i = 0; i < nn->count; i++)
        output = layer_output(&nn->layers[i], output);
    return output;
}