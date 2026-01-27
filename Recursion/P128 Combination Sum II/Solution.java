import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        fincomb(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }

    static void fincomb(int ind, int[] arr, int target, List<List<Integer>> ans, List<Integer>ds){
        if (target == 0) {
            ans.add(new ArrayList<> (ds));
            return;
        }

        for(int i = ind ; i < arr.length ; i++) {
            if (i > ind && arr[i] == arr[i-1]) continue;
            if (arr[i] > target) break;

            ds.add(arr[i]);
            fincomb(i + 1, arr, target - arr[i], ans, ds);
            ds.remove(ds.size() - 1);
        }
    }
}