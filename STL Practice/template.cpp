# include <iostream>
using namespace std;

//define template
template<typename T>
bool less_than(T a, T b){
    return a < b;
}

int main(){
    // input the typename into the template，and call the function
    cout << less_than<int>(10,20) << "\n";
    cout << less_than<string>("Hello", "World") << "\n";
    cout << less_than<bool>(false, true) << "\n";
    cout << less_than(0.2, 0.5) << "\n";
    return 0;
}