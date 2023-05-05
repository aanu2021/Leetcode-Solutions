/**
 * @param {string} s
 * @return {boolean}
 */


var isValid = function(s) {
     const stack = [];

    for (const char of s) {
        if (char === 'c') {
            if (stack.length < 2) return false;
            if (stack.at(-1) !== 'b' || stack.at(-2) !== 'a') return false;
            stack.splice(-2, 2);
        }
        else stack.push(char);
    }
    return stack.length === 0;
};