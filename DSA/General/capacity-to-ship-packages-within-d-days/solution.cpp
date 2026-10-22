class Solution {
public:
    int cal_day(vector<int> &w,int mid){
        int load=0;
        int days=1;
        int n=w.size();
        for(int i=0;i<n;i++){
            if(load+w[i]>mid){
                days+=1;
                load=w[i];
            }
            else{
                load+=w[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& w, int d) {
       int low=*max_element(w.begin(),w.end());
       int high=accumulate(w.begin(),w.end(),0);
       while(low<=high){
        int mid=low+(high-low)/2;
        int req_day=cal_day(w,mid);
        if(req_day<=d){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return low;
    }
};