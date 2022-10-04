class Solution {
    public void moveZeroesApproach1(int[] nums) {
        
    // cool technique: sliding window, window size is equal to numberOfZeroes
    
        if(nums.length == 0)
            return;
        
        int windowSize = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] == 0){
                windowSize++;
            }else{
                int temp = nums[i];
                nums[i] = 0;
                nums[i-windowSize] = temp;
            }
        }
        
    }



class Solution {
    public void moveZeroesApproach2(int[] nums) {
        int i = 0;
        for(int x : nums){
            if(x != 0){
                nums[i] = x;
                i++;
            }
        }
        for( ;i < nums.length;i++)
            nums[i] = 0;
    }
}

}