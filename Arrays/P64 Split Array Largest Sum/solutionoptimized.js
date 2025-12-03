class SubarrayPartitioner {
    // Counts how many partitions are needed for a given maxSum
    countPartitions(a, maxSum) {
        let partitions = 1; // at least one partition
        let subarraySum = 0; // sum of current subarray

        for (let num of a) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }

    // Finds the minimum largest subarray sum possible for at most k partitions
    largestSubarraySumMinimized(a, k) {
        let low = Math.max(...a); // largest element
        let high = a.reduce((acc, val) => acc + val, 0); // sum of array

        // Binary search
        while (low <= high) {
            let mid = Math.floor((low + high) / 2);
            let partitions = this.countPartitions(a, mid);

            if (partitions > k) {
                low = mid + 1; // too many partitions
            } else {
                high = mid - 1; // try smaller maxSum
            }
        }
        return low;
    }
}

let a = [10, 20, 30, 40];
let k = 2;
let sp = new SubarrayPartitioner();
let ans = sp.largestSubarraySumMinimized(a, k);
console.log("The answer is:", ans);
