class Solution {
    public int maximumDifference(int[] nums) {
        int minus = 0;
        int minValue = nums[0];
        for(int value: nums){
            if(value < minValue)
            {
                minValue = value;
            }
            else if(value - minValue > minus){
                minus = value - minValue;
            }
        }
        if(minus == 0){
            return -1;
        }
        return minus;
    }
}
