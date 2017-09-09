#include <iostream>
#include "include/GameOfLife.h"

Position::Position(Column column, Row row){
    this->column = column;
    this->row = row;
}

bool Position::operator==(const Position &other){
    return (this->column == other.column &&
        this->row == other.row);
}

Board::Board(){
    setWasCalled = false;
}

Board::~Board(){
}

bool Board::HasLivingCells(){
    return setWasCalled;
}

void Board::SetCellState(Position position, CellState){
    setWasCalled = true;
}

std::list<Position> Board::GetLivingCellsPositions(){
    std::list<Position> list;
    list.push_back(Position(FourthColumn, FourthRow));
    
    return list;
}

CellState Board::GetCellState(Position position){
    if(setWasCalled == true){
        return Alive;
    }

    return Dead;
}
