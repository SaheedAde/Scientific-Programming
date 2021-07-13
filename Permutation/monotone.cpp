#include "monotone.h"

pair<long,long> monotone(const Permutation& P) {
    long* up;
    long* dn;
    long n = P.getN();

    up = new long[n+1]; // to hold the sequence ui (increasing)
    dn = new long[n+1]; // to hold the sequence di (decreasing)

    // generates the length of the last enteries of ui, di
    for (long k=1; k<=n; k++) {
        up[k] = dn[k] = 1;
    }

    for (long k=n-1; k>=1; k--) {
        for (long j=k+1; j<=n; j++) {
            if (P(k) > P(j)) {
                // decreasing
                if (dn[k] <= dn[j]) {
                    dn[k] = dn[j]+1;
                }
            }
            else {
                // increasing
                if (up[k] <= up[j]) {
                    up[k] = up[j]+1;
                }
            }
        }
    }

    long up_max = 1;
    long dn_max = 1;
    for (long k=1; k<=n; k++) {
        if (up_max < up[k]) up_max = up[k];
        if (dn_max < dn[k]) dn_max = dn[k];
    }

    delete[] up;
    delete[] dn;

    return make_pair(up_max,dn_max);
}