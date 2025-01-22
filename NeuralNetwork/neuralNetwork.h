#include "structures.h"

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

void neuron_propagation(Neuron *n, double *inputs);

void layer_propagation(Layer *l, double *inputs);
double* layer_output(Layer *l);

void forward_propagation(Network *nn, double *inputs);
double* network_output(Network *nn);

#endif