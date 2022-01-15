#include "common.h"

namespace evolution
{

IntRandomGenerator<0, 3> intrand_for_actions{};

Actions generate_random_action()
{
    return static_cast<Actions>(intrand_for_actions.generate());
}

}  // namespace evolution
