#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
/* template end here */

/* problem code here */
bool allCitiesCovered(
    vector<int> &cities,
    vector<int> &towers,
    lli r
) {
    // cout << "allcitiescovered: " << r << endl;
    int m = towers.size();
    int towerIdx = 0;

    for(int i=0;i < cities.size();i++) {
        // cover this city using tower somehow
        // hypothesis : 
        bool cityCovered = false;

        while(towerIdx < m) {
            int tower = towers[towerIdx];
            lli conda = (cities[i] >= tower - r) ;
            lli condb = (cities[i]-r <= tower);
            // cout << conda << " " << condb << endl;
            if(conda && condb) {
                cityCovered = true;
                break;
            }

            towerIdx++;
        }

        if(cityCovered == false) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cities(n);
    vector<int> towers(m);

    for(auto &i: cities) {
        cin >> i;
    }

    for(auto &i: towers) {
        cin >> i;
    }

    lli start = 0;
    lli end = 2 * 1e9;

    lli ans = -1;
    while(start <= end) {
        lli mid = start + (end-start)/2;

        if(allCitiesCovered(cities, towers, mid)) {
            ans = mid;
            end=mid-1;
        } else {
            start=mid+1;
        }
    }

    cout << ans << endl;
    return 0;
}