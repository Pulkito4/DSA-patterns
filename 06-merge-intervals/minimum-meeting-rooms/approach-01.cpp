class Solution {
	public:
	int minMeetingRooms(vector<int> &start, vector<int> &end) {
		int n = start.size();
		int rooms = 0 ;
		int res = 0;
		int i = 0, j = 0;
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());
		// i for start, j for end
		while (i<n && j<n) { // although we know start time will always be less than end
			// so even if we dont apply condition on j it works
			
			if (start[i]<end[j]) {
				rooms++;
				i++;
				res = max(res, rooms);
			} else {
				// either start[i]>end[j]
				// or start[i] == end[j] ->  A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.
				// in either case we do rooms--, j++
				rooms--;
				j++;
			}
		}
		// no need to loop j till the end as we will do rooms-- only and it doesnt affect max/res
		return res;
		
	}
};
