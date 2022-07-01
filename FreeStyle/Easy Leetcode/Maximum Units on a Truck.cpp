//https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return b[1] < a[1];
        });
        // for(int i=0; i<boxTypes.size(); ++i){
        //     cout << boxTypes[i][0] << " " << boxTypes[i][1] << endl;
        // }
        int ans = 0;
        for(int i=0; i<boxTypes.size(); ++i){
            truckSize -= boxTypes[i][0];
            if(truckSize >= 0){
                ans += boxTypes[i][0] * boxTypes[i][1];
            }else{
                truckSize += boxTypes[i][0];
                ans += truckSize * boxTypes[i][1];
                break;
            }
            // cout << ans << endl;
            // cout << "truckSize:" << truckSize << endl;
        }
        return ans;
    }
};
