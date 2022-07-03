//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0) return ans;
        else if(strs[0].size() == 0) return ans;
        else if(strs.size() == 1) return strs[0];
        
        int j=0;
        bool flag = 0;
        while(1){
            for(int i=1; i<strs.size(); ++i){
                if(j >= strs[i-1].size() || j >= strs[i].size() || strs[i-1][j] != strs[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
            j++;
        }
        
        for(int i=0; i<j; ++i){
            ans += strs[0][i];
        }
        return ans;
    }
};
