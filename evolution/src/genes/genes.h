#include <algorithm>
#include <array>
#include "src/common/common.h"

#ifndef EVOLUTION_GENES_H_
#define EVOLUTION_GENES_H_

namespace evolution
{
namespace genes
{

class Genes final
{
    public:
        using gene_container_type = std::array<int, 20>;

        Genes();

        Genes(gene_container_type const& genes) :
            genes_{std::move(genes)}
        {}

        void scramble_genes();
        gene_container_type get_genes() const { return genes_; }

        private:
            gene_container_type genes_{};
};

Genes from_parthenogenesis(Genes const& genes_mother);
Genes from_sexual_reproduction(Genes const& genes_mother, Genes const& genes_father);

}  // namespace genes
}  // namespace evolution

#endif // EVOLUTION_GENES_H_