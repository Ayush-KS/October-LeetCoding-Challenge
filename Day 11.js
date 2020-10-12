// Remove Duplicate Letters

/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    var cnt = new Array(26).fill(0);
    var used = new Array(26).fill(0);
    var ans = [];
    
    for(let i = 0; i < s.length; i++) {
        var ch = s.charCodeAt(i) - 97;
        cnt[ch]++;
    }
    
    for(let i = 0; i < s.length; i++) {
        var ch = s.charCodeAt(i) - 97;
        --cnt[ch];
        if(used[ch] > 0)
            continue;
        while((ans.length > 0) && (ans[ans.length - 1] > ch) && (cnt[ans[ans.length - 1]] > 0)) {
            used[ans[ans.length - 1]] = 0;
            ans.pop();
        }
        ans.push(ch);
        used[ch]++;
    }
    
    var ret = "";
    for(let i = 0; i < ans.length; i++) {
        ret += String.fromCharCode(97 + ans[i]);
    }
    
    return ret;
};