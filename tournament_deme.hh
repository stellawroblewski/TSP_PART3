#pragma once

#include "chromosome.hh"
#include "climb_chromosome.hh"
#include "cities.hh"
#include "deme.hh"
#include <random>
#include <vector>

class TournamentDeme : public Deme{
    
  public:
    Chromosome* select_parent() override;

    Chromosome* tournament_selection();

    std::vector<Chromosome*> winners(std::vector<Chromosome*> parents);
};


