// ***Problem Desc***: given destination and list of car positions and speeds. find num of groups that’ll reach at target
// ***sort based on position, make descending levels of time in stack [O(n.logn) time | O(n) space]***:
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, int>> cars(n);
    for (int i = 0; i<n; ++i) cars[i] = {position[i], speed[i]};
    
    sort(cars.begin(), cars.end());

    stack<double> fleets;

    for (auto car: cars) {
        double timeNeeded = (target-car.first) / (double) car.second;
        while (!fleets.empty() && fleets.top() <= timeNeeded) fleets.pop();
        fleets.push(timeNeeded);
    }

    return fleets.size();
}
