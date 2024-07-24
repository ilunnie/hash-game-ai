#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* weights;
    double  bias;
    double  output;

    double (*activate)(double);
    int inputs;
} Neuron;

double fit(Neuron *n, double* values) {
    double result = 0;
    int i;
    for (i = 0; i < n->inputs; i++)
        result += values[i] * n->weights[i];
    result += n->bias;
    
    return n->activate(result);
}

double identity(double x) {
    return x;
}

int main()
{
    double input[] = {0.1, 0.2, 0.3};
    double weights[] = {0.1, 0.2, 0.3};

    Neuron neuron;
    neuron.inputs = sizeof(input) / sizeof(double);
    neuron.weights = weights;
    neuron.bias = 0.5;
    neuron.activate = identity;

    double out = fit(&neuron, input);
    printf("%f\n", out);

    free(neuron.weights);

    return 0;
}
