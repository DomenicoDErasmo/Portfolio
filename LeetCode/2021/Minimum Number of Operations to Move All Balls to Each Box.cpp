class Solution 
{
public:
    vector<int> minOperations(string boxes) 
    {
        std::vector<int> minMoves;
        for (int i = 0; i < boxes.length(); i++)
        {
            minMoves.push_back(getMoves(boxes, i));
        }
        return minMoves;
    }
private:
    int getMoves(std::string boxes, int box)
    {
        int moves = 0;
        for (int i = 0; i < boxes.length(); i++)
        {
            if (boxes[i] == '1')
            {
                moves += absValue(box - i);
            }
        }
        return moves;
    }
    
    int absValue(int val)
    {
        return val > 0 ? val : 0 - val;
    }
};