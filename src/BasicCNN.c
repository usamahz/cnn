/*
 * Copyright (c) 2024 U S A M A H
 * All rights reserved.
 *
 * This code is licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 28
#define FILTER_SIZE 3
#define OUTPUT_SIZE (INPUT_SIZE - FILTER_SIZE + 1)

typedef struct {
    float weights[FILTER_SIZE][FILTER_SIZE];
    float bias;
} Filter;

void initialize_filter(Filter *filter) {
    for (int i = 0; i < FILTER_SIZE; i++) {
        for (int j = 0; j < FILTER_SIZE; j++) {
            filter->weights[i][j] = (float)rand() / RAND_MAX; // Random weights
        }
    }
    filter->bias = (float)rand() / RAND_MAX; // Random bias
}

float apply_filter(float input[INPUT_SIZE][INPUT_SIZE], Filter *filter, int x, int y) {
    float sum = 0.0;
    for (int i = 0; i < FILTER_SIZE; i++) {
        for (int j = 0; j < FILTER_SIZE; j++) {
            sum += input[x + i][y + j] * filter->weights[i][j];
        }
    }
    return sum + filter->bias; // Add bias
}

void convolve(float input[INPUT_SIZE][INPUT_SIZE], float output[OUTPUT_SIZE][OUTPUT_SIZE], Filter *filter) {
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            output[i][j] = apply_filter(input, filter, i, j);
        }
    }
}

void relu(float input[OUTPUT_SIZE][OUTPUT_SIZE]) {
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (input[i][j] < 0) {
                input[i][j] = 0;
            }
        }
    }
}

int main(void) {
    float input[INPUT_SIZE][INPUT_SIZE] = { /* Initialize with your input data */ };
    float output[OUTPUT_SIZE][OUTPUT_SIZE];
    Filter filter;

    initialize_filter(&filter);
    convolve(input, output, &filter);
    relu(output);

    // Output the result
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            printf("%f ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}
