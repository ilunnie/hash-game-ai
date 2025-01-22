#include "structures.h"

#ifndef CONSTRUCTORS_H
#define CONSTRUCTORS_H

Neuron neuron_init(int input_size, double (*activate)(double), double (*initializer)());

Layer layer_init(int units, int input_size, double (*activate)(double), double (*initializer)());

Network network_init(int input_size);
void add_layer(Network *nn, int units, double (*activate)(double), double (*initializer)());

#endif