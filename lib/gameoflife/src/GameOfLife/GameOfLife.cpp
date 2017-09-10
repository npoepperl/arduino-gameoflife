#include <string.h>
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
    memset(&rows, 0x00, sizeof(rows));
}

Board::~Board(){
}

bool Board::HasLivingCells(){
    for(int row = 0; row < 8; row++){
        if(rows[row] != 0){
            return true;
        }
    }

    return false;
}

void Board::SetCellState(Position position, CellState cellState){
    if(cellState == Alive){
        rows[position.row] |= (0b10000000 >> position.column);
    }
    else{
        rows[position.row] &= ~(0b10000000 >> position.column);
    }
}

std::list<Position> Board::GetLivingCellsPositions(){
    std::list<Position> list;

    for(int row = FirstRow; row <= EighthRow; row++){
        for(int column = FirstColumn; column <= EighthColumn; column++){
            if(GetCellState(Position((Column)column, (Row)row)) == Alive){
                list.push_back(Position((Column)column, (Row)row));
            }
        }
    }
    
    return list;
}

CellState Board::GetCellState(Position position){
    return (rows[position.row] & (0b10000000 >> position.column)) == 0 ? Dead : Alive;
}

unsigned char Board::GetRowAsByte(Row row){
    return rows[row];
}