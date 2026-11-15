class Solution {
public:
     void merge(vector<int> &arr,int low,int mid,int high){
        int left=low;
        int right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                 temp.push_back(arr[right]);
                 right++;
            }
        }
        while(left<=mid){
             temp.push_back(arr[left]);
             left++;
        }
        while(right<=high){
             temp.push_back(arr[right]);
             right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
        void mergefun(vector<int> &nums,int low,int high){
        if (low>=high) return ;
        int mid=low+(high-low)/2;
        mergefun(nums,low,mid);
        mergefun(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> mergeSort(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        mergefun(nums,low,high);
        return nums;
    }
};
