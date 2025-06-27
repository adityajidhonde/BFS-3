// Time Complexity : O(2^N) N is size of string
// Space Complexity : O(2^N)  
// Did this code successfully run on Leetcode : Yes

// Your code here along with comments explaining your approach:
// 1. Get all possible subsequence of brackets string except alphabets using BFS. Here subsequence is the result we get after removing that bracket from string.
// 2. Maintain a hashset to check if that string is explored before or not. For each string check if it's valid using stack. 
// 3. Keep track of size of each level. Stop adding strings to be traversed to queue if we get valid string and check validity of remaining string.

class Solution {
public:
    bool validity(string st){
        stack<char> ch;
        for(int i=0;i<st.size();i++){
            if(st[i]=='('){ch.push('(');}
            else if(st[i]==')'){if(!ch.empty() && ch.top()=='('){ch.pop();} else{ch.push(')');}}
        }
        if(ch.empty()){return true;}else{return false;}
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        vector<string> ans;
        map<string,int> mp;
        int shape=1,term=-1;
        if(validity(s)){
            ans.push_back(s);return ans;}
        while(!q.empty()){
            string temp=q.front();
            for(int i=0;i<temp.size();i++){
                if(temp[i]!=')' && temp[i]!='('){continue;}
                string tempa=temp;tempa.erase(i,1);
                if(mp[tempa] != 1) {
                    mp[tempa] = 1;  
                    q.push(tempa);
                    
                    if(validity(tempa)){
                        ans.push_back(tempa);
                        term=1;
                    }
                }
            }
            q.pop();shape--;
            if(shape==0){
                shape=q.size();
                if(term==1){break;}
            }
        }
        return ans; 
    }
};
