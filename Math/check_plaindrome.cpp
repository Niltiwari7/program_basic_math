#include<iostream>
using namespace std;

int rev(int n){
    int rev_digit=0;
    while(n>0){
        rev_digit=(rev_digit*10)+(n%10);
        n/=10;
    }    
    return rev_digit;
}
int main(){
    int n;
    cin>>n;
    int rev_digit=rev(n);
    if(rev_digit==n)cout<<"Plaindrome";
    else cout<<" Not Plaindrome";
}