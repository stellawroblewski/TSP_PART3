#include "climb_chromosome.hh"
#include "chromosome.hh"
#include "cities.hh"

#include <random>


//inspiration taken from https://www.learncpp.com/cpp-tutorial/915-shallow-vs-deep-copying/
//Cities::permutation_t deepCopy(Cities::permutation_t source)
/*{
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
    }*/


ClimbChromosome* ClimbChromosome::clone() const{ //we don't need override in this line here
  return new ClimbChromosome(cities_ptr_);
}

void ClimbChromosome::mutate(){
  double fitness1 = get_fitness();
  ClimbChromosome* chrome2 = clone();
  ClimbChromosome* chrome3 = clone();
  chrome2->order_ = order_;
  chrome3->order_ = order_;
  unsigned int p = rand() % (order_.size());
  unsigned int p_order = order_[p];
  if (p!=0){
    chrome2->order_[p] = order_[p-1];
    chrome2->order_[p-1] = p_order; 
  }
  else{
    chrome2->order_[p] = order_[order_.size()-1];
    chrome2->order_[order_.size()-1] = p_order;
  }
  double fitness2 = chrome2->get_fitness();
  if (p!=(order_.size()-1)){
    chrome3->order_[p] = order_[p+1];
    chrome3->order_[p+1] = p_order;
  }
  else{
    chrome3->order_[p] = order_[0];
    chrome3->order_[0] = p_order;
  }
  double fitness3 = chrome3->get_fitness();

  //checking to see which chromosome has best fitness and 
  //setting this chromosome to have that best order
  if (fitness1 > fitness2){
    if (fitness1 > fitness3){ 
    }
    if (fitness3 > fitness1){
    order_ = chrome3->order_;    
    }
  }
  else if (fitness2 > fitness3){
    order_ = chrome2->order_;     
  }
  else {
    order_ = chrome3->order_;
  }
}








