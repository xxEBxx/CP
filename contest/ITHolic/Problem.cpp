#include <bits/stdc++.h>
using namespace std;

struct Resource {
    int id, RA, RP, RW, RM, RL, RU;
    char RT;
    int RE;
};

struct ActiveResource {
    Resource res;
    int active_left;
    int downtime_left;
    int life_left;
    bool is_active() const { return active_left > 0; }
};

int main() {
    int D, R, T;
    cin >> D >> R >> T;

    vector<Resource> resources(R);
    for (auto& r : resources) {
        cin >> r.id >> r.RA >> r.RP >> r.RW >> r.RM >> r.RL >> r.RU >> r.RT;
        if (r.RT != 'X') cin >> r.RE;
        else r.RE = 0;
    }

    vector<tuple<int, int, vector<int>>> purchases;
    vector<ActiveResource> active;
    int accumulator = 0;
    int budget = D;

    for (int turn = 0; turn < T; ++turn) {
        int TM, TX, TR;
        cin >> TM >> TX >> TR;

        // Purchase phase
        vector<int> bought;
        int cost = 0;
        vector<Resource> affordable;

        for (const auto& r : resources) {
            if (r.RA <= budget) {
                affordable.push_back(r);
            }
        }

        // Greedy purchase: buy first affordable resource
        if (!affordable.empty()) {
            auto& buy = affordable[0];
            cost = buy.RA;
            if (cost <= budget) {
                budget -= cost;
                bought.push_back(buy.id);

                active.push_back({
                                         buy,
                                         buy.RW,    // initial active period
                                         0,         // downtime starts after active
                                         buy.RL - 1 // immediate activation uses 1 turn
                                 });
            }
        }

        if (!bought.empty()) {
            purchases.emplace_back(turn, bought.size(), bought);
        }

        // Maintenance costs
        int maintenance = 0;
        for (auto& ar : active) {
            maintenance += ar.res.RP;
        }
        budget -= maintenance;

        // Calculate powered buildings
        int powered = 0;
        for (auto& ar : active) {
            if (ar.is_active()) {
                powered += ar.res.RU;
            }
        }

        // Apply simple effects (only type A for demonstration)
        for (auto& ar : active) {
            if (ar.is_active() && ar.res.RT == 'A') {
                powered = powered * (100 + ar.res.RE) / 100;
            }
        }

        // Check minimum requirement
        if (powered >= TM) {
            int actual = min(powered, TX);
            budget += actual * TR;
        }

        // Update resource states
        for (auto& ar : active) {
            if (ar.is_active()) {
                ar.active_left--;
                if (ar.active_left == 0) {
                    ar.downtime_left = ar.res.RM;
                }
            } else if (ar.downtime_left > 0) {
                ar.downtime_left--;
                if (ar.downtime_left == 0) {
                    ar.active_left = ar.res.RW;
                }
            }
            ar.life_left--;
        }

        // Remove expired resources
        active.erase(remove_if(active.begin(), active.end(),
                               [](const ActiveResource& ar) { return ar.life_left <= 0; }), active.end());
    }

    // Output purchases
    for (const auto& [t, cnt, ids] : purchases) {
        cout << t << " " << cnt;
        for (int id : ids) cout << " " << id;
        cout << "\n";
    }

    return 0;
}