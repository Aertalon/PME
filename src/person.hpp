#include <string>
#include "src/job.hpp"
#include <iostream>

#ifndef PERSON_H_
#define PERSON_H_

namespace pme
{

class PersonInterface
{
    protected:
        virtual ~PersonInterface() {};
};

template<class Derived>
class Person : public PersonInterface
{
    private:
        std::string name_;
        int money_;

    public:

        constexpr Derived& derived() { return static_cast<Derived&>(*this); }

        constexpr Person(char const* name) :
            name_(std::string{name}),
            money_{0}
            {}

        ~Person() override {};

        // Buys at most a quantity q of resource R
        template<class R>
        constexpr void buy(R q)
        {
            //Person find_seller<R>(); // optional?
        }

        void update()
        {
            //energy_--;
        }

};


class Farmer : public Person<Farmer>
{
    private:
        using Base = Person<Farmer>;

    public:
        constexpr Farmer(char const* name) : Base(name)
        {

        }
};

class Smith : public Person<Smith>
{
    private:
        using Base = Person<Smith>;

    public:
        constexpr Smith(char const* name) : Base(name)
        {

        }
};

}
#endif // PERSON_H_
