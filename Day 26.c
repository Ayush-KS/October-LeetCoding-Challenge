// Champagne Tower

double half(double db) {
    if(db <= 0)
        return 0;
    return db / 2;
}

double champagneTower(int poured, int row, int glass){
    double* curr = (double*)malloc(1 * sizeof(double));
    curr[0] = poured;
    
    for(int i = 1; i <= row; i++) {
        double* v = (double*)malloc((i + 1) * sizeof(double));
        v[0] = v[i] = half(curr[0] - 1);
        for(int j = 0; j < i - 1; j++) {
            v[j + 1] = half(curr[j] - 1) + half(curr[j + 1] - 1);
        }
        curr = v;
    }
    
    return curr[glass] >= 1 ? 1 : curr[glass];
}