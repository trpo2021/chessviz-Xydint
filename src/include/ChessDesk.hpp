#pragma once
#include <Figure.hpp>
#include <fstream>
#include <map>

using namespace std;

typedef std::pair<char, int> pci;

class ChessDesk {
public:
    ChessDesk();
    void add_desk_in_file(string notation, ofstream& file);
    void move_figure(char x1, int y1, char x2, char y2, Figure::Piece);

protected:
    map<char, Figure[8]> desk;
};