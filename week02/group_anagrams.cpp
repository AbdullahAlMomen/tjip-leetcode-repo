#Time Complexity :O(N)
#Space Complexity:O(1)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>>mp;
       vector<vector<string>>result;

      for (auto str : strs)
        {
            vector<int> count(26, 0);
            for (int i = 0; i < str.size(); ++i)
            {
                char tmp = str.at(i);
                count.at(tmp - 'a') += 1;
            }

            string key;
            for(int j = 0; j < 26; ++j)
            {
                key += count.at(j);
            }

          auto it=mp.find(key);

          if(it==mp.end())
              mp[key]={str};
          else
              mp[key].push_back(str);


        }

        for(auto it=mp.begin();it!=mp.end();it++){

            result.push_back(it->second);
        }
        return result;

    }
};
