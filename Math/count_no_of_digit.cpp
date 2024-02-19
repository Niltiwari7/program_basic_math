#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt=0;//variable that store the number of digit
    while(n>0){
        cnt++;
        n/=10;
    }
    cout<<cnt;
}