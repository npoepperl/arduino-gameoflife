#include <iostream>
#include "include/GameOfLife.h"

Position::Position(int xCoordinate, int yCoordinate){
}

Board::Board(){
    setWasCalled = false;
}

Board::~Board(){
}

void Board::SetCellState(Position &position, CellState){
    setWasCalled = true;
}

bool Board::GetCellState(int x, int y){
    if(setWasCalled == true){
        return true;
    }

    return false;
}
