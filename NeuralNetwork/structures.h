#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct neuron {
    double* weights;
    double  bias;

    double (*activate)(double);
    int inputs;
} Neuron;

typedef struct layer
{
    Neuron* neurons;
    int count;
} Layer;

typedef struct network
{
    Layer* layers;
    int count;
} Network;

#endif