#include "expression_engine.h"
#include <string>
#include <stdexcept>

extern "C" {
#include "../c/math_kernel.h"
}

double ExpressionEngine::evaluate(const std::string& expr) {

    size_t pos;
    double a, b;

    // Addition
    if ((pos = expr.find('+')) != std::string::npos) {
        a = std::stod(expr.substr(0, pos));
        b = std::stod(expr.substr(pos + 1));
        return add(a, b);
    }

    // Subtraction
    if ((pos = expr.find('-')) != std::string::npos) {
        a = std::stod(expr.substr(0, pos));
        b = std::stod(expr.substr(pos + 1));
        return sub(a, b);
    }

    // Multiplication
    if ((pos = expr.find('*')) != std::string::npos) {
        a = std::stod(expr.substr(0, pos));
        b = std::stod(expr.substr(pos + 1));
        return mul(a, b);
    }

    // Division
    if ((pos = expr.find('/')) != std::string::npos) {
        a = std::stod(expr.substr(0, pos));
        b = std::stod(expr.substr(pos + 1));
        return divide(a, b);
    }

    throw std::runtime_error("Invalid expression format");
}
