#include "../inc/ExpressionElement.hpp"

Expression::Expression(std::string symbol,std::vector<Expression::ExpressionElement>* expression){
    this->symbol = symbol;
    this->expression = expression;
}

void Expression::addToExpression(Expression::ExpressionElement element){
    this->expression->push_back(element);
}

void Expression::setSymbol(std::string str){
    this->symbol = str;
}

std::string Expression::getSymbol(){
    return this->symbol;
}

std::vector<Expression::ExpressionElement>* Expression::getExpression(){
    return this->expression;
}