// Stone Game IV

bool winnerSquareGame(int n){
    bool dp[n + 1];
    
    for(int i = 0; i <= n; i++) {
        dp[i] = false;
        for(int j = 1; j*j <= i; j++) {
            if(!dp[i - j*j]) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}