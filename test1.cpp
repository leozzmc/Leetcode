class Solution {
public:
    // 1 <= n <= 1690
    int num=1;
    int counter=0;
    int divider=0;
    bool isUgly(int num){
        if(num != 1){    
            while(num !=0){
                if(num % 2 == 0){
                    num = num / 2;
                    if(num == 1) return true;
                } 
                else if(num % 3 == 0){ 
                    num = num / 3;
                    if(num == 1) return true;
                }
                else if(num % 5 == 0 ){
                    num =  num / 5;
                    if(num == 1) return true;
                }
                else {
                    // number contain prime factor other than 2, 3 and 5

                    cout << "No valid factor:" << endl;
                    return false;
                }
            }
            //num=0
            return true;
        }
        else return true;
    }

    int nthUglyNumber(int n) {
       
       // a loop to increase number
            // calling isUgly to check if it is ugly number
            // if return is true, than counter add 1
            // if counter == n, thenreturn result

        while( counter < n){
            cout << "Checking if '" << num << "' is valid ";
            if(isUgly(num)){
                counter++;
                cout << num << "is valid" << endl; 
                if(counter == n) break;
            }
            num++;
        }
        // counter == n
        return num;
    }
};