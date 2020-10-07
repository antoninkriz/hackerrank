#include <bits/stdc++.h>

using namespace std; 

/**
 * 11559 - Event Planning
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int participants, budget, hotelsCount, weeksCount;
    while (cin >> participants >> budget >> hotelsCount >> weeksCount) {
      long long minimumCost = 500001;

      for (int i = 0; i < hotelsCount; i++) {
        int cost;
        cin >> cost;

        int maxBeds = -1;
        for (int j = 0; j < weeksCount; j++) {
          int freeBeds;
          cin >> freeBeds;
          maxBeds = max(maxBeds, freeBeds);
        }

        if (maxBeds >= participants)
          minimumCost = min(minimumCost, ((long long) cost * participants));
      }

      if (minimumCost <= budget)
        cout << minimumCost << "\n";
      else
        cout << "stay home\n";
    }
    
    return 0;
}
