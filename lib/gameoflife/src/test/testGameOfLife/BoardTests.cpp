#include "BoardTests.h"
#include "GameOfLife.h"


BoardTests::BoardTests(){

}

BoardTests::~BoardTests(){

}

TEST_F(BoardTests, GetCellState){
    Board board = Board();

    ASSERT_EQ(false, board.GetCellState(3, 3));
}

TEST_F(BoardTests, SetAndGetCellState){
    Board board = Board();

    Position position(3, 3);
    board.SetCellState(position, Alive);

    ASSERT_EQ(true, board.GetCellState(3, 3));
}
