<h2>2366. Minimum Replacements to Sort the Array </h2>

[Link to Problem](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/)

<details><summary>Codes </summary>

```java

public class LC2366 {
    public long minimumReplacement(int[] nums) {
        int n = nums.length, last_processed = nums[n - 1];
        long answer = 0;
        for (int i = n - 2; i >= 0; i--) {
            int parts_required = (nums[i] + last_processed - 1) / last_processed;
            last_processed = nums[i] / parts_required;
            answer += parts_required - 1;
        }

        return answer;
    }
}

```

</details>

<br>
<br>

<h2>347. Top K Frequent Elements </h2>

[Link to Problem](https://leetcode.com/problems/top-k-frequent-elements)

<details><summary>Codes </summary>

```java

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC347 {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int max_count = 0;
        for (int i : nums) {
            mp.merge(i, 1, Integer::sum);
            max_count = Math.max(mp.get(i), max_count);
        }

        List<List<Integer>> bucket = new ArrayList<>(max_count + 1);
        for (int i = 0; i <= max_count; i++) bucket.add(new ArrayList<>());
        for (int i : mp.keySet()) bucket.get(mp.get(i)).add(i);

        int[] answer = new int[k];
        for (int i = max_count, j = 0; i >= 1 && j < k; i--) {
            if (bucket.get(i).size() > 0) {
                for (int ii : bucket.get(i)) answer[j++] = ii;
            }
        }

        return answer;
    }
}

```

</details>
