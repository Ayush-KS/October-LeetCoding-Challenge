// Minimum Number of Arrows to Burst Balloons

/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    var n = points.length;
    if(n == 0)
        return 0;
    var ans = 1;
    points.sort(function(a, b) {
        if(a[0] > b[0]) 
            return 1;
        return -1;
    });
    var curr = points[0][1];
    for(let i = 0; i < n; i++) {
        if(points[i][0] > curr) {
            ans++;
            curr = points[i][1];
        }
        curr = Math.min(curr, points[i][1]);
    }
    
    return ans;
};