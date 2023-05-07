class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant, dire;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        vector<bool> ban(n, false);
        int r = 0, d = 0;
        while (!radiant.empty() && !dire.empty()) {
            int curr = (senate[radiant.front()] == 'R') ? radiant.front() : dire.front();
            if (ban[curr]) {
                ban[curr] = false;
                if (senate[radiant.front()] == 'R') {
                    radiant.push(radiant.front());
                    radiant.pop();
                } else {
                    dire.push(dire.front());
                    dire.pop();
                }
            } else {
                ban[curr] = true;
                if (senate[radiant.front()] == 'R') {
                    r++;
                } else {
                    d++;
                }
                if (r >= dire.size()) {
                    return "Radiant";
                } else if (d >= radiant.size()) {
                    return "Dire";
                }
                if (senate[radiant.front()] == 'R') {
                    radiant.push(radiant.front());
                    radiant.pop();
                } else {
                    dire.push(dire.front());
                    dire.pop();
                }
            }
        }
        return (radiant.empty()) ? "Dire" : "Radiant";
    }
};
