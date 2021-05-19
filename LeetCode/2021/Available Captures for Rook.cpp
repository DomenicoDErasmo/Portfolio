class Solution {
public:
    
    std::vector<int> returnRookCoordinates(std::vector<std::vector<char>>& board)
    {
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                if (board[row][col] == 'R')
                {
                    std::vector<int> location = {row, col};
                    return location;
                }
            }
        }
        std::vector<int> not_found = {-1, -1};
        return not_found;
    }
    
    int numLeftCaptures(std::vector<std::vector<char>>& board, std::vector<int> rook_coords)
    {
        int num_left_captures = 0;
        int row = rook_coords[0];
        int rook_col = rook_coords[1];
        
        for (int col = 0; col < rook_col; col++)
        {
            if (board[row][col] == 'p')
            {
                num_left_captures = 1;
            }
            else if (board[row][col] == 'B')
            {
                num_left_captures = 0;
            }
        }
        std::cout << "Left Captures: " << num_left_captures << std::endl;
        return num_left_captures;
    }
    
    int numRightCaptures(std::vector<std::vector<char>>& board, std::vector<int> rook_coords)
    {
        int num_right_captures = 0;
        int row = rook_coords[0];
        int rook_col = rook_coords[1];
        
        for (int col = 7; col > rook_col; col--)
        {
            if (board[row][col] == 'p')
            {
                num_right_captures = 1;
            }
            else if (board[row][col] == 'B')
            {
                num_right_captures = 0;
            }
        }
        std::cout << "Right Captures: " << num_right_captures << std::endl;
        return num_right_captures;
    }
    
    int numRowCaptures(std::vector<std::vector<char>>& board, std::vector<int> rook_coords)
    {
        int left_captures = numLeftCaptures(board, rook_coords);
        int right_captures = numRightCaptures(board, rook_coords);
        int row_captures = left_captures + right_captures;
        return row_captures;
    }
    
    int numUpCaptures(std::vector<std::vector<char>>& board, std::vector<int> rook_coords)
    {
        int num_up_captures = 0;
        int col = rook_coords[1];
        int rook_row = rook_coords[0];
        
        for (int row = 0; row < rook_row; row++)
        {
            if (board[row][col] == 'p')
            {
                num_up_captures = 1;
            }
            else if (board[row][col] == 'B')
            {
                num_up_captures = 0;
            }
        }
        std::cout << "Up Captures: " << num_up_captures << std::endl;
        return num_up_captures;
    }
    
    int numDownCaptures(std::vector<std::vector<char>>& board, std::vector<int> rook_coords)
    {
        int num_down_captures = 0;
        int col = rook_coords[1];
        int rook_row = rook_coords[0];
        
        for (int row = 7; row > rook_row; row--)
        {
            if (board[row][col] == 'p')
            {
                num_down_captures = 1;
            }
            else if (board[row][col] == 'B')
            {
                num_down_captures = 0;
            }
        }
        std::cout << "Down Captures: " << num_down_captures << std::endl;
        return num_down_captures;
    }
    
    int numColCaptures(std::vector<std::vector<char>>& board, std::vector<int> rook_coords)
    {
        int up_captures = numUpCaptures(board, rook_coords);
        int down_captures = numDownCaptures(board, rook_coords);
        int col_captures = up_captures + down_captures;
        return col_captures;
    }
    
    int numRookCaptures(vector<vector<char>>& board) 
    {
        std::vector<int> rook_coords = returnRookCoordinates(board);
        std::cout << "Rook coordinates: " << rook_coords[0] << ", " << rook_coords[1] << std::endl;
        
        int num_row_captures = numRowCaptures(board, rook_coords);
        int num_col_captures = numColCaptures(board, rook_coords);
       
        int num_rook_captures = num_row_captures + num_col_captures;
        return num_rook_captures;
    }

};