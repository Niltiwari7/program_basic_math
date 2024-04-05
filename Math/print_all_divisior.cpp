#include<iostream>
using namespace std;

void print_divisors(int n) {
        // Code here.
        vector<int>ans;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                ans.push_back(i);
                if(n/i!=i)ans.push_back(n/i);
            }
        }
        sort(begin(ans),end(ans));
        for(auto it:ans)cout<<it<<" ";
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<endl;
    }
}


