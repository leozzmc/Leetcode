#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> numCount(20001, 0);
    //store the frequency of each number
    for(int n: nums){
        numCount[n+10000]++;
    }
    auto comparator = [](pair<int, int> &leftPair, pair<int, int>&rightPair){
        return leftPair.second < rightPair.second;
    }
    priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comparator)> freqHeap(comparator);

    //push to heap
    for(int i=0; i<numCount.size(); i++){
        if(numCount[i]>0){
            // since the first element of the pair is the number itself, we need to convert it back
            freqHeap.push({i-10000, numCount[i]});
        }
    }
    vector<int> result;
    while(!freqHeap.empty() && k>0){
        result.push_back(freqHeap.top().first);
        freqHeap.pop();
        k--;
    }
    return result;
}

void main(){

};