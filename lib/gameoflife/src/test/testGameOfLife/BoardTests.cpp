#include "BoardTests.h"
#include "GameOfLife.h"

enum CellState{
    Dead = 1,
    Alive = 2
};

class Position{
public:
    Position(int xCoordinate, int yCoordinate){
        this->xCoordinate = xCoordinate;
        this->yCoordinate = yCoordinate;
    }

    int xCoordinate;
    int yCoordinate;
};

class Board{
public:
    Board(){
        setWasCalled = false;
    }

    ~Board(){

    }

    void SetCellState(Position &position, CellState){
        setWasCalled = true;
    }

    bool GetCellState(int x, int y){
        if(setWasCalled == true){
            return true;
        }

        return false;
    }

private:
    bool setWasCalled;
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

    Position position(3, 3);
    board.SetCellState(position, Alive);

    ASSERT_EQ(true, board.GetCellState(3, 3));
}
