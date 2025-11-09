#include <iostream>

// specify number of bits after decimal point
template<size_t dp>
constexpr int32_t DoubleToFixed(double d) {
    return int32_t(d * double(1 << dp) + (d >= 0 ? 0.5 : -0.5));
}

template<size_t dp>
constexpr double FixedToDouble(int32_t d) {
    return double(d) / double(1 << dp)
}

// g++ exp.cpp -o exp && ./exp
int main() {
    // 16.16
    constexpr size_t precision_bits = 2;
    constexpr int32_t a = DoubleToFixed<precision_bits>(5.6);
    constexpr int32_t b = DoubleToFixed<precision_bits>(2.7);

    constexpr int32_t c = a + b;
    constexpr int32_t d = a - b;
    constexpr int32_t e = (int64_t(a) * int64_t(b)) >> precision_bits;
    constexpr int32_t f = (int64_t(a) / int64_t(b)) << precision_bits;

    // A / B * 2^16
    constexpr int32_t g = (int64_t(a)<< precision_bits) / int64_t(b) ;
    // A * 2^16 / B

    constexpr double z_a = FixedToDouble<precision_bits>(a);
     constexpr double z_b = FixedToDouble<precision_bits>(b);
    constexpr double z = FixedToDouble<precision_bits>(c);
    constexpr double z1 = FixedToDouble<precision_bits>(d);
    constexpr double z2 = FixedToDouble<precision_bits>(e);
    constexpr double z3 = FixedToDouble<precision_bits>(f);
    constexpr double z4 = FixedToDouble<precision_bits>(g);


}