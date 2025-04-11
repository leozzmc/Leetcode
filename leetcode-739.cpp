#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> dailyTemperatures(vector<int>& temperatures){
    if(temperatures.size()==1) return {0};
    vector<int> returnVec(temperatures.size(), 0);
    //Store vector index
    stack<int> tempStack;
    for(int i=0; i<temperatures.size(); i++){
        while(!tempStack.empty() && temperatures[i] > temperatures[tempStack.top()]){
            int prevIndex = tempStack.top();
            tempStack.pop();
            returnVec[prevIndex] = i - prevIndex;
        }
        tempStack.push(i);
    }
    return returnVec;
}


int main(){

    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> resultVec = dailyTemperatures(temperatures);
    //print return vec
    for(auto it=resultVec.begin(); it!=resultVec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}