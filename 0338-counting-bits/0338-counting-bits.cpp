class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1,0);
        for(int i=1;i<=n;i++){
            int count = 0;
            int j = i;
            while(j>0){         //Brian Kernighan's algorithm
                j &= (j-1);
                count++;
            }
            bits[i] = count;
        }
        return bits;
    }
};