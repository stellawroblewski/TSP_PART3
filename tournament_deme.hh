#pragma once

#include "chromosome.hh"
#include "climb_chromosome.hh"
#include "cities.hh"
#include "deme.hh"
#include <random>
#include <vector>

class TournamentDeme : public Deme{
    
  public:
    
    TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate) 
    : Deme(cities_ptr, pop_size, mut_rate){}

    Chromosome* select_parent() override;

    Chromosome* tournament_selection();

    std::vector<Chromosome*> winners(std::vector<Chromosome*> parents);
};


