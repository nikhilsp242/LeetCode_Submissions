class Solution {
public:
    int compress(vector<char>& chars) {
        int readIdx = 0, writeIdx = 0;

        while(readIdx<chars.size()){
            char curr = chars[readIdx];
            int count = 0;

            while(readIdx<chars.size() && chars[readIdx]==curr){
                readIdx++;
                count++;
            }

            chars[writeIdx++] = curr;

            if(count>1){
                string num = to_string(count);
                for(char c : num) chars[writeIdx++] = c;
            }
        }

        return writeIdx;
    }
};