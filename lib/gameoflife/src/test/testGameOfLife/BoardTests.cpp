#include "BoardTests.h"
#include "GameOfLife.h"


BoardTests::BoardTests(){

}

BoardTests::~BoardTests(){

}

TEST_F(BoardTests, AssertThatNewBoardIsEmpty){
    Board board = Board();

    ASSERT_EQ(false, board.HasLivingCells());
}

TEST_F(BoardTests, AssertThatBoardWithLivingCellIsNotEmpty){
    Board board = Board();

    Position position(4, 4);
    board.SetCellState(position, Alive);

    ASSERT_EQ(true, board.HasLivingCells());
}

TEST_F(BoardTests, AssertThatOneLivingCellsPositionIsRetreivedAsList){
    Board board = Board();

    Position position(4, 4);

    board.SetCellState(position, Alive);

    std::list<Position> living = board.GetLivingCellsPositions();

    EXPECT_FALSE(living.empty());

    for(std::list<Position>::iterator iter = living.begin(); iter != living.end(); iter++){
        ASSERT_EQ(true, position == *iter);
    }
}

TEST_F(BoardTests, AssertThatCellIsDead){
    Board board = Board();
    ASSERT_EQ(Dead, board.GetCellState(Position(3, 3)));
}

TEST_F(BoardTests, AssertThatTheStateOfOneCellCanBeSetAndRetreived){
    Board board = Board();

    Position position(3, 3);
    board.SetCellState(position, Alive);

    ASSERT_EQ(Alive, board.GetCellState(position));
}

TEST_F(BoardTests, AssertThatTheStateOfMultipleCellCanBeSetAndRetreived){
    Board board = Board();

    std::list<Position> positions;
    positions.push_back(Position(1, 3));
    positions.push_back(Position(3, 3));
    positions.push_back(Position(5, 7));
    positions.push_back(Position(3, 7));

    for(std::list<Position>::iterator iter = positions.begin(); iter != positions.end(); iter++){
        board.SetCellState(*iter, Alive);
        ASSERT_EQ(Alive, board.GetCellState(*iter));
    }

}