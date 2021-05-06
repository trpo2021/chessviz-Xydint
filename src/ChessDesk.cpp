#include <ChessDesk.hpp>

ChessDesk::ChessDesk()
{
    desk['a'][7] = Figure(Figure::Black, Figure::Rook);
    desk['b'][7] = Figure(Figure::Black, Figure::Knight);
    desk['c'][7] = Figure(Figure::Black, Figure::Bishop);
    desk['d'][7] = Figure(Figure::Black, Figure::Queen);
    desk['e'][7] = Figure(Figure::Black, Figure::King);
    desk['f'][7] = Figure(Figure::Black, Figure::Bishop);
    desk['g'][7] = Figure(Figure::Black, Figure::Knight);
    desk['h'][7] = Figure(Figure::Black, Figure::Rook);
    for (int i = 'a'; i <= 'h'; i++)
        desk[i][6] = Figure(Figure::Black, Figure::Pawn);
    for (int i = 'a'; i <= 'h'; i++)
        for (int j = 0; j < 8; j++)
            desk[i][j] = Figure(Figure::Not, Figure::None);
    for (int i = 'a'; i <= 'h'; i++)
        desk[i][1] = Figure(Figure::White, Figure::Pawn);
    desk['a'][0] = Figure(Figure::White, Figure::Rook);
    desk['b'][0] = Figure(Figure::White, Figure::Knight);
    desk['c'][0] = Figure(Figure::White, Figure::Bishop);
    desk['d'][0] = Figure(Figure::White, Figure::Queen);
    desk['e'][0] = Figure(Figure::White, Figure::King);
    desk['f'][0] = Figure(Figure::White, Figure::Bishop);
    desk['g'][0] = Figure(Figure::White, Figure::Knight);
    desk['h'][0] = Figure(Figure::White, Figure::Rook);
}