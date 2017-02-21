#ifndef TMXPP_IMPL_WRITE_UTILITY_HPP
#define TMXPP_IMPL_WRITE_UTILITY_HPP

#include <string>
#include <string_view>
#include <type_traits>
#include <boost/lexical_cast.hpp>
#include <type_safe/strong_typedef.hpp>
#include <tmxpp/exceptions.hpp>
#include <tmxpp/impl/Xml.hpp>

namespace tmxpp::impl {

void add(Xml::Element elem, Xml::Attribute::Name name, std::string_view value)
{
    elem.add(name, Xml::Attribute::Value{value});
}

template <
    class Arithmetic,
    class = std::enable_if_t<std::is_arithmetic_v<Arithmetic>>>
std::string to_string(Arithmetic num) try {
    return boost::lexical_cast<std::string>(num);
}
catch (const boost::bad_lexical_cast& e) {
    throw Exception{
        std::string{"Could not convert Arithmetic to std::string. "} +
        e.what()};
}

template <class T, class Phantom>
std::string to_string(type_safe::strong_typedef<Phantom, T> x)
{
    return to_string(get(x));
}

} // namespace tmxpp::impl

#endif // TMXPP_IMPL_WRITE_UTILITY_HPP
