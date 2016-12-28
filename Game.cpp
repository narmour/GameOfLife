#include <iostream>
#include "unistd.h"
#include "Game.h"

Game::Game(){

    grid = new bool*[NUM_ROW];

    for(int i =0;i <NUM_ROW;i++)
        grid[i] = new bool[NUM_COL];

    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;
    grid[1][3] =1;
    grid[0][2] = 1;

}

bool isValid(int i,int j){
    return ((i+1) <=9 && (i-1 >=0) && (j+1)<=9 && j-1 >=0);
}



int Game::countNeighbors(bool **cells,int i,int j){
     int n =0;
    
     //upper left corner
     if(i -1 >=0 && j-1 >=0 &&cells[i-1][j-1])
         n++;

     //up
     if(i-1 >=0&&cells[i-1][j])
         n++;

     //upper right corner
     if(i-1 >=0 && j+1 <=9&&cells[i-1][j+1])
         n++;

     //right
     if(j+1 <=9&&cells[i][j+1])
         n++;

     //bottom right corner
     if(i+1 <=9 && j+1 <=9 &&cells[i+1][j+1])
         n++;

     //bottom
     if(i+1 <=9 &&cells[i+1][j])
         n++;

     //bottom left
     if(i+1 <=9 && j-1>=0 &&cells[i+1][j-1])
         n++;

     //left
     if(j-1 >=0 &&cells[i][j-1])
         n++;




    return n;
}

bool** Game::tick(bool **cells){
    //init return array
    bool** state = new bool*[NUM_COL];
    for(int i =0;i <NUM_ROW;i++)
        state[i] = new bool[NUM_COL];
    

    // update each cell sequentially
    
    
    for(int i =0;i <NUM_ROW;i++){
        for(int j=0;j<NUM_COL;j++){
            int n = countNeighbors(cells,i,j);
            // if the cell is alive
            if(cells[i][j]){
                if(n==2 || n==3)
                    state[i][j] =1;
                else
                    state[i][j]==0;
            }
            //if dead with 3 neighbors
            else if(n==3)
                state[i][j]=1;
            // its dead
            else
                state[i][j]=0;
        }
    }

    //return new state
    return state;
}


void printState(bool **cells){
    for(int i =0;i<NUM_ROW;i++){
        for(int j=0;j<NUM_COL;j++){
            if(cells[i][j])
                std::cout << "x    ";
            else
                std::cout << "o    ";
        }
        std::cout << std::endl;
    }
        std::cout << std::endl << std::endl;
}





int main(){
    Game g;

    while(true){
        printState(g.grid);
        g.grid= g.tick(g.grid);
        sleep(2);
    }
    

    return 0;
}
