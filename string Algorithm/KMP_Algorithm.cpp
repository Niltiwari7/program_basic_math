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