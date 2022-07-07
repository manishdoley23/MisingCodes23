//https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    unordered_map<string, bool> umap;
    bool check(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3){
        if(p3 == len3){
            return (p1 == len1 && p2 == len2)?true:false;
        }
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if(umap.find(key) != umap.end()){
            return umap[key];
        }
        
        if(p1 == len1){
           bool temp;
            temp = s2[p2] == s3[p3];
            if(temp){
                temp = check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
            }
            umap[key] = temp;
            return umap[key];
        }
        
        if(p2 == len2){
            bool temp;
            temp = s1[p1] == s3[p3];
            if(temp){
                temp = check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
            }
            umap[key] = temp;
            return umap[key];
        }
        
        bool choice1, choice2;
        choice1 = choice2 = 0;
        if(s1[p1] == s3[p3]){
            choice1 = check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
        }
        if(s2[p2] == s3[p3]){
            choice2 = check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
        }
        
        bool temp = choice1 || choice2;
        umap[key] = temp;
        return umap[key];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n3 != n1+n2) return 0;
        
        return check(s1, s2, s3, n1, n2, n3, 0, 0, 0);
    }
};
