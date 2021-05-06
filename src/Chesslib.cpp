#include <Chesslib.hpp>

Step parse_notation(string notation)
{
    Step step;

    if (notation != "0-0-0" && notation != "0-0") {
        if (string("KQRBN").find(notation[0]) != -1)
            step.piece = notation[0];
        else {
            step.piece = 'P';
            notation.insert(0, "P");
        }
    }
    step.first.second = notation[1];
    step.first.first = (int)notation[2] - 49;

    step.last.first = (int)notation[5] - 49;
    step.last.second = notation[4];

    return step;
}