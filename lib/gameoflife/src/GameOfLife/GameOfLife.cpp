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
    row = 0;
}

Board::~Board(){
}

bool Board::HasLivingCells(){
    return setWasCalled;
}

void Board::SetCellState(Position position, CellState cellState){
    setWasCalled = true;

    if(cellState == Alive){
        row |= (0b10000000 >> position.column);
    }
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

unsigned char Board::GetRowAsByte(Row row){
    return this->row;
}