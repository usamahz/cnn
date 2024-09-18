/*
 * Copyright (c) 2024 U S A M A H
 * All rights reserved.
 *
 * This code is licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"

// Function to read input data from a file
void read_input_data(const char *filename, float input[INPUT_SIZE][INPUT_SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(file, "%f", &input[i][j]);
        }
    }
    fclose(file);
}