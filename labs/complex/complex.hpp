#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include<iosfwd>
#include <iostream>

struct Complex {
    double re;
    double im;
    Complex() = default;
    explicit Complex(double real) : re(real) {}
    Complex(double real, double imag) : re(real), im(imag) {}
    Complex(const Complex&) = default;
    Complex(Complex&&) = default;
    Complex& operator=(Complex&) = default;
    Complex& operator=(Complex&&) = default;
    ~Complex() = default;
    Complex operator-();
    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);
    [[nodiscard]]std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
    [[nodiscard]]std::istream& ReadFrom(std::istream& istrm) noexcept;
    char leftBrace { '{' };
    char rightBrace { '}' };
    char separator { ',' };
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs);

[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs);

[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs);

[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
    return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
    return rhs.ReadFrom(istrm);
}

#endif
