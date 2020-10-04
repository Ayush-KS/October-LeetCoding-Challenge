// K-diff Pairs in an Array

class Solution {
    public int findPairs(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int ans = 0;
        
        for(int i : nums) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if((k == 0 && entry.getValue() > 1) || (k != 0 && mp.containsKey(entry.getKey() + k))) {
                ans++;
            }
        }
        
        return ans;
    }
}