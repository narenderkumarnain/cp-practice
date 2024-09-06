#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

/**
 * 
 */
struct Interactive {
    int queries = 0;
    int maxQueries = 4;
    vector<int> arr;
    Interactive(vector<int> a) {
        arr = a;
        queries = 0;
    }

    int query(int i, int j) {
        queries++;
        if(queries > maxQueries) exit(0);
        return arr[i] * arr[j];
    }
};
bool testing = false;
int query(int i, int j, Interactive &it) {
    if(testing) {
        return it.query(i, j);
    } else {
        cout << "? " << i+1 << " " << j+1 << endl;
        int ans;
        cin >> ans;
        return ans;
    }
}

int hitIt(int n) {
    vector<int> p = {15, 23, 42};
    for(int i=0;i<p.size();i++) {
        if(n%p[i] == 0) {
            return p[i];
        }
    } 
    return -1;
}

int a = -1, b = -1, c = -1, d = -1, e = -1, f = -1;



int findLeftOne() {
    int allNums[] = {4, 8, 15, 16, 23, 42};
    for(int i=0;i<6;i++) {
        int nm = allNums[i];
        if(a != nm && b != nm && c != nm && d != nm && e != nm) {
            return nm;
        }
    }
    // cout << "Why! " << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << endl;
    return 0;
}

int main() {
    // Interactive it({4,8,16,15,42, 23});
    Interactive it({15,42, 23, 4,8,16});
    vector<int> nums(6, -1);

    int ab = query(0, 1, it);
    int bc = query(1, 2, it);



    int abHit = hitIt(ab);
    if(abHit != -1) {
        if(bc%abHit == 0) {
            // b = abHit
            b = abHit;
            a = ab / b;
            c = bc / b;
        } else {
            // a - abHit
            a = abHit;
            b = ab / a;
            c = bc / b;
        }

        int cd = cd = query(2, 3, it);
        d = cd / c;

        int de = query(3, 4, it);
        e = de / d;
        f = findLeftOne();
    } else {
        int bcHit = hitIt(bc);
        if(bcHit != -1) {
            c = bcHit;
            b = bc / c;
            a = ab / b;

            // find cd -> de -> e -> left one is f
            int cd = cd = query(2, 3, it);
            d = cd / c;

            int de = query(3, 4, it);
            e = de / d;
            f = findLeftOne();
        } else {
            int cd = query(2, 3, it);
            int cdHit = hitIt(cd);
            d = cdHit;
            c = cd / d;
            b = bc / c;
            a = ab / b;

            // 1 query - find the e and f also 
            int de = query(3, 4, it);
            e = de / d;
            f = findLeftOne();
            // all solved
        }
    }

    cout << "! " << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << endl;
    return 0;
}