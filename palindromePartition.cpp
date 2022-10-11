#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int a,int b){
    while(a<=b){
        if(s[a++]!=s[b--])
        return false;
    }
    return true;
}
 void solve(string s,int index,vector<vector<string>> &ans,vector<string> &ds){
    if(index==s.size()){
           ans.push_back(ds);
           return ;
    }
    for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index,i)){
            ds.push_back(s.substr(index,i-index+1));
             solve(s,i+1,ans,ds);
        ds.pop_back();
        }
        
    }
}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList);
                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};
int main(){
    string s;
    cin>>s;
    Solution of;
    vector<vector<string>> ans,ans1;
     ans1=of.partition(s);
    vector<string> ds;
    solve(s,0,ans,ds);
    // for(auto i: ans){
    //     for(auto j:i){
    //         cout<<j<<"  ";
    //     }
    //     cout<<endl;
    // }
    if(ans==ans1){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}