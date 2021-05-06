#include <Figure.hpp>
#include <map>

using namespace std;

class ChessDesk {
public:
    ChessDesk();

protected:
    map<char, Figure[8]> desk;
};