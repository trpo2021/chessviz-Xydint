#include <ChessDesk.hpp>

#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ChessDesk desk;
    string input;
    string save_path;
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
    file.close();

    file.open("./chess.html", fstream::out);
    if (!file.is_open()) {
        cout << "err";
        return 1;
    }
    file << R"!(<!DOCTYPE html>
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
    desk.add_desk_in_file("zxcv", file);
    //Место для логики

    file << "\n</body>\n</html>";
    file.close();
}