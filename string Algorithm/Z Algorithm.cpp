//brute force

vector<int>Zfunction(string s){
    int n = s.size();
    vector<int>z(n,0);
    for(int i = 1;i<n;i++){
        while(i+z[i]<n && s[i]==s[z[i]+i]){
            z[i]++;
        }
    }
    return z;
}


vector<int>z_function(string s){
    int n = s.size();
    int l = 0;
    int r = 0;
    for(int i=0;i<n;i++){
        if(i<r){
            z[i] = min(r-i,z[i-1]);
        }
        while(i+z[i]<n && s[i]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}
