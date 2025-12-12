/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let word = s.trim().split(/\s+/).reverse()
    return word.join(" ")
};

console.log(reverseWords("  hello world  "));