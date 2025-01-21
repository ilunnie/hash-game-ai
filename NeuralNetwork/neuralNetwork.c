#include <stdlib.h>
#include <math.h>

#include "neuralNetwork.h"
#include "structures.h"

void neuron_propagation(Neuron *n, double* inputs) {
    double result = 0;
    for (int i = 0; i < n->inputs; i++)
        result += inputs[i] * n->weights[i];
    result += n->bias;
    
    n->output = n->activate(result);
}

void layer_propagation(Layer *l, double* inputs) {
    for (int i = 0; i < l->count; i++)
        neuron_propagation(&l->neurons[i], inputs);
}

double* layer_output(Layer *l) {
    double *output = (double*)malloc(l->count * sizeof(double));
    for (int i = 0; i < l->count; i++)
        output[i] = l->neurons[i].output;
    return output;
}

void forward_propagation(Network *nn, double* inputs) {
    for (int i = 0; i < nn->count; i++) {
        layer_propagation(&nn->layers[i], inputs);
        inputs = layer_output(nn->layers[i]);
    }
}

double* network_output(Network *nn) {
    return layer_output(&nn->layers[nn->count - 1]);
}