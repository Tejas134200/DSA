class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int mini = 10000;
        for(int i =0;i<nums.length;i++){
            if(nums[i]==target){
                mini = Math.min(mini , Math.abs(i-start));
            }
        }
        return mini;
    }
}