// filepath: fxp_header.h
#pragma once
// ...existing code...
#include <cstdint>
#include <type_traits>
#include <iostream>

int double_to_fixed(double input);
double fixed_to_double(int fixed_value);


int double_to_fixed(double input) {
    return static_cast<int> (input * (1 << 16));
}

int double_to_fixed(int fixed_value) {
    return static_cast<double> ((double) fixed_value / (double)(1 << 16));
}

// // Simple fixed-point type: underlying integer IntT, FracBits fractional bits.
// // Value = raw / 2^{FracBits}
// template<typename IntT = int32_t, int FracBits = 16>
// class FixedPoint {
//     static_assert(std::is_signed<IntT>::value, "IntT must be signed");
//     static_assert(FracBits >= 0 && FracBits < (int)(sizeof(IntT) * 8), "Invalid FracBits");

// public:
//     using WideT = std::conditional_t<(sizeof(IntT) <= 4), int64_t, __int128_t>;

//     constexpr FixedPoint() : raw_(0) {}
//     constexpr FixedPoint(int32_t i) : raw_(static_cast<IntT>(i) << FracBits) {}
//     constexpr FixedPoint(double d) : raw_(static_cast<IntT>(d * (1ULL << FracBits))) {}

//     static constexpr FixedPoint fromRaw(IntT raw) noexcept { FixedPoint f; f.raw_ = raw; return f; }
//     constexpr IntT raw() const noexcept { return raw_; }

//     constexpr double toDouble() const noexcept { return static_cast<double>(raw_) / (1ULL << FracBits); }

//     // arithmetic
//     constexpr FixedPoint operator+(FixedPoint o) const noexcept { return fromRaw(static_cast<IntT>(raw_ + o.raw_)); }
//     constexpr FixedPoint operator-(FixedPoint o) const noexcept { return fromRaw(static_cast<IntT>(raw_ - o.raw_)); }

//     constexpr FixedPoint operator*(FixedPoint o) const noexcept {
//         WideT prod = static_cast<WideT>(raw_) * static_cast<WideT>(o.raw_);
//         prod = prod >> FracBits; // scale back
//         return fromRaw(static_cast<IntT>(prod));
//     }

//     constexpr FixedPoint operator/(FixedPoint o) const noexcept {
//         WideT num = (static_cast<WideT>(raw_) << FracBits);
//         num = num / static_cast<WideT>(o.raw_);
//         return fromRaw(static_cast<IntT>(num));
//     }

//     // comparison
//     constexpr bool operator==(FixedPoint o) const noexcept { return raw_ == o.raw_; }
//     constexpr bool operator!=(FixedPoint o) const noexcept { return raw_ != o.raw_; }
//     constexpr bool operator<(FixedPoint o) const noexcept { return raw_ < o.raw_; }
//     constexpr bool operator<=(FixedPoint o) const noexcept { return raw_ <= o.raw_; }
//     constexpr bool operator>(FixedPoint o) const noexcept { return raw_ > o.raw_; }
//     constexpr bool operator>=(FixedPoint o) const noexcept { return raw_ >= o.raw_; }

//     friend std::ostream& operator<<(std::ostream& os, FixedPoint f) {
//         return os << f.toDouble();
//     }

// private:
//     IntT raw_;
// };
// // ...existing code...