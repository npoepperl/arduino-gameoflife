
enum CellState{
    Dead = 1,
    Alive = 2
};

class Position{
public:
    Position(int xCoordinate, int yCoordinate);

    int xCoordinate;
    int yCoordinate;
};


class Board{
public:
    Board();
    ~Board();

    void SetCellState(Position &position, CellState);
    bool GetCellState(int x, int y);
    
private:
    bool setWasCalled;
};
