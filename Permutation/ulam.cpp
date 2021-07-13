#include "permutation.h"
#include "uniform.h"
#include "monotone.h"
#include <iostream>
using namespace std;

// int main() {
//     long n;
//     long reps;
//     seed();

//     cout << "Enter n (size of permutation) --> ";
//     cin >> n;
//     cout << "Enter number of repetitions --> ";
//     cin >> reps;

//     Permutation P(n);

//     long sum_up = 0;
//     long sum_dn = 0;

//     for (long k=0; k<reps; k++) {
//         P.randomize();
//         pair<long,long> ans;
//         ans = monotone(P);
//         sum_up += ans.first;
//         sum_dn += ans.second;
//     }

//     cout << "Average length of longest increasing subsequence is "
//     << double(sum_up)/double(reps) << endl;

//     cout << "Average length of longest decreasing subsequence is "
//     << double(sum_dn)/double(reps) << endl;

//     return 0;
// }

int main () {
    long n;
    seed();

    cout << "Enter n (size of permutation) --> ";
    cin >> n;

    Permutation P(n);

    Permutation F(n);
    P.randomize();
    F = P;
    cout << "The permutation is " << P << endl;
    int k = 1;
    while (true) {
        if (k == 5000) break;
        if (P.isIdentity()) break;
        k +=1;
        P *= F;
    }
    cout << "The order is " << k << endl;
    return 0;
}