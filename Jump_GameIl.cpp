public int Jump(int[] nums)
    {
        int count = 0;
        if (nums.Length == 1) return count;
        for (int i = nums.Length - 1; i >= 0; i--)
        {
            for (int j = 0; j < nums.Length; j++)
            {
                if (nums[j] + j >= i)
                {
                    count++;
                    i = j;
                    if (i == 0) return count;
                    j = -1;
                }
            }
        }

        return count;
    }
