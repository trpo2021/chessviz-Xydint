#include <ChessDesk.hpp>
#include <Chesslib.hpp>
#include <Figure.hpp>
#include <gtest.h>

class TChessDesk : public ChessDesk {
public:
    Figure get_figure(char x, int y)
    {
        return desk[x][y];
    }
};

TEST(chessDesk, move_figure)
{
    // Arrange
    TChessDesk desk;
    Figure exp_fig(Figure::White, Figure::Pawn);
    Figure real_1, real_2;

    // Act
    desk.move_figure('e', 1, 'e', 3, Figure::Pawn);
    real_1 = desk.get_figure('e', 3);
    real_2 = desk.get_figure('e', 1);

    // Assert
    ASSERT_EQ(real_1.get_piece(), exp_fig.get_piece());
    ASSERT_EQ(real_2.get_piece(), Figure::None);
}

TEST(ChessLib, parse_notation)
{
    // Arrange
    string notation = "e2-e4";
    Step step;

    // Act
    step = parse_notation(notation);

    // Assert
    EXPECT_EQ(step.first.first, 'e');
    EXPECT_EQ(step.first.second, 1);
    EXPECT_EQ(step.last.first, 'e');
    EXPECT_EQ(step.last.second, 3);
    EXPECT_EQ(step.piece, Figure::Pawn);
}

TEST(Figure, get_css_class)
{
    // Arrange
    Figure Pawn(Figure::White, Figure::Pawn);
    Figure Queen(Figure::Black, Figure::Queen);
    Figure None(Figure::Not, Figure::None);
    string pawn, queen, none;
    // Act
    pawn = Pawn.get_css_class();
    queen = Queen.get_css_class();
    none = None.get_css_class();

    // Assert
    EXPECT_EQ(pawn, "white pawn");
    EXPECT_EQ(queen, "black queen");
    EXPECT_EQ(none, "");
}