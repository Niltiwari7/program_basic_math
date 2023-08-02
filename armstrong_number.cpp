#include<bits/stdc++.h>
using namespace std;

int cnt_digit(int n){
    int cnt=0;
    while(n>0){
        cnt++;
        n/=10;
    }
    return cnt;
}
bool check_armstrong(int n){
    int original_n = n; // Store the original value of n
    int sum = 0;
    int d = cnt_digit(n);
    while(n>0){
        int rem = n % 10;
        sum += pow(rem, d);
        n /= 10;
    }
    return sum == original_n; // Compare with the original value of n
}



int main(){
    int n;
    cin>>n;
    if(check_armstrong(n))
    cout<<"Armstrong";
    else cout<<"Not  armstrong";
}