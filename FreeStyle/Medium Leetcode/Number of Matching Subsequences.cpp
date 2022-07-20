//https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha(26);
        for(int i=0; i<s.size(); ++i){
            alpha[s[i] - 'a'].push_back(i);
        }      

        int numFound = 0;
        for(const auto& word:words){
            int currInd = -1;
            bool found = 1;

            for(char c:word){
                auto it = upper_bound(alpha[c - 'a'].begin(), alpha[c - 'a'].end(), currInd);
                if(it == alpha[c - 'a'].end()){
                    found = 0;
                    break;
                }else{
                    currInd = *it;
                }
            }

            if(found) numFound++;
        }
        return numFound;
    }
};
