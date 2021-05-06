#include <Figure.hpp>

Figure::Figure(Color color, Piece piece)
{
    this->color = color;
    this->piece = piece;
}

std::string Figure::get_css_class()
{
    std::string res = "";
    switch (color) {
    case Black:
        res += "black ";
        break;
    case White:
        res += "white ";
        break;
    }
    King, Queen, Rook, Knight, Bishop, Pawn, None;
    switch (piece) {
    case King:
        res += "king";
        break;
    case Queen:
        res += "queen";
        break;
    case Rook:
        res += "rook";
        break;
    case Knight:
        res += "knight";
        break;
    case Bishop:
        res += "bishop";
        break;
    case Pawn:
        res += "pawn";
        break;
    }
    return res;
}

Figure::Figure()
{
}