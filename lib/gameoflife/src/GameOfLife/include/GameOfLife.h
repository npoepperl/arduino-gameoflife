#include <list>

enum CellState{
    Dead = 1,
    Alive = 2
};

struct Position{

    Position(int column, int row);

    bool operator==(const Position &other);

    int column;
    int row;
};

class Board{
public:
    Board();
    ~Board();

    bool HasLivingCells();

    std::list<Position> GetLivingCellsPositions();

    void SetCellState(Position &position, CellState);
    bool GetCellState(int x, int y);

private:
    bool setWasCalled;
};
