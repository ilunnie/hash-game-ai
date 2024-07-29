#include "structures.h"
#include "activationFunctions.h"

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

double neuron_output(Neuron *n, double* values);
double* layer_output(Layer *n, double* values);

#endif