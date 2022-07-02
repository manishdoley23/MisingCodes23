//https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int conv(char x){
        if(x == 'I') return 1;
        else if(x == 'V') return 5;
        else if(x == 'X') return 10;
        else if(x == 'L') return 50;
        else if(x == 'C') return 100;
        else if(x == 'D') return 500;
        else return 1000;
    }
    
    int romanToInt(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); ++i){
            if(i > 0 && (s[i-1] == 'I' && s[i] == 'X' || 
            s[i-1] == 'I' && s[i] == 'V' || s[i-1] == 'X' && s[i] == 'L' || 
            s[i-1] == 'X' && s[i] == 'C' || s[i-1] == 'C' && s[i] == 'D' ||
            s[i-1] == 'C' && s[i] == 'M')){
                sum -= conv(s[i-1]);
                sum = sum + (conv(s[i]) - conv(s[i-1]));
                // cout << i << " " << sum << endl;
                continue;
            }
            sum += conv(s[i]);
            // cout << i << " " << sum << endl;
        }
        return sum;
    }
};
