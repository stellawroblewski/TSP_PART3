#pragma once

#include "chromosome.hh"
#include "climb_chromosome.hh"
#include "cities.hh"
#include "deme.hh"
#include <random>
#include <vector>

class TournamentDeme : public Deme{
    
  public:
    void compute_next_generation() override;

    void tournament_selection();

private:
    std::vector<Chromosome::Chromosome*> winners (std::vector<Chromosome::Chromosome*> parents);


