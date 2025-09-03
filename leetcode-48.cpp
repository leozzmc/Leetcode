#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    int counter = 0;
    while(counter <3){
        // reversed subVec
        for(int i=0; i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
            
        }
        //symmetric
        for(int i=0; i<n; i++){
            int temp=0;
            // only need to execute the lower-left triabgle
            for(int j=i; j<n; j++){
                if(i!=j){
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        counter++;
    }
}

void main(){


}