#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <exception>

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        b %= a;
        swap(a, b);
    }
    return b;
}

class Rational {

    int p, q;

public:
    Rational() { p = 0; q = 1; }
    Rational(int numerator, int denominator) {
        if (!denominator) {
            throw std::invalid_argument("zero");
        }
        int g = gcd(abs(numerator), abs(denominator));
        p = numerator / g;
        q = denominator / g;
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        if (p == 0) {
            q = 1;
        }
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

    friend Rational operator + (const Rational &lhs, const Rational &rhs) {
        return Rational(lhs.p * rhs.q + rhs.p * lhs.q, lhs.q * rhs.q);
    };

    friend Rational operator - (const Rational &lhs, const Rational &rhs) {
        return Rational(lhs.p * rhs.q - rhs.p * lhs.q, lhs.q * rhs.q);
    };

    friend Rational operator * (const Rational &lhs, const Rational &rhs) {
        return Rational(lhs.p * rhs.p, lhs.q * rhs.q);
    };

    friend Rational operator / (const Rational &lhs, const Rational &rhs) {
        if (!rhs.p) {
            throw std::domain_error("zero");
        }
        return Rational(lhs.p * rhs.q, lhs.q * rhs.p);
    };

    friend bool operator == (const Rational &lhs, const Rational &rhs) {
        return lhs.p == rhs.p && lhs.q == rhs.q;
    };

    friend bool operator > (const Rational &lhs, const Rational &rhs) {
        double pp = lhs.p * rhs.q - rhs.p * lhs.q, qq = lhs.q * rhs.q;
        return pp / qq > 0;
    };

    friend bool operator < (const Rational &lhs, const Rational &rhs) {
        return !(lhs > rhs || lhs == rhs);
    };

    friend std::istream &operator >> (std::istream& stream, Rational& r) {
        int n, d;
        char c;
        if (stream) {
            stream >> n >> c >> d;
            if (stream && c == '/') {
                r = Rational(n, d);
            }
        }
        return stream;
    }

    friend std::ostream &operator << (std::ostream &stream, const Rational &r) {
        stream << r.p << "/" << r.q;
        return stream;
    }

};