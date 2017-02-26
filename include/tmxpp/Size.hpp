#ifndef TMXPP_SIZE_HPP
#define TMXPP_SIZE_HPP

#include <tmxpp/Constrained.hpp>
#include <tmxpp/Pixel.hpp>

namespace tmxpp {

template <class Number>
struct Size {
    using Dimension = Positive<Number>;

    Dimension w;
    Dimension h;
};

using pxSize = Size<Pixel>;
using iSize  = Size<int>;

template <class N>
inline bool operator==(Size<N> l, Size<N> r) noexcept
{
    return l.w == r.w && l.h == r.h;
}

template <class N>
inline bool operator!=(Size<N> l, Size<N> r) noexcept
{
    return !(l == r);
}

} // namespace tmxpp

#endif // TMXPP_SIZE_HPP
