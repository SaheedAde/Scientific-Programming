#ifndef PERMUTATION_H
#define PERMUTATION_H
#include <iostream>
using namespace std;

class Permutation {
    private:
        long n;  // length of permutation group
        // pointer to array holding the elements of the permutation group,
        // where data[1],...,data[n] hold the value of pi(1),...,pi(n),
        // so we'll waste data[0] to make it easy to remember. Hence data will
        // have n+1 length.
        long* data;

    public:
        // constructors
        Permutation();
        Permutation(long nels); // nels is the length of permutation group
        Permutation(long nels, long* array); // array contains an array of n+1 long

        ~Permutation(); // destructor

        Permutation(const Permutation& that); // copy constructor
        Permutation operator=(const Permutation& that);  // assignment operators (read-only)

        // methods
        void swap(long i, long j); // exchange the value of pi(i) and pi(j)
        void randomize(); // replaces pi with a permutation chosen uniformly at random from Sn.
        void reset(); // resets the array to pi(n)=n if not permutation
        bool check() const; // check if data is a valid representation of permutation, if not it calls reset method
        long getN() const { return n; } // get the value of n
        long of(long k) const; // P.of(k) returns p(k) for given k
        Permutation inverse() const; // assigns the inverse of P to Q, but leaves P unchanged

        // operators (read-only)
        long operator()(long k) const { return of(k); } // returns P(k) using operator (). Hence P.of(k) is the same as P(k)
        Permutation operator*(const Permutation& that) const; // composition of 2 Permutations with operator *. returns permutation, Z = P*Q
        Permutation operator*=(const Permutation& that);

        // comparison operators
        bool operator==(const Permutation& that) const;
        bool operator!=(const Permutation& that) const;
        bool operator< (const Permutation& that) const;
        bool isIdentity() const;
};

// output permutation in disjoint cycle format
ostream& operator<<(ostream& os, const Permutation& P);

#endif