#ifndef TMXPP_IMPL_EXCEPTIONS_HPP
#define TMXPP_IMPL_EXCEPTIONS_HPP

#include <stdexcept>
#include <tmxpp/exceptions.hpp>
#include <tmxpp/impl/Xml.hpp>

namespace tmxpp::impl {

class Invalid_attribute : public tmxpp::Invalid_attribute {
public:
    using Name  = Xml::Attribute::Name;
    using Value = Xml::Attribute::Value;

    explicit Invalid_attribute(Name);
    explicit Invalid_attribute(Name, Value);
};

class Invalid_element : public tmxpp::Invalid_element {
public:
    using Name  = Xml::Element::Name;
    using Value = Xml::Element::Value;

    explicit Invalid_element(Name);
    explicit Invalid_element(Name, Value);
};

} // namespace tmxpp::impl

#endif // TMXPP_IMPL_EXCEPTIONS_HPP