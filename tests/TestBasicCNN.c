/*
 * Copyright (c) 2024 U S A M A H
 * All rights reserved.
 *
 * This code is licensed under the MIT License.
 */

#include <stdio.h>
#include <assert.h>
#include "BasicCNN.h"

void test_relu() {
    float test_output[OUTPUT_SIZE][OUTPUT_SIZE] = {
        {1.0, -1.0, 2.0},
        {-0.5, 0.0, 3.0},
        {4.0, -2.0, -3.0}
    };
    
    relu(test_output);
    
    // Check that negative values are set to 0
    assert(test_output[0][1] == 0.0);
    assert(test_output[1][0] == 0.0);
    assert(test_output[2][1] == 0.0);
    printf("ReLU test passed!\n");
}

int main() {
    test_relu();
    return 0;
}