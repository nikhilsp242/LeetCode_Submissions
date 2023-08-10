class Solution {
public:
    //helper function to handle padding
    string padding(queue<string>& sent,int pad,int rem){
        string res;
        string spaces(pad,' ');
        int qs = sent.size();
        if(rem==0){
            while(!sent.empty()){
                res += sent.front() + spaces;
                sent.pop();
            }
        }
        else{
            while(!sent.empty()){
                if(rem>0){
                    res += sent.front() + spaces + ' ';
                    sent.pop();
                    rem--;
                }
                else{
                    res += sent.front() + spaces;
                    sent.pop();
                }
            }
        }
        if(qs==1) return res;
        return res.substr(0,res.size()-pad);
    }

    //helper function to handle the spaces
    string handleSpaces(queue<string>& sent,int diff){
        int pad = 0;
        int rem = 0;
        if(sent.size()==1) pad = diff;
        else if(diff == 0) pad = 1;
        else if(diff%(sent.size()-1) == 0) pad = diff/(sent.size()-1);
        else {
            pad = diff/(sent.size()-1);
            rem = diff%(sent.size()-1);
        }
        return padding(sent,pad,rem);
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justify;
        int size = 0;
        queue<string> sent;

        for (int i = 0; i < words.size(); i++) {
            if (size + sent.size() + words[i].size() <= maxWidth) {
                size += words[i].size();
                sent.push(words[i]);
            } else {
                int diff = maxWidth - size;
                string justified = handleSpaces(sent, diff);
                justify.push_back(justified);
                size = words[i].size();
                sent.push(words[i]);
            }
        }

        // Handle the last line (left-justified)
        string lastLine;
        while (!sent.empty()) {
            lastLine += sent.front() + ' ';
            sent.pop();
        }
        lastLine.pop_back(); // Remove the last space
        lastLine += string(maxWidth - lastLine.size(), ' '); // Add padding to the end
        justify.push_back(lastLine);

        return justify;
    }
};