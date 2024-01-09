#include<iostream>
using namespace std;

long long mod=1e9+7;
long long power(long long n,long long x)
{
    if(x==0)return 1;
    if(x&1)return n*power(n,x-1)%mod;
    else return power((n*n)%mod,x/2)%mod;
}
int main(){
    int n,x; 
    cin>>n>>x;
    cout<<power(n,x);
    
}