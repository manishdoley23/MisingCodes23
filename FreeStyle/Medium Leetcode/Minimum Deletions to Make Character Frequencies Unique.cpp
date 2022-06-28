//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> vec(26);
        for(int i=0; i<s.size(); ++i){
            vec[s[i] - 'a']++;
        }
        sort(vec.begin(), vec.end(), [](int a,int b){return a>b;});
        int ans = 0;
        int f = vec[0];
        for(int i=0; i<vec.size(); ++i){
            if(vec[i] > f){
                if(f > 0) ans += vec[i] - f;
                else ans += vec[i];
            }
            f = min(f-1, vec[i]-1);
        }
        return ans;
    }
};
