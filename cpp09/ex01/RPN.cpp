#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const std::string &s) 
{
    (void)s;
}

RPN::RPN(const RPN& copy){
    *this = copy;
}

RPN&    RPN::operator=(const RPN& copy){
    if (this != &copy){
        this->_data = copy._data;
   }
   return (*this);
}

RPN::~RPN(){}

static bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int     RPN::evaluate(const std::string &expression)
{
    if (expression.empty())
        throw Error("empty expression");

    for (size_t i = 0; i < expression.size(); ++i)
    {
        char c = expression[i];

        if (c == ' ') continue;

        if (std::isdigit(c))
        {
            if (i + 1 < expression.size() && std::isdigit(expression[i + 1]))
                throw Error("operands must be single digits");
            _data.push(c - '0');
        }
        else if (isOperator(c))
            applyOperator(c);
        else
            throw Error("invalid token");
    }

    if (_data.size() != 1)
        throw Error("invalid expression");

    return _data.top();
}

void    RPN::applyOperator(char op)
{
    if (_data.size() < 2)
        throw Error("not enough operands");

    int b = _data.top(); _data.pop();
    int a = _data.top(); _data.pop();

    int result;
    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;
    else if (op == '/')
    {
        if (b == 0)
            throw Error("division by zero");
        result = a / b;
    }
    else
        throw Error("invalid operator");

    _data.push(result);
}
