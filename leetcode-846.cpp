#include <iostream>
#include <vector>

using namespace std;

// hand = [[1,2,3,6,2,3,4,7,8], groupSize = 3
// [[1,2,3], [2,3,4], [6,7,8]]

bool helper(vector<int> &hand, int index){
    if(index >= hand.size()) return true;

    int firstItem = hand[index];
    for(int i=0; i<groupSize;i++){
        int currentItem = firstItem + i;
        // check if currentItem in hand
        auto it = find(hand.begin(), hand.end(), currentItem); 
        if(it == hand.end()) return false;
        else hand.erase(it);
    }
    return helper(hand, index);
}

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if(n % groupSize != 0) return false;
    // check if contain consecutive numbers per group
    sort(hand.begin(), hand.end());
    return helper(hand, 0);
}


void main(){};