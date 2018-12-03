//The new selection operator we’ll try is called “tournament selection” 
//because it pits candidate parents against each other to determine which parent gets to recombine. It works as follows:

/*Select P parents at random, where P is a constant power of two that you choose (no bigger than the population size).

Take the first pair in the set of P parents and discard the parent with the lower fitness of the two.

Do the same for the next pair, and so forth. You should have P/2 parents in the resulting set.

 Repeat steps B--C until you’re left with only one parent.*/

#include "tournament_deme.hh"

#include <random>
#include <vector>

std::vector<Chromosome*> TournamentDeme::winners (std::vector<Chromosome*> parents){
    if(parents.size()<=1){
        return parents;
    }
    std::vector<Chromosome*> winning_parents;

    for (long unsigned int i = 0; i < (parents.size())/2; i+=2){
        double fit_1 = parents[i]->get_fitness();
        double fit_2 = parents[i+1]->get_fitness();
        if (fit_1 >= fit_2){
            winning_parents.push_back(parents[i]);
        }
        else{
           winning_parents.push_back(parents[i+1]); 
        }
    }
    return winners(winning_parents);

}


Chromosome* TournamentDeme::tournament_selection(){
    auto random_num_parents = [&]() -> int {
        long unsigned int random = rand() % pop_.size();
        while((2^random) > pop_.size()) {
            random = rand() % pop_.size();
        }
        return 2^random;
    };
    std::vector<Chromosome*> parents;
    for (int i = 0; i < random_num_parents(); i++){
        parents.push_back(select_parent());
    }
    Chromosome* winner = winners(parents)[0];
    return winner;
}

Chromosome* TournamentDeme::select_parent(){
    return tournament_selection();
}



