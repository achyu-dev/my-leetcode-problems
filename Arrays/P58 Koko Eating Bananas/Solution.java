public class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1, right = 0;

        // Find the maximum pile size
        for (int pile : piles) {
            right = Math.max(right, pile);
        }

        int result = right; // Store the minimum speed found

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long hours = 0; // Use long to prevent overflow

            // Calculate total hours needed at speed `mid`
            for (int pile : piles) {
                hours += (pile + mid - 1L) / mid; // Avoid overflow by casting to long
            }

            if (hours <= h) {
                result = mid; // Update result with the lower possible speed
                right = mid - 1; // Try a smaller eating speed
            } else {
                left = mid + 1; // Increase the speed
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] piles = { 3, 6, 7, 11 };
        int h = 8;
        int minSpeed = solution.minEatingSpeed(piles, h);
        System.out.println("Minimum eating speed: " + minSpeed);
    }

}
