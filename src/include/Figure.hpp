#pragma once
#include <string>

class Figure {
public:
    enum Color { Black, White, Not };
    enum Piece { King, Queen, Rook, Knight, Bishop, Pawn, None };
    Figure();
    Figure(Color, Piece);
    std::string get_css_class();
    Piece get_piece();

private:
    Color color;
    Piece piece;
};