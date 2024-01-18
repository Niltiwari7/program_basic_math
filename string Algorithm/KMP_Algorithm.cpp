// Brute Force-:
// Time Complexity = O(n*m)

// class Solution
// {
//     public:
//         vector <int> search(string pat, string txt)
//         {
//             //code hee.
//             vector<int>result;
           
//             for(int i = 0;i<txt.size();i++)
//             {
//                  bool flag = true;
//                 for(int j = 0;j<pat.size();j++){
//                     if(txt[i+j]!=pat[j]){
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag==true)result.push_back(i+1);
//             }
//             return result;
//         }
     
// };

// Optimal Solution-: 
// Time Complexity -: O(n+m)
//     KMP Algorithm
class KMP {
public:
    static std::vector<int> buildPrefixArray(const std::string& pattern) {
        int m = pattern.size();
        std::vector<int> prefixArray(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                prefixArray[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = prefixArray[len - 1];
                } else {
                    prefixArray[i] = 0;
                    i++;
                }
            }
        }

        return prefixArray;
    }

    static std::vector<int> search(const std::string& text, const std::string& pattern) {
        int n = text.size();
        int m = pattern.size();
        std::vector<int> prefixArray = buildPrefixArray(pattern);

        std::vector<int> positions;
        int i = 0, j = 0;

        while (i < n) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }

            if (j == m) {
                positions.push_back(i - j);
                j = prefixArray[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = prefixArray[j - 1];
                } else {
                    i++;
                }
            }
        }

        return positions;
    }
};
