//https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return 0;
        
        int s1len = s1.size();
        int s2len = s2.size();
        
        vector<int> h1(26, 0);
        vector<int> h2(26, 0);
        
        int left=0, right=0;
        while(right < s1len){
            h1[s1[right] - 'a']++;
            h2[s2[right] - 'a']++;
            right++;
        }
        right -= 1;
        while(right < s2len){
            if(h1 == h2) return 1;
            right += 1;
            
            if(right != s2len){
                h2[s2[right] - 'a'] += 1;
            }
            h2[s2[left] - 'a'] -= 1;
            left += 1;
        }
        return 0;
    }
};
