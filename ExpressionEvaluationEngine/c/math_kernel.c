#include "math_kernel.h"
#include<stdio.h>

double add(double a, double b) { printf("Native (add)\n"); return a + b; }
double sub(double a, double b) { printf("Native (sub)\n"); return a - b; }
double mul(double a, double b) { printf("Native (mul)\n"); return a * b; }
double divide(double a, double b) { printf("Native (divide)\n"); return (b == 0) ? 0 : a / b;}
