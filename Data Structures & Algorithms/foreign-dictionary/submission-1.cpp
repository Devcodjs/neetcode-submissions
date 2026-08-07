class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<int> present(26 , 0);
        vector<vector<int>> adj(26);
        vector<int> inde(26 , 0);
        for(int i = 0 ; i < n - 1; i++){
            string s = words[i];
            string t = words[i + 1];
            int j = 0;
            while(j < min(s.size() , t.size())){
                if(s[j]== t[j]) j++;
                else{
                    adj[s[j] - 'a'].push_back(t[j] - 'a');
                    inde[t[j] - 'a']++;
                    break;
                }
            }
            if (j == min(s.size(), t.size()) && s.size() > t.size())
                return "";
        }
        for(auto& e : words){
            for(auto& t : e){
                if(!present[t - 'a']) present[t - 'a'] = 1;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < 26; i++){
            if(present[i]  && inde[i] == 0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans += char(node + 'a');
            for(auto& e : adj[node]){
                inde[e]--;
                if(inde[e] == 0)q.push(e);
            }
        }
        int cnt = 0;
        for(auto& e : present){
            if(e) cnt++;
        }
        if(cnt != ans.size()) return "";

       
        return ans;
    }
};
