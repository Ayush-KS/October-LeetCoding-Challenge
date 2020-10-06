// Complement of Base 10 Integer

class Solution {
    public int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        int rev = ~n;
        int mask = Integer.highestOneBit(n);
        mask <<= 1;
        mask -= 1;
        return rev & mask;
    }
}
