class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> charFreq;
        unordered_set<int> seenFreq;

        for(char c : s){
            charFreq[c]++;
        }

        int deletions = 0;

        for(const auto& pair : charFreq){
            int freq = pair.second;

            while(seenFreq.count(freq)>0){
                freq--;
                deletions++;
            }

            if(freq>0){
                seenFreq.insert(freq);
            }
        }
        
        return deletions;
    }
};