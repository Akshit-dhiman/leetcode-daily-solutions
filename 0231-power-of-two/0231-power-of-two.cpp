class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long num = 1;

        while(num<= n){
            if(num == n) return true;
            num*=2;
        }
        return false;
    }
};