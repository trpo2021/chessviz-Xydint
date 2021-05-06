#pragma once
#include <Figure.hpp>
#include <string>

typedef std::pair<char, int> pci;

using namespace std;

struct Step {
    Figure::Piece piece;
    pci first;
    pci last;
};

Step parse_notation(string notation);
