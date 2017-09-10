#include "BoardTests.h"
#include <algorithm>
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

    Position position(FourthColumn, FourthRow);
    board.SetCellState(position, Alive);

    ASSERT_EQ(true, board.HasLivingCells());
}

TEST_F(BoardTests, AssertThatOneLivingCellsPositionIsRetreivedAsList){
    Board board = Board();

    Position position(FirstColumn, ThirdRow);

    board.SetCellState(position, Alive);

    std::list<Position> living = board.GetLivingCellsPositions();

    EXPECT_FALSE(living.empty());

    for(std::list<Position>::iterator iter = living.begin(); iter != living.end(); iter++){
        ASSERT_EQ(true, position == *iter);
    }
}

TEST_F(BoardTests, AssertThatMultipleLivingCellsPositionsAreRetreivedAsList){
    Board board = Board();

    std::list<Position> positions;
    positions.push_back(Position(FirstColumn, ThirdRow));
    positions.push_back(Position(ThirdColumn, ThirdRow));
    positions.push_back(Position(FifthColumn, SeventhRow));
    positions.push_back(Position(FifthColumn, EighthRow));

    for(std::list<Position>::iterator iter = positions.begin(); iter != positions.end(); iter++){
        board.SetCellState(*iter, Alive);
        ASSERT_EQ(Alive, board.GetCellState(*iter));
    }

    std::list<Position> living = board.GetLivingCellsPositions();

    EXPECT_FALSE(living.empty());
    ASSERT_EQ(positions.size(), living.size());

    for(std::list<Position>::iterator iter = living.begin(); iter != living.end(); iter++){
        std::list<Position>::iterator result = std::find(positions.begin(), positions.end(), *iter);
        ASSERT_TRUE(result != positions.end());
    }
}

TEST_F(BoardTests, AssertThatCellIsDead){
    Board board = Board();
    ASSERT_EQ(Dead, board.GetCellState(Position(ThirdColumn, ThirdRow)));
}

TEST_F(BoardTests, AssertThatTheStateOfOneCellCanBeSetAndRetreived){
    Board board = Board();

    Position position(ThirdColumn, ThirdRow);
    board.SetCellState(position, Alive);

    ASSERT_EQ(Alive, board.GetCellState(position));
}

TEST_F(BoardTests, AssertThatTheStateOfMultipleCellCanBeSetAndRetreived){
    Board board = Board();

    std::list<Position> positions;
    positions.push_back(Position(FirstColumn, ThirdRow));
    positions.push_back(Position(ThirdColumn, ThirdRow));
    positions.push_back(Position(FifthColumn, SeventhRow));
    positions.push_back(Position(FifthColumn, EighthRow));

    for(std::list<Position>::iterator iter = positions.begin(); iter != positions.end(); iter++){
        board.SetCellState(*iter, Alive);
        ASSERT_EQ(Alive, board.GetCellState(*iter));
    }
}

TEST_F(BoardTests, AssertThatLivingCellCanBeSetAsDead){
    Board board = Board();

    Position position(FirstColumn, FourthRow);

    board.SetCellState(Position(FirstColumn, FourthRow), Alive);
    EXPECT_EQ(Alive, board.GetCellState(position));

    board.SetCellState(Position(FirstColumn, FourthRow), Dead);
    EXPECT_EQ(Dead, board.GetCellState(position));
}

TEST_F(BoardTests, AssertThatRowOfEmptyBoardIsEmpty){
    Board board = Board();
    
    ASSERT_EQ(0b00000000, board.GetRowAsByte(FirstRow));
}

TEST_F(BoardTests, AssertThatByteValueOfRowMatchesSetCellStates){
    Board board = Board();

    board.SetCellState(Position(ThirdColumn, FirstRow), Alive);

    ASSERT_EQ(0b00100000, board.GetRowAsByte(FirstRow));
}
