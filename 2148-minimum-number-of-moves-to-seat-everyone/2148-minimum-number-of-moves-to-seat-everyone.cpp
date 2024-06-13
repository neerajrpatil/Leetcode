class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // 1 3 5
        int n=seats.size();
        sort(begin(seats),end(seats));
        sort(begin(students),end(students));
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(seats[i]-students[i]);
        }
        return ans;
    }
};