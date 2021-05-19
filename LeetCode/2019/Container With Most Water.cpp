class Solution {
public:
    
    int MinHeight(int first_height, int second_height)
    {
        if (first_height < second_height)
        {
            return first_height;
        }
        else
        {
            return second_height;
        }
    }
    
    int maxArea(vector<int>& height) 
    {
        int max_area = 0, area = 0;

        for (int first_end = 0; first_end < height.size(); first_end++)
        {
            
            for (int second_end = 0; second_end < height.size(); second_end++)
            {
                area = MinHeight(height[first_end], height[second_end]) * (second_end - first_end);
                if (area > max_area)
                {
                    max_area = area;
                }
            }
        }
        
        return max_area;
        
    }
};