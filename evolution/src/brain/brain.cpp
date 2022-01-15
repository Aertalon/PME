#include "src/common/common.h"
#include "brain.h"

namespace evolution
{
namespace brain
{

Actions Brain::decide(std::array<int, 6> const& input_outer_layer)
{
    auto genes = genes_.get_genes();
    std::array<int, 2> output_inner_layer = {{
        std::max(0,
            input_outer_layer[0] * genes[0] +
            input_outer_layer[1] * genes[1] +
            input_outer_layer[2] * genes[2] +
            input_outer_layer[3] * genes[3] +
            input_outer_layer[4] * genes[4] +
            input_outer_layer[5] * genes[5]),
        std::max(0,
            input_outer_layer[0] * genes[6] +
            input_outer_layer[1] * genes[7] +
            input_outer_layer[2] * genes[8] +
            input_outer_layer[3] * genes[9] +
            input_outer_layer[4] * genes[10] +
            input_outer_layer[5] * genes[11])
    }};

    std::array<int, 4> output_output_layer = {{
        std::max(0,
            output_inner_layer[0] * genes[12] +
            output_inner_layer[1] * genes[13]),
        std::max(0,
            output_inner_layer[0] * genes[14] +
            output_inner_layer[1] * genes[15]),
        std::max(0,
            output_inner_layer[0] * genes[16] +
            output_inner_layer[1] * genes[17]),
        std::max(0,
            output_inner_layer[0] * genes[18] +
            output_inner_layer[1] * genes[19])}};

    auto selected_action_index = std::distance(
            output_output_layer.begin(),
            std::max_element(
                output_output_layer.begin(),
                output_output_layer.end()));

    //std::cout << "Selected action index: " << selected_action_index << std::endl;

    return static_cast<Actions>(selected_action_index);
}

Actions Brain::decide_random(std::array<int, 6> const&)
{
    return generate_random_action();
}

}  // namespace agent
}  // namespace evolution