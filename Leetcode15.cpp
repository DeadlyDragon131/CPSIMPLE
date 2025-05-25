#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i = 0;i < nums.size();i++){
             if(i > 0 && nums[i] == nums[i-1]){
                    continue;
                }
            int a = nums[i];
            int l = i+1, r = nums.size()-1;
            while(l < r){
               
                int threesum = a + nums[l] + nums[r];
                if(threesum > 0){
                    r--;
                }
                else if(threesum < 0){
                    l++;
                }
                else{
                    v.push_back({a,nums[l],nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                }

            }
           

        }
        return v;
    }
};