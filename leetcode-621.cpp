#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int leastInterval(vector<char>& tasks, int n) {
    priority_queue<int> maxHeap;
    vector<int> charCount(26, 0);
    for(char c: tasks){
        charCount[c-'A']++;
    }
    sort(charCount.begin(), charCount.end());
    for(int i=0; i<charCount.size(); i++){
        if(charCount[i]>0){
            maxHeap.push(charCount[i]);
        }
    }
    
    int intervals=0;

    while(!maxHeap.empty()){
        vector<int> temp;
        int cycle = n+1;
        while(cycle>0 && !maxHeap.empty()){
            int count = maxHeap.top();
            if(count-1 > 0 )temp.push_back(count-1);
            maxHeap.pop();
            intervals++;
            cycle--;
        }

        for(int t: temp){
            maxHeap.push(t);
        }
        //pedding idles
        if (!maxHeap.empty()) {
            intervals += cycle;
        }
    }

    return intervals;
}



void main(){};