// Buddy Strings

var buddyStrings = function(A, B) {
    if(A.length != B.length)
        return false;
    var freq = new Array(26).fill(0);
    var double = false;
    
    var diff = [];
    
    for(let i = 0; i < A.length; i++) {
        if(A[i] != B[i])
            diff.push(i);
        var ch = A.charCodeAt(i) - 97;
        freq[ch]++;
        if(freq[ch] > 1) {
            double = true;
        }
    }
    
    if(diff.length == 2) {
        if(A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]])
            return true;
    } else if(diff.length == 0) {
        if(A == B && double == true)
            return true;
    }
    
    return false;
};