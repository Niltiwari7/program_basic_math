class Solution {
public:
  vector<pair<int, int>> dir{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

    bool isValidCell(int x,int y,int m,int n){
        return 0<=x && x<m && 0<=y && y<n;
    }  

    bool isPrime(int num){
        if(num<2)return false;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
       unordered_map<int,int>mp;

       int m = mat.size();
       int n = mat[0].size();

       for(int i = 0;i<m;i++){
           for(int j = 0;j<n;j++){
               for(auto d:dir){
                   vector<char>sb;
                   int x = i;
                   int y = j;
                   while(isValidCell(x,y,m,n)){
                       sb.push_back(mat[x][y]+'0');
                       int num = stoi(string(sb.begin(),sb.end()));
                       if(num>10 && isPrime(num)){
                           mp[num]++;
                       }
                       x +=d.first;
                       y+=d.second;
                   }
               }
               
           }
       } 
       int maxFreq = 0;
       int maxPrime = -1;
       for(auto it:mp){
           int prime = it.first;
           int freq = it.second;
           if(freq>maxFreq || (freq==maxFreq)&& prime>maxPrime){
               maxFreq = freq;
               maxPrime = prime;
           }
       } 
       return maxPrime;
    }
};