#include <array>
#include "src/common/common.h"
#include "src/genes/genes.h"


#ifndef EVOLUTION_BRAIN_H_
#define EVOLUTION_BRAIN_H_

namespace evolution
{
namespace agent
{
    class Tree;
    class AgentPerception;
}

namespace brain
{
class Brain final
{
    genes::Genes genes_{};

    public:
        Brain () = default;
        Brain(genes::Genes const& genes) :
            genes_{std::move(genes)}
        {}

        Brain(Brain const& mother)
        {
            genes_ = genes::from_parthenogenesis(mother.get_genes());
        }

        Actions decide(std::array<int, 6> const& input_outer_layer);
        Actions decide_random(std::array<int, 6> const& input_outer_layer);

        genes::Genes get_genes() const { return genes_; }
};

}  // namespace agent
}  // namespace evolution

#endif // EVOLUTION_BRAIN_H_