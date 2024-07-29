#include "structures.h"
#include "activationFunctions.h"

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

double neuron_output(Neuron *n, double* inputs);
double* layer_output(Layer *l, double* inputs);
double* network_output(Network *nn, double* inputs);

#endif