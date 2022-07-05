//https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i=0; i<nums.size(); ++i){
            map[nums[i]] = 1;
        }
        
        int longestStreak = 0;
        for(int i=0; i<nums.size(); ++i){
            if(!map.count(nums[i] - 1)){
                int curr = nums[i];
                int currStreak = 1;
                
                // cout << "nums[i]:" << nums[i] << endl;
                // cout << "map.count(curr):" << map.count(curr + 1) << endl;
                while(map.count(curr + 1)){
                    // cout << "map count:" << map.count(curr + 1) << endl;
                    curr++;
                    currStreak++;
                    // if(currStreak == 99) break;
                }
                longestStreak = max(currStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};
