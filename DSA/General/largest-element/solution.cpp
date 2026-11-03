class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxi=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
            }
        }
        return maxi;
    }
};