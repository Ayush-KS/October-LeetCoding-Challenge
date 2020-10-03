// Combination Sum

class Solution {
    public List<List<Integer>> combinationSum(int[] cd, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<Integer>();
        Arrays.sort(cd);
        backtrack(cd, target, ans, curr, 0);
        return ans;
    }
    
    public void backtrack(int[] cd, int target, List<List<Integer>> ans, List<Integer> curr, int in) {
        if(target == 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        for(int i = in; (i < cd.length) && (target - cd[i] >= 0); i++) {
            curr.add(cd[i]);
            backtrack(cd, target - cd[i], ans, curr, i);
            curr.remove(curr.size() - 1);
        }
    }
}