class Figure {
public:
    enum Color { Black, White, Not };
    enum Piece { King, Queen, Rook, Knight, Bishop, Pawn, None };
    Figure();
    Figure(Color, Piece);

private:
    Color color;
    Piece piece;
};