// ***Problem Desc***: given meeting schedules, find min number of rooms required to accomodate all

// ***keep track of how many have started vs ended, the max diff between these two during iter is the ans [O(n.logn) time | O(n) space]***:
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int>starts, ends;
    for(auto i: intervals) 
        {starts.push_back(i[0]);ends.push_back(i[1]);}
    int ans=1, i=0, j=0;
    while (i<intervals.size()) {
    if (starts[i] > ends[j]) j++;
    else if (starts[i] < ends[j]) i++;
    else {i++; j++;}
    ans = max(ans, i-j);
    } return ans;
}
