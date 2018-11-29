#include "Chromosome.hh"

class ClimbChromosome : public Chromosome{
	
  public:
    void mutate() override;

    virtual Chromosome* clone() const override;

