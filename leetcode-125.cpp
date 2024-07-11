# include <iostream>
using namespace std;

bool isPalindrome(string input){
    bool isPalindrome = false;
    int length=0;
    if (input.size() %2 != 0){
        length = ((int)input.size()/2)+1;
    }
    else{
        length = ((int)input.size()/2);
    }
    for(int i=0; i<length;i++){
        if (input[i]!=input[input.size()-i-1]){
            cout << "No  palindrome" << endl;
            return false;
        }
        else{
            isPalindrome = true;
        }
    }
    return isPalindrome;
}

int main(){

    string question = "ab_a";
    string tempStr="";
    
    for(char c:question){
        if(c >= 48 && c<=57){
            tempStr+=c;
        }
        else if(c>= 65 && c<=90){
            tempStr+=c+32;
        }
        else if(c>=97 && c<=122){
            tempStr+=c;
            
        }
        
    }
    cout << tempStr << endl;
    
    // Check if it is palindrome
    
    cout << "Is is palindrome? " << isPalindrome(tempStr) << endl;

    return 0;
}