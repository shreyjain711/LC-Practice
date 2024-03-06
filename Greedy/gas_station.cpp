// ***Problem Desc***: for each i, gas available there and cost from there to next station is given; where can one start to complete a loop

// ***Brute [O(n<sup>2</sup>) time | O(1) space]***: start from each position and try going in a loop

// ***Keep adding up the gas deficit from 0, if it hits -ve, can start from it next so loop from there again, at end eval if gas>=fuel, start stored [O(n) time | O(1) space]***:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int overall=0, start=0, currDiff=0;
    for (int i=0; i<cost.size(); ++i) {
        overall += gas[i]-cost[i];
        currDiff += gas[i]-cost[i];
        if (currDiff < 0) {
            currDiff=0;
            start = i+1;
        }
    }
    
    return overall>=0 ? start : -1;
}
