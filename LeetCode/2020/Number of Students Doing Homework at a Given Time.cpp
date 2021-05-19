class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) 
    {
        int num_students = 0;
        for(int student = 0; student < startTime.size(); student++)
        {
            if((startTime[student] <= queryTime) and (endTime[student] >= queryTime))
            {
                num_students++;
            }
        }
        return num_students;
    }
};