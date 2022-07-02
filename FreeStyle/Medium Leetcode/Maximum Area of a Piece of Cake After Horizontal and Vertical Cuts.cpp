//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    
        sort(horizontalCuts.begin(), horizontalCuts.end(), [](int&a, int&b){
            return a > b;
        });
        sort(verticalCuts.begin(), verticalCuts.end(), [](int&a, int&b){
            return a > b;
        });
        int m = 1000000007;
        // h %= m;
        // w %= m;
        int mxHeight = (h - horizontalCuts[0]) % m;
        for(int i=1; i<horizontalCuts.size(); ++i){
            mxHeight = max(mxHeight, abs(horizontalCuts[i-1] - horizontalCuts[i]) % m);
        }
        mxHeight = max(mxHeight, abs(horizontalCuts[horizontalCuts.size() - 1] - 0) % m);
        
        int mxWidth = (w - verticalCuts[0]) % m;
        for(int i=1; i<verticalCuts.size(); ++i){
            mxWidth = max(mxWidth, abs(verticalCuts[i-1] - verticalCuts[i]) % m);
        }
        mxWidth = max(mxWidth, abs(verticalCuts[verticalCuts.size() - 1] - 0) % m);
        
        // cout << "mxHeight:" << mxHeight << endl;        
        // cout << "mxWidth:" << mxWidth << endl;
        
        // cout << mxHeight % m << endl;
        // cout << mxWidth % m << endl;
        // cout << ((long)mxHeight * mxWidth) % m << endl;
        return ((long)mxHeight * mxWidth) % m;
        // return ((mxHeight % temp) * (mxWidth % temp)) % temp;
    }
};
