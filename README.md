# TSP_PART3

## __Our Method__

What we did was what was assigned. We made a travelling saleswoman problem solver using genetic algorithms, 
local mutations and tournaments to decide which paths are shortest and should be modified to create shorter paths.


## Our Results

Our results are shown in the files:

Baseline.tsv

local.tsv

tournament.tsv

Where the number on the left is the trial number and the number on the right is the path length. This ran 
for 100,000 trials or so, and whenever the path shortened, the resulting path length and trial number were 
recorded. As you can see in the graph comparison.gif, the tournament-style genetic algorithm using local 
mutation got to the shortest path length the quickest. It also, in this case, reached a lower path length than
the other two trials on challenge.tsv with a population size of 8 and mutation rate of 0.4. 

In the future, it would be cool to parellelize this. ;)

