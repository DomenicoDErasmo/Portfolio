class Solution {
public:
   
    char IntToChar(int number)
    {
        switch (number)
        {
            case 0:
                return '0';
                break;
            case 1:
                return '1';
                break;
            case 2:
                return '2';
                break;
            case 3:
                return '3';
                break;
            case 4:
                return '4';
                break;
            case 5:
                return '5';
                break;
            case 6:
                return '6';
                break;
            case 7:
                return '7';
                break;
            case 8:
                return '8';
                break;
            case 9:
                return '9';
                break;
            default:
                return '.';
                break;
        }
    }
    
    bool IsValidBox(std::vector<std::vector<char>>& board, int horizontal_box, int vertical_box)
    {
        int horizontal_min = horizontal_box * 3, horizontal_max = horizontal_min + 3;
        int vertical_min = vertical_box * 3, vertical_max = vertical_min + 3;
        
        for (int number_to_check = 0; number_to_check < 10; number_to_check++)
        {
            int box_frequency = 0;
            for (int hor_pos = horizontal_min; hor_pos < horizontal_max; hor_pos++)
            {
                for (int ver_pos = vertical_min; ver_pos < vertical_max; ver_pos++)
                {
                    if (board[hor_pos][ver_pos] == IntToChar(number_to_check))
                    {
                        box_frequency++;
                    }
                    if (box_frequency > 1)
                    {
                        std::cout << number_to_check << " was found in box " << horizontal_box + 1 << ", " << vertical_box << " too many times. Invalid!\n";
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool ValidBoxes(std::vector<std::vector<char>>& board)
    {
        for (int horizontal_box = 0; horizontal_box < 3; horizontal_box++)
        {
            for (int vertical_box = 0; vertical_box < 3; vertical_box++)
            {
                if (!IsValidBox(board, horizontal_box, vertical_box))
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool ValidColumns(std::vector<std::vector<char>>& board)
    {
        for (int number_to_check = 0; number_to_check < 10; number_to_check++)
        {   
            for (int row_index = 0; row_index < 9; row_index++)
            {
                int col_frequency = 0;  
                for (int col_index = 0; col_index < 9; col_index++)
                {
                    if (board[col_index][row_index] == IntToChar(number_to_check))
                    {
                        col_frequency++;
                    }
                    if (col_frequency > 1)
                    {
                        std::cout << number_to_check << " was found multiple times in column " << row_index << ". Invalid!\n";
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool ValidRows(std::vector<std::vector<char>>& board)
    {
        for (int number_to_check = 0; number_to_check < 10; number_to_check++)
        {
            for (int row_index = 0; row_index < 9; row_index++)
            {
                int col_frequency = 0;
                for (int col_index = 0; col_index < 9; col_index++)
                {
                    if (board[row_index][col_index] == IntToChar(number_to_check))
                    {
                        col_frequency++;
                    }
                    if (col_frequency > 1)
                    {
                        std::cout << number_to_check << " was found multiple times in row " << row_index << ". Invalid!\n";
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(std::vector<std::vector<char>>& board) 
    {
        if (ValidRows(board) && ValidColumns(board) && ValidBoxes(board))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};