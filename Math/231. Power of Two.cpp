//first method - Brute force

class Solution {
public:
    bool solve(int n){
        if(n==1)return true;
        if(n==0||n%2==1)return  false;
        return solve(n/2);
    }
    bool isPowerOfTwo(int n) {    
        return solve(n);       
    }
};

// second method optimal method Bit manipulation
//Observation -> If a number is power of two then there only one set bit 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return ((n&(n-1))==0);
    }
};