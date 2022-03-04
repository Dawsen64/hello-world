//笨方法， 能跑但是会超时
class Solution {
public long subArrayRanges(int[] nums) {
            long sum = 0;
            for(int i = 0; i < nums.length; i++){
                for(int j = i; j < nums.length; j++){
                    int[] subArr = Arrays.copyOfRange(nums, i, j+1);
                    int max = Arrays.stream(subArr).max().getAsInt();
                    int min = Arrays.stream(subArr).min().getAsInt();
                    sum += max - min;
                }
            }
            return sum;
        }
}

class Solution {
public long subArrayRanges(int[] nums) {
            long sum = 0;

            for(int i = 0; i < nums.length; i++){
                int maxValue = Integer.MIN_VALUE;
                int minValue = Integer.MAX_VALUE;
                for(int j = i; j < nums.length; j++){
                    maxValue = Math.max(maxValue, nums[j]);
                    minValue = Math.min(minValue, nums[j]);
                    sum += maxValue - minValue;
                }
            }
            return sum;
        }
}
