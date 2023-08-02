#include<iostream>
using namespace std;

bool isprime(int n){
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(n%i==0)cnt++;
        if(cnt>1)return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isprime(n))cout<<"Prime";
    else cout<<"Not prime";
}