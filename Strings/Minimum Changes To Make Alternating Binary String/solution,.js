/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
    let count1 = 0;
    let count2 = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] !== (i % 2).toString()) {
            count1++;
        }
        if (s[i] !== ((i + 1) % 2).toString()) {
            count2++;
        }
    }
    return Math.min(count1, count2);
};

// Example usage:
console.log(minOperations("0100"));