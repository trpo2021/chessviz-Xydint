class Figure {
public:
    enum Color { Black, White };
    enum Piece { King, Queen, Rook, Knight, Bishop, Pawn, None };
    Figure(Color, Piece);

private:
    Color color;
    Piece piece;
};