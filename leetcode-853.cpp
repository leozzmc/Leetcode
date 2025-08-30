#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars(n);
    double timeToTravel;
    for (int i=0; i<n; i++){
        timeToTravel = (double)(target - position[i]) /(double)speed[i];
        cars[i] ={position[i],timeToTravel};
    }
   sort(cars.begin(), cars.end());
   stack<double> fleetStack;
   for(int i=n-1; i>=0; i--){
     if(fleetStack.empty()){
        fleetStack.push(cars[i].second);
     } 
     else{
        if(cars[i].second > fleetStack.top()){
            fleetStack.push(cars[i].second);
        }
     }
   }
   return (int)fleetStack.size();
}

void main(){

}