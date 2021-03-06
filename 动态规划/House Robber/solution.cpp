class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return nums[0];
        }
        int size = nums.size();
        int * maxMount = new int[size];
        maxMount[0] = nums[0];
        if(nums[1] > nums[0])
        {
            maxMount[1] = nums[1];
        }
        else
        {
            maxMount[1] = nums[0];
        }
        for(int i = 2 ; i < size ; i++)
        {
            int tmp = nums[i];
            int before = maxMount[i - 1];
            int before2 = maxMount[i - 2];
            if(tmp + before2 > before)
            {
                maxMount[i] = tmp + before2;
            }
            else
            {
                 maxMount[i] = before;
            }
        }
        return  maxMount[size - 1];
    }
};