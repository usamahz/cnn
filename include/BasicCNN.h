/*
 * Copyright (c) 2024 U S A M A H
 * All rights reserved.
 *
 * This code is licensed under the MIT License.
 */

#ifndef CNN_H
#define CNN_H

#define INPUT_SIZE 28
#define FILTER_SIZE 3
#define OUTPUT_SIZE (INPUT_SIZE - FILTER_SIZE + 1)

typedef struct {
    float weights[FILTER_SIZE][FILTER_SIZE];
    float bias;
} Filter;

void initialize_filter(Filter *filter);
float apply_filter(float input[INPUT_SIZE][INPUT_SIZE], Filter *filter, int x, int y);
void convolve(float input[INPUT_SIZE][INPUT_SIZE], float output[OUTPUT_SIZE][OUTPUT_SIZE], Filter *filter);
void relu(float input[OUTPUT_SIZE][OUTPUT_SIZE]);

#endif // CNN_H
