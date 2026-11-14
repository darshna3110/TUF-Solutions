class Solution {
public:
    void rotateArrayByOne(vector<int>& arr) {
        int n=arr.size();
        int temp=arr[0];
        for(int i=0;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        arr[n-1]=temp;

    }
};