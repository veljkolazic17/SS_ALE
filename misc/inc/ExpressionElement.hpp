#pragma once

#include "Types.h"
#include <string>
#include <vector>
class Expression{

    public:
        struct ExpressionElement{
            ExpressionListElementType type;
            std::string value;
        };

        Expression(std::string,std::vector<ExpressionElement>*);

        void addToExpression(ExpressionElement);
        void setSymbol(std::string);

        std::string getSymbol();
        std::vector<ExpressionElement>* getExpression();

    private:
        std::string symbol;
        std::vector<ExpressionElement>* expression;
};
