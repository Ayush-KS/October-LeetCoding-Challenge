// Repeated DNA Sequences

#define ll long long int
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> op;
        int n = s.size();
        if(n < 11)
            return op;
        
        
        unordered_map<int, int> freq;
        unordered_map<char, int> mp;
        mp['A'] = 0;
        mp['C'] = 1;
        mp['G'] = 2;
        mp['T'] = 3;
        
        
        ll hash = 0;
        for (int i = 0; i < 10; i++) {
            hash *= 4;
            hash += mp[s[i]];
        }
        freq[hash] = 1;
        
        ll maxP = pow(4, 9);
        
        for(int i = 10; i < n; i++) {
            hash -= (maxP * mp[s[i - 10]]);
            hash *= 4;
            hash += mp[s[i]];
            
            freq[hash]++;
            if(freq[hash] == 2) {
                op.push_back(s.substr(i - 9, 10));
            }
        }
        
        return op;
    }
};