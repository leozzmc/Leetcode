#include <iostream>
#include <list>
using namespace std;

void PrintList(const list<int>&lst){
    for (auto it = lst.begin(); it != lst.end(); ++it){
        cout << *it;
        // Next() is a function in STL, it could return the next address of the iterator.
        if(next(it) != lst.end()){
            cout << "->";
        }
    }
    cout << "-> NULL" << endl;
}

int main (){
    
    list<int> lst = {1,2,3};
    PrintList(lst);
    
    // Don't need to free memory manually, the STL will do it automatically

    return 0;
}

