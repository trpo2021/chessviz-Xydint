#include <ChessDesk.hpp>
#include <iostream>

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
        for (int j = 2; j < 6; j++)
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

void ChessDesk::add_desk_in_file(string notation, ofstream& file)
{
    file << R"!(<table class="chessboard">
    <caption>)!"
         << notation << R"!(</caption>)!";

    for (int i = 7; i >= 0; i--) {
        file << R"!(<tr>)!" << '\n';
        for (char j = 'a'; j <= 'h'; j++) {
            file << R"!(<td><span class=")!";
            file << desk[j][i].get_css_class();
            file << R"!("></span></td>)!" << '\n';
        }
        file << R"!(</tr>)!" << '\n';
    }
    file << R"!(</table>)!";
}

void ChessDesk::move_figure(char x1, int y1, char x2, char y2, Figure::Piece f)
{
    if (!(x1 >= 'a' && x1 <= 'h')) {
        cout << "err" << endl;
        throw 1;
    }
    if (!(x2 >= 'a' && x2 <= 'h')) {
        cout << "error" << endl;
        throw 2;
    }
    if (!(y1 >= 0 && y1 < 8)) {
        cout << "error" << endl;
        throw 3;
    }
    if (!(y2 >= 0 && y2 < 8)) {
        cout << "error" << endl;
        throw 4;
    }
    if (f != desk[x1][y1].get_piece()) {
        cout << "error" << f << " " << desk[x1][y1].get_piece() << endl;
        cout << x1 << " " << y1 << endl;
        cout << x2 << " " << y2 << endl << endl;
        throw 5;
    }
    desk[x2][y2] = desk[x1][y1];
    desk[x1][y1] = Figure(Figure::Not, Figure::None);
}