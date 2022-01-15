#include "genes.h"

namespace evolution
{
namespace genes
{

IntRandomGenerator<-100, 100> gene_int_generator{};
IntRandomGenerator<-10, 10> gene_mutation_int_generator{};
IntRandomGenerator<0, 1> gene_bool_generator{};

Genes::Genes()
{
    for (auto& g: genes_)
    {
        g = gene_int_generator.generate();
    }
}

void Genes::scramble_genes()
{
    for (auto& g: genes_)
    {
        g += gene_mutation_int_generator.generate();
    }
}

Genes from_parthenogenesis(Genes const& genes_mother)
{
    // copy mother's genes and mutate them
    Genes genes{genes_mother.get_genes()};
    genes.scramble_genes();
    return genes;
}

Genes from_sexual_reproduction(Genes const& genes_mother, Genes const& genes_father)
{
    // mix up father and mother genes
    Genes::gene_container_type genes_container{};
    std::transform(
        genes_mother.get_genes().begin(),
        genes_mother.get_genes().end(),
        genes_father.get_genes().begin(),
        genes_container.begin(),
        [](int m, int f) -> int
        {
            if (gene_bool_generator.generate() > 0) { return m; }
            return f;
        });

    // mutate
    Genes genes{genes_container};
    genes.scramble_genes();
    return genes;
}

}  // namespace genes
}  // namespace evolution
