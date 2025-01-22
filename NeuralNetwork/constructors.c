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

Network network_init(int input_size) {
    Network network;
    network.layers = malloc(sizeof(Layer));
    network.layers[0] = (Layer){
        .neurons = malloc(input_size * sizeof(Neuron)), 
        .count = input_size};
    network.count = 0;
    return network;
}

void add_layer(
    Network *nn, 
    int units, 
    double (*activate)(double),
    double (*initializer)())
{
    int input_size;
    int index;
    if (nn->count == 0) {
        index = 0;
        input_size = nn->layers[0].count;
    }
    else {
        index = nn->count;
        input_size = nn->layers[nn->count - 1].count;
    }

    nn->count = index + 1;
    Layer *layers = malloc(nn->count * sizeof(Layer));
    for (int i = 0; i < index; i++)
        layers[i] = nn->layers[i];
    layers[index] = layer_init(units, input_size, activate, initializer);

    nn->layers = layers;
}