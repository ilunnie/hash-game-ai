#include <stdlib.h>

#include "constructors.h"
#include "structures.h"

Neuron neuron_init(
    int input_size,
    double (*activate)(double), 
    double (*initializer)()) 
{
    Neuron neuron;
    neuron.weights = malloc(input_size * sizeof(double));
    neuron.bias = initializer();

    for (int i = 0; i < input_size; i++)
        neuron.weights[i] = initializer();

    neuron.activate = activate;
    neuron.inputs = input_size;

    return neuron;
}

Layer layer_init(
    int units,
    int input_size, 
    double (*activate)(double), 
    double (*initializer)())
{
    Layer layer;
    layer.count = units;

    layer.neurons = malloc(units * sizeof(Neuron));
    for (int i = 0; i < units; i++)
        layer.neurons[i] = neuron_init(input_size, activate, initializer);

    return layer;
}