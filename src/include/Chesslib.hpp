#pragma once
#include <Figure.hpp>
#include <string>

typedef std::pair<char, int> pci;

using namespace std;

struct Step {
    char piece;
    pci first;
    pci last;
};

Step parse_notation(string notation);
