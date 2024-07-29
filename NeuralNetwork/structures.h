#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct neuron {
    double* weights;
    double  bias;

    double (*activate)(double);
    int inputs;
} Neuron;

#endif