#include <cstdlib>
#include <type_traits>
#include "resource.h"

template<class R>
int Resource::will_finish_in(R consumed)
{
    std::div_t result = div(this, consumed);
    return result.quot;
}
