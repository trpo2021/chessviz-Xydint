#pragma once
#include <Figure.hpp>
#include <fstream>
#include <map>

using namespace std;

class ChessDesk {
public:
    ChessDesk();
    void add_desk_in_file(string notation, fstream& file);

protected:
    map<char, Figure[8]> desk;
};