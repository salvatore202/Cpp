/*
 * fibonacci.cpp
 *
 *  Created on: 5 feb 2024
 *      Author: salva
 */
#include <iostream>



int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}



