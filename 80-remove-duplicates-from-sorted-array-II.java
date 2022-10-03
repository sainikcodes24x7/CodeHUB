class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int l = 0;
        int r = n-1;
        int count = 0;
        while(l < r)
        {
            if(nums[l+1] != nums[l]) {
                l++;
                count = 0;
            }
            else
            {
                if(count < 1) {
                    count++;
                    l++;
                }
                else {
                    if(l+1 < r) {
                        for(int j = l+2; j <= r; j++) {
                            nums[j-1] = nums[j];
                        }
                    }
                    r--;
                }
            }
        }
        return r+1;
    }
}
Console

