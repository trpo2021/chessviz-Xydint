#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    string input;
    fstream file;
    list<string> notations;

    //Интерпретация параметров программы
    if (argc == 2) {
        file.open(argv[1]);
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
}