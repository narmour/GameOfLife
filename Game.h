#define NUM_ROW 10
#define NUM_COL 10
class Game{



    public:
        // grid cells
        bool **grid;

        Game();
        int countNeighbors(bool **cells,int i,int j);
        bool** tick(bool **cells);




};


