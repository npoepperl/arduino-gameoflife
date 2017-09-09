#include "BoardTests.h"
#include "GameOfLife.h"

class Board{
public:
    Board(){

    }

    ~Board(){

    }

    void SetCellState(int, int, bool){

    }

    bool GetCellState(int, int){
        return true;
    }
};

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

    board.SetCellState(3, 3, true);

    ASSERT_EQ(true, board.GetCellState(3, 3));
}
