#include <complex.hpp>

Complex Complex::operator-() {
    re = re * -1;
    im = im * -1;
    return *this;
}

bool Complex::operator==(const Complex& other) const {
    return re == other.re && im == other.im;
}

bool Complex::operator!=( const Complex& other) const {
    return re != other.re || im != other.im;
}

Complex& Complex::operator+=(const Complex& other) {
    re += other.re;
    im += other.im;
    return *this;
}

Complex& Complex::operator+=(const double rhs) {
    re += rhs;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs) {
    re -= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    re = re * other.re - im * other.im;
    im = re * other.im + im * other.re;
    return *this;
}

Complex& Complex::operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    re = (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im);
    im = (im * other.re - re * other.im) / (other.re * other.re + other.im * other.im);
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    re /= rhs;
    im /= rhs;
    return *this;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) noexcept {
    istrm >> leftBrace >> re >> separator >> im >> rightBrace;
    return istrm;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return {lhs.re + rhs.re, lhs.im + rhs.im};
}

Complex operator+(const Complex& lhs, const double rhs) {
    return {lhs.re + rhs, lhs.im};
}

Complex operator+(const double lhs, const Complex& rhs) {
    return {rhs.re + lhs, rhs.im};
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return {lhs.re - rhs.re, lhs.im - rhs.im};
}
Complex operator-(const Complex& lhs, const double rhs) {
    return {lhs.re - rhs, lhs.im};
}
Complex operator-(const double lhs, const Complex& rhs) {
    return {rhs.re - lhs, rhs.im * (-1)};
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    return {lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + lhs.im * rhs.re};
}
Complex operator*(const double lhs, const Complex& rhs) {
    return {rhs.re * lhs, rhs.im * lhs};
}
Complex operator*(const Complex& lhs, const double rhs) {
    return {lhs.re * rhs, lhs.im * rhs};
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    return {(lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im), (lhs.im * rhs.re - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im)};
}
Complex operator/(const double lhs, const Complex& rhs) {
    return {lhs * rhs.re / (rhs.re * rhs.re + rhs.im * rhs.im), (-1) * lhs * rhs.im / (rhs.re * rhs.re + rhs.im * rhs.im)};
}

Complex operator/(const Complex& lhs, const double rhs) {
    return {lhs.re / rhs, lhs.im / rhs};
}