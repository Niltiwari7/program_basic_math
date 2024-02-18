//method 1 Brute force- Prefix function
bool isPrefix(string s1,string s2){
    int n = s1.size();
    return s1==s2.substr(0,n);
}

//method 1 Brute force- Suffix function
bool isSuffix(string s1,string s2){
        int len = s1.size();
        int n = s2.size(); 
        return s1==s2.substr(n-len,len);
}



