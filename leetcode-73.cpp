#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* Solution-1 O(m+n) space */
void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> Row;
    vector<int> Col;

    //Check 0 elements
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==0){
                Row.push_back(i);
                Col.push_back(j);
            }
        }
    }

    sort(Row.begin(), Row.end());
    sort(Col.begin(), Col.end());

    for(auto it=Row.begin();it!=Row.end(); ++it){
        for(int j=0; j<n; ++j){
            matrix[*it][j]=0;
        }
    }
    for(auto it=Col.begin();it!=Col.end(); ++it){
        for(int i=0; i<m; ++i){
            matrix[i][*it]=0;
        }
    }         
}


/* Solution-2 O(1) space */

void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col0 = 1;

        //Check 0 elements
        for(int i=0; i<m; i++){
            if(matrix[i][0]==0) col0=0;
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i= m-1; i>=0; i--){
            for(int j=n-1; j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j]==0) matrix[i][j]=0;
            }
            if(col0 == 0) matrix[i][0] =0;
        }          
    }


void main(){

}