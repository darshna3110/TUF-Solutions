class Solution {
public:
    int countpages(vector<int>& nums, int k) {
        int student = 1;
        long long pages = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pages + nums[i] <= k) {
                pages += nums[i];
            } else {
                student++;
                pages = nums[i];
            }
        }

        return student;
    }

    int findPages(vector<int>& nums, int k) {
        int n = nums.size();

        // Not enough books to allocate one to each student
        if (k > n) {
            return -1;
        }

        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int cntno = countpages(nums, mid);

            if (cntno > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
