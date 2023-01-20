class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map1;
        multimap<int, char> map2;
        for(auto x: s)
        map1[x]++;
        for(auto x: map1)
        map2.insert(pair<int, char>(x.second, x.first));
        string res="";
        for(auto x: map2)
        cout<<x.first<<x.second<<endl;
        for(auto x: map2){
            int k=x.first;
            while(k){
                res+=x.second;
                k--;
            }
        }
        reverse(res.begin(),res.end());
        return res;

        
    }
};