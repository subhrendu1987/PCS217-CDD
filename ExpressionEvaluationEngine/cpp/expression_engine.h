#ifndef EXP_ENGINE_H
#define EXP_ENGINE_H

#include <string>

class ExpressionEngine {
public:
    double evaluate(const std::string& expr);
};

#endif
