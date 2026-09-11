#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
    struct Job {
        int deadline;
        int profit;
    };

    // Iterative find function to avoid C++23 lambda recursion issues
    int findParent(int i, vector<int>& parent) {
        if (i == parent[i]) return i;
        return parent[i] = findParent(parent[i], parent);
    }

public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<Job> jobs(n);
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs[i] = {deadline[i], profit[i]};
            if (deadline[i] > maxDeadline) maxDeadline = deadline[i];
        }

        // Sort jobs based on profit in descending order
        sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
            return a.profit > b.profit;
        });

        // Initialize DSU parent array
        vector<int> parent(maxDeadline + 1);
        iota(parent.begin(), parent.end(), 0);

        int countJobs = 0;
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            // Find the latest available slot for this job's deadline
            int availableSlot = findParent(jobs[i].deadline, parent);

            if (availableSlot > 0) {
                // Assign job to this slot and link to the next available one (leftwards)
                parent[availableSlot] = findParent(availableSlot - 1, parent);
                countJobs++;
                maxProfit += jobs[i].profit;
            }
        }

        return {countJobs, maxProfit};
    }
};