#include <cstdint>
#include <cstdlib>
#include <type_traits>
#include <utility>

#ifndef RESOURCE_H_
#define RESOURCE_H_


/// Determine if two sets are the same resource
/// @{
template<class R1, class R2, class Base>
struct are_same_derivation : std::conjunction<
    std::is_base_of<Base, R1>,
    std::is_same<R1, R2>>
{
    using type = R1;
};

template<class R1, class R2, class Base>
static constexpr bool are_same_derivation_v = are_same_derivation<R1, R2, Base>::value;

template<class R1, class R2, class Base>
using are_same_derivation_t = typename are_same_derivation<R1, R2, Base>::type;
/// @}

/// Resource
///
/// Base class for resource
class Resource {
    std::size_t quantity_{0};

    public:

    /// Ctor
    constexpr Resource(std::size_t const quantity) :
        quantity_{quantity}
    {}

    template<class T, std::enable_if_t<std::is_same<Resource, std::decay_t<T>>::value>>
    constexpr Resource(T&& r) :
        quantity_(std::forward<T>(r).getQuantity())
    {}

    /// Consume part of this resource
    ///
    /// @param consumed The quantity to be consumed
    template<class R>
    bool consume(R const consumed)
    {
        if (quantity_ < consumed.getQuantity())
        {
            quantity_ = 0U;
            return false;
        }
        quantity_ -= consumed.getQuantity();
        return true;
    }

    /// Get function
    constexpr std::size_t getQuantity() const { return quantity_;}

    /// Set function
    void setQuantity(std::size_t const quantity) { quantity_ = quantity;}

    /// How long will it take if consumed at constant rate?
    ///
    /// @param consumed The consumed resource
    template<class R>
    constexpr std::size_t will_finish_in(R consumed);


};

/// Sum operator for resources
template<class R1, class R2>
auto operator+(R1& r1, R2& r2) -> std::enable_if_t<are_same_derivation_v<R1, R2, Resource>, R1>
{
    R1 r{r1.getQuantity() + r2.getQuantity()};
    r1.setQuantity(0);
    r2.setQuantity(0);
    return r;
}

/// Division operator for resources
template<class R1, class R2>
constexpr auto div(R1 r1, R2 r2) -> std::enable_if_t<are_same_derivation_v<R1, R2, Resource>, std::div_t>
{
    using std::div;
    return std::div(r1.getQuantity() + r2.getQuantity());
}

/// Grain
///
/// Staple food, every person needs to consume grain to survive
class Grain : public Resource
{
    public:
        constexpr Grain(std::size_t q) : Resource(q) {}
};


/// Frankincense
///
/// A fragrant thing
class Frankincense : public Resource
{
    public:
        constexpr Frankincense(std::size_t q) : Resource(q) {}
};

/// Tool
///
/// A useful gizmo
class Tool : public Resource
{
    public:
        Tool(std::size_t q) : Resource(q) {}
};

#endif // RESOURCE_H_