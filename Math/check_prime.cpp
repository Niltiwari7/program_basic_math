#include<iostream>
using namespace std;


bool check(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isprime(n))cout<<"Prime";
    else cout<<"Not prime";
}
