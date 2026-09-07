class Solution {
public:
    struct meeting {
        int start;
        int end;
        int id;
    };

    static bool compare(struct meeting m1, struct meeting m2) {
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        else if (m1.id < m2.id) return true; // Tie-break with index
        return false;
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        struct meeting m[n];
        for (int i = 0; i < n; i++) {
            m[i].start = s[i];
            m[i].end = f[i];
            m[i].id = i + 1;
        }

        sort(m, m + n, compare);

        vector<int> ans;
        int limit = m[0].end;
        ans.push_back(m[0].id);

        for (int i = 1; i < n; i++) {
            if (m[i].start > limit) {
                ans.push_back(m[i].id);
                limit = m[i].end;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};