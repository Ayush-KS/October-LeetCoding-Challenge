// Bag of Tokens

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int bagOfTokensScore(int* arr, int n, int p){
    qsort(arr, n, sizeof(n), cmpfunc);
    int i = 0;
    int j = n - 1;
    int ans = 0;

    while(i <= j) {
        if(arr[i] <= p) {
            ans++;
            p -= arr[i];
            i++;
        } else {
            if(ans && arr[j] + p >= arr[i] && i != j){
                p += arr[j];
                j--;
                ans--;
            } else {
                break;
            }
        }
    }
    return ans;
}