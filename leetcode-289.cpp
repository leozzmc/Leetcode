#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> temp = board;
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 

    for(int row=0; row < rows; row++){
        for(int col=0; col<cols; col++){

            int liveNeighbors = 0;
            //set direction
            for(int d=0; d<directions.size(); d++){
                int newRow = row + directions[d][0];
                int newCol = col + directions[d][1];
                
                // check bounary
                if(newRow >=0 && newRow < rows && newCol >=0 && newCol < cols){
                    //apply rules
                    if(temp[newRow][newCol]==1){
                        liveNeighbors++;
                    }
                }
                if(liveNeighbors > 3){
                    board[row][col] = 0;
                }
                if(temp[row][col]==1 && (liveNeighbors<2)) board[row][col]=0;
                if(temp[row][col]==1 && (liveNeighbors==2 || liveNeighbors==3)) board[row][col]=1;
                if(temp[row][col]==0 && (liveNeighbors==3)) board[row][col]=1;
            }
        }
    }
}

void main(){};