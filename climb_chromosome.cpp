#include "climb_chromosome.hh"
#include <random>


//used from https://www.learncpp.com/cpp-tutorial/915-shallow-vs-deep-copying/
Cities::permutation_t deepCopy(permutation_t source)
{
    // because m_length is not a pointer, we can shallow copy it
    int m_length = source.size();
 
    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (source[0])
    {
        // allocate memory for our copy
        permutation_t clone = new permutation_t(m_length);
 
        // do the copy
        for (int i=0; i < m_length; ++i)
            clone[i] = source[i];
    }
    else{
	    return nullptr;}
}

void ClimbChromosome::mutate() override{
  double fitness = get_fitness();
  Chromosome* chrome2 = clone();
  Chromosome* chrome3 = clone();
  chrome2->order_ = deepCopy(order_);
  chrome3->order_ = deepCopy(order_);
  int p = rand()% order_.size();
  int temp = order_[p];
  int temp2;
  if (p == 0){
    temp2 = order_[order_.size()-1];}
  else {
    temp2 = order_[p-1];}	    
  chrome2->order_[p] = temp2;
  chrome2->order_[order_.size()-1] = temp;
  double fitness2 = chrome2->get_fitness();
  if (p == order_.size()-1){
    temp2 = order_[0];}
  else {
    temp2 = order_[p+1];}
  chrome3->order_[p] = temp2;
  chrome3->order_[order_.size()-1] = temp;
  double fitness3 = chrome3->get_fitness();}
  if (fitness1 > fitness2){
    if (fitness1 > fitness3){ 
    }
    if (fitness3 > fitness1){
    order_ = deepCopy(chrome3->order_);    
    }}
  else if (fitness2 > fitness3){
    order_ = deepCopy(chrome2->order_);     
  }
  else {
    order_ = deepCopy(chrome3->order_);
  }
   

 




}

virtual ClimbChromosome::Chromosome* clone() const override;

