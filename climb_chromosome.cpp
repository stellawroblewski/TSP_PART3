#include "climb_chromosome.hh"
#include "chromosome.hh"
#include "cities.hh"

#include <random>


//inspiration taken from https://www.learncpp.com/cpp-tutorial/915-shallow-vs-deep-copying/
Cities::permutation_t deepCopy(Cities::permutation_t source)
{
    // because m_length is not a pointer, we can shallow copy it
    int m_length = source.size();
 
    if(!source[0]){
      return *new Cities::permutation_t(0);
    }
    // allocate memory for our copy
    Cities::permutation_t* clone = new Cities::permutation_t(m_length);

    
        
    
    // do the copy
    for (int i=0; i < m_length; ++i){
      clone->at(i) = source[i];
    }

    return *clone;
}

void ClimbChromosome::mutate(){
  double fitness = get_fitness();
  Chromosome* chrome2 = clone();
  Chromosome* chrome3 = clone();
  chrome2->order_ = deepCopy(order_);
  chrome3->order_ = deepCopy(order_);
  int p = rand()% order_.size();
  int temp = order_[p];
  int temp2;

  //calculating a potential chromosome, chrome2
  if (p == 0){
    temp2 = order_[order_.size()-1];
  }
  else {
    temp2 = order_[p-1];
  }	

  chrome2->order_[p] = temp2;
  chrome2->order_[order_.size()-1] = temp;
  double fitness2 = chrome2->get_fitness();
  
  //calculating another potential chromosome, chrome3
  if (p == order_.size()-1){
    temp2 = order_[0];
  }
  
  else {
    temp2 = order_[p+1];
  }
  chrome3->order_[p] = temp2;
  chrome3->order_[order_.size()-1] = temp;
  double fitness3 = chrome3->get_fitness();
  
  //checking to see which chromosome has best fitness and 
  //setting this chromosome to have that best order
  if (fitness1 > fitness2){
    if (fitness1 > fitness3){ 
    }
    if (fitness3 > fitness1){
    order_ = deepCopy(chrome3->order_);    
    }
  }
  else if (fitness2 > fitness3){
    order_ = deepCopy(chrome2->order_);     
  }
  else {
    order_ = deepCopy(chrome3->order_);
  }

  //deleting chrome2 and chrome3
  delete chrome2;
  delete chrome3;
}

virtual ClimbChromosome::Chromosome* clone() const{ //we don't need override in the definition here
  return new ClimbChromosome(cities_ptr_);
}

