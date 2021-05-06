#include <ChessDesk.hpp>
#include <Chesslib.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ChessDesk desk;
    Step step;
    string input;
    fstream file;
    list<string> notations;

    //Интерпретация параметров программы
    if (argc == 2) {
        file.open(argv[1], fstream::in);
        if (!file.is_open())
            return 1;
    } else
        return 1;

    //Чтение введенных данных из файла
    while (true) {
        file >> input;
        file >> input;
        notations.push_back(input);
        if (file.eof())
            break;
        file >> input;
        notations.push_back(input);
        if (file.eof())
            break;
    }
    notations.pop_back();
    file.close();

    ofstream fout;
    fout.open("./chess.html");
    if (!fout.is_open())
        return 1;
    fout << R"!(<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>chessviz</title>
  <style type="text/css">
    table.chessboard {
      border: 5px solid #333;
      border-collapse: collapse;
      height: 320px;
      margin: 20px;
      width: 320px;
    }
    table.chessboard caption {
      text-align: left;
    }
    table.chessboard td {
      background-color: #fff;
      font-size: 25px;
      height: 40px;
      text-align: center;
      vertical-align: middle;
      width: 40px;
    }
    table.chessboard tr:nth-child(odd) td:nth-child(even),
    table.chessboard tr:nth-child(even) td:nth-child(odd) {
      background-color: #999;
    }

    table.chessboard .white.king:before   { content: "\2654"; }
    table.chessboard .white.queen:before  { content: "\2655"; }
    table.chessboard .white.rook:before   { content: "\2656"; }
    table.chessboard .white.bishop:before { content: "\2657"; }
    table.chessboard .white.knight:before { content: "\2658"; }
    table.chessboard .white.pawn:before   { content: "\2659"; }

    table.chessboard .black.king:before   { content: "\265A"; }
    table.chessboard .black.queen:before  { content: "\265B"; }
    table.chessboard .black.rook:before   { content: "\265C"; }
    table.chessboard .black.bishop:before { content: "\265D"; }
    table.chessboard .black.knight:before { content: "\265E"; }
    table.chessboard .black.pawn:before   { content: "\265F"; }
  </style>
</head>
<body>
)!";
    desk.add_desk_in_file("zxcv", fout);

    for (auto it = notations.begin(); it != notations.end(); ++it) {
        step = parse_notation(*it);
        try {
            desk.move_figure(
                    step.first.first,
                    step.first.second,
                    step.last.first,
                    step.last.second,
                    step.piece);
        } catch (const int a) {
            cout << a << endl;
        }

        desk.add_desk_in_file(*it, fout);
    }
    cout << 10;
    fout << "\n</body>\n</html>";
    fout.close();
}