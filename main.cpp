/* 
 * File:   main.cpp
 * Author: astd63
 *
 * Created on 23 Апрель 2018 г., 18:21
 */

#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

// ew rationals oh no
struct rational {
    int nom, denom;
    // default
    rational() {
        nom = 1;
        denom = 1;
    }
    // if one def
    rational(int nom) {
        nom = nom;
        denom = 1;
    }
    // if both def
    rational(int _nom, int _denom) {
        denom = _denom;
        nom = _nom;
    }
};

int _gcd (rational &_a) {
    int a = _a.nom;
    int b = _a.denom;
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int gcd (rational &_a, rational &_b) {
    int a = _a.denom;
    int b = _b.denom;
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int lcm (rational &a, rational &b) {
    return a.denom * b.denom / gcd(a, b);
}

// how to install linux here ;_;
// operators
// "+"
rational operator +(rational &a, rational &b) {
    int _lcm = lcm(a, b);
    int _a = a.nom;
    int _b = b.nom;
    _a *= _lcm / a.denom;
    _b *= _lcm / b.denom;
    rational ans = rational(_a + _b, _lcm);
    return ans;
}

// "-"
rational operator -(rational &a, rational &b) {
    int _lcm = lcm(a, b);
    int _a = a.nom;
    int _b = b.nom;
    _a *= _lcm / a.denom;
    _b *= _lcm / b.denom;
    rational ans = rational(_a - _b, _lcm);
    return ans;
}

// "*"
rational operator *(rational &a, rational &b) {
    rational ans = rational(a.nom * b.nom, a.denom * b.denom);
    return ans;
}

// "/"
rational operator /(rational &a, rational &b) {
    rational ans = rational(a.nom * b.denom, a.denom * b.nom);
    return ans;
}

rational reduce(rational &a) {
    int __gcd = _gcd(a);
    a.nom /= __gcd;
    a.denom /= __gcd;
    return a;
}

// Frankfurt am Main ;)
int main() {
    cout << "CRITICAL DEBUG" << '\n';
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    rational r(a, b), _r(c, d);
    cout << "VERY DEBUG" << '\n';
    rational f = r + _r;
    cout << "debug" << '\n';
    reduce(f);
    cout << 1 << '\n';
    cout << 2 << '\n';
    cout << lcm(r, _r);
    rational g = r - _r;
    reduce(g);
    if (g.denom == 1) { cout << "Minus" << g.nom << endl; } else { cout << "Minus" << g.nom << " / " << g.denom << endl; }
    rational h = r * _r;
    reduce(h);
    if (h.denom == 1) { cout << "Times: " << h.nom << endl; } else { cout << "Times: " << h.nom << " / " << h.denom << endl; }
    rational k = r / _r;
    reduce(k);
    if (k.denom == 1) { cout << "Divide: " << k.nom << endl; } else { cout << "Divide: " << k.nom << " / " << k.denom << endl; }
    return 0;
}