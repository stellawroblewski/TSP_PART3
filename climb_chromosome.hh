#pragma once

#include "chromosome.hh"

#include "cities.hh"
#include <random>

class ClimbChromosome : public Chromosome{
	
  public:
  	ClimbChromosome(const Cities* cities_ptr) 
  		: Chromosome(cities_ptr){}

  	double get_fitness() const {
  		return Chromosome::get_fitness();
  	} 

    void mutate() override;

    virtual Chromosome* clone() const override;
};

