#include "expression_evaluator.h"
int main()
{
     std::string in;
     std::getline(std::cin,in);
     if (check(in))  std::cout<<cal(in);
     else std::cout<<"ILLEGAL";

    return 0;
}