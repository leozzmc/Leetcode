#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* TLE method */

// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int n = gas.size();
//     int startingPoint = 0;
//     while(startingPoint<n){
//         int tank = 0;
//         bool ok =true;
//         int offset = startingPoint;
//         for(int i=0; i<n; i++){
//             tank += gas[(i+offset)%n];
//             if(tank < cost[(i+offset)%n]){
//                 ok = false;
//                 break;
//             }
//             tank -= cost[(i+offset)%n];
//         }
//         if(ok) return startingPoint;
//         startingPoint++;
//     }
//     return -1;
// }

/*  Other method */

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n=cost.size();
    int tank = 0;
    int total = 0;
    int start = 0;


    for(int i=0; i<n; i++){
        int diff =  gas[i] - cost[i];
        tank +=diff;
        total +=diff;

        if(tank < 0){
            start = i+1;
            tank = 0;
        }
    }
    
    if(total >=0){
        return start%n;
    }
    else return -1;
}


void main(){};