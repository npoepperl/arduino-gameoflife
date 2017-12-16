#include <list>

enum Column{
    FirstColumn = 0,
    SecondColumn = 1,
    ThirdColumn = 2,
    FourthColumn = 3,
    FifthColumn = 4,
    SixthColumn = 5,
    SeventhColumn = 6,
    EighthColumn = 7
};

enum Row{
    FirstRow = 0,
    SecondRow = 1,
    ThirdRow = 2,
    FourthRow = 3,
    FifthRow = 4,
    SixthRow = 5,
    SeventhRow = 6,
    EighthRow = 7
};

enum CellState{
    Dead = 1,
    Alive = 2
};

struct Position{

    Position(Column column, Row row);

    bool operator==(const Position &other);

    Column column;
    Row row;
};

class Board{
public:
    Board();
    ~Board();

    bool HasLivingCells();

//    std::list<Position> GetLivingCellsPositions();

    void SetCellState(Position position, CellState cellState);
    CellState GetCellState(Position position);

    unsigned char GetRowAsByte(Row row);
private:
    unsigned char rows[8];
};
