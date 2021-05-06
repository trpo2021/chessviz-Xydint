#include <Chesslib.hpp>

Step parse_notation(string notation)
{
    Step step;

    if (notation != "0-0-0" && notation != "0-0") {
        if (string("KQRBN").find(notation[0]) != -1)
            switch (notation[0]) {
            case 'K':
                step.piece = Figure::Piece::King;
                break;
            case 'Q':
                step.piece = Figure::Piece::Queen;
                break;
            case 'R':
                step.piece = Figure::Piece::Rook;
                break;
            case 'B':
                step.piece = Figure::Piece::Bishop;
                break;
            case 'N':
                step.piece = Figure::Piece::Knight;
                break;
            }
        else {
            step.piece = Figure::Piece::Pawn;
            notation.insert(0, "P");
        }
    }
    step.first.second = notation[1];
    step.first.first = (int)notation[2] - 49;

    step.last.first = (int)notation[5] - 49;
    step.last.second = notation[4];

    return step;
}