struct cmp {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {

        // Min-heap according to frequency
        if (a.first != b.first) {
            return a.first > b.first;
        }

        // If frequency is same,
        // lexicographically larger word should come first
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Store frequency
        unordered_map<string, int> f;

        for (int i = 0; i < words.size(); i++) {
            f[words[i]]++;
        }

        // Step 2: Priority Queue
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            cmp
        > pq;

        // Step 3: Traverse hashmap
        for (auto i : f) {

            string word = i.first;
            int freq = i.second;

            pair<int, string> curr = {freq, word};

            // First k elements
            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            // Step 4: Compare with worst element
            if (curr.first < pq.top().first) {
                continue;
            }

            // If frequency is greater
            else if (curr.first > pq.top().first) {
                pq.pop();
                pq.push(curr);
            }

            // If frequency is same
            else {
                if (curr.second < pq.top().second) {
                    pq.pop();
                    pq.push(curr);
                }
            }
        }

        // Step 5: Store answer
        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        // Heap gives worst -> best
        reverse(res.begin(), res.end());

        return res;
    }
};