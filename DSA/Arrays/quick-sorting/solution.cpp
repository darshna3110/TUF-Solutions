class Solution {
public:
    int partion(vector<int> &nums,int low,int high){
        int pivot=nums[low];
        int i=low;
        int j=high;
        while(i<j){
            while( i<=high &&nums[i]<=pivot){
                i++;
            }
            while(j>=low && nums[j]>pivot){
                j--;
            }
            if(i<j) swap(nums[i],nums[j]);

        }
        swap(nums[j],nums[low]);
        return j;

    }
    void qs(vector<int> &nums,int low,int high){
        if(low<high){
            int part=partion(nums,low,high);
            qs(nums,low,part-1);
            qs(nums,part+1,high);
        }
    }
    vector<int> quickSort(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        qs(nums,low,high);
        return nums;
    }
};
