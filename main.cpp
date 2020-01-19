#include <iostream>
#include "StringReverser.h"

int main()
{
    Solver<std::string, std::string> *sr = new StringReverser();
    sr->solve("helloworld");
}

