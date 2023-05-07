#include <bits/stdc++.h>
using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    int n = queries.size();
    vector<int> ans(n);
    unordered_map<string, int> wordFreq;
    
    // Loop through the strings vector and append each string to stringstream
    stringstream ss;
    for (string s : strings) {
        ss << s << " ";
    }
    
    // Populate the wordFreq map with frequency of each word
    string word;
    while (ss >> word) {
        if (wordFreq.find(word) == wordFreq.end()) {
            wordFreq[word] = 1;
        } else {
            wordFreq[word]++;
        }
    }
    
    // Loop through the queries vector and check if each query word exists in the map
    int i = 0;
    for (string query : queries) {
        if (wordFreq.find(query) != wordFreq.end()) {
            ans[i] = wordFreq[query];
        } else {
            ans[i] = 0;
        }
        i++;
    }
    return ans;
}
int main()
{
    vector<string> strings = {"abcde sdaklfj asdjf na basdn sdaklfj asdjf na asdjf na basdn sdaklfj asdjf"};
    vector<string> queries = {"abcde sdaklfj asdjf na basdn"};

    vector<int> ans = matchingStrings(strings, queries);

    // for (auto &kv : wordFreq)
    // {
    //     // cout << kv.first << " : " << kv.second << endl;
    //     ans.push_back(kv.second);
    // }
    // printing the required vector;
    for (auto p : ans)
        cout << p << endl;

    return 0;
}
