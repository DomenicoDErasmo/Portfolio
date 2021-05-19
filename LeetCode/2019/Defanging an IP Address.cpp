class Solution {
public:
    string defangIPaddr(string address) 
    {
        std::string new_point = "[.]";
        for (size_t address_index = 0; address_index < address.size(); address_index++)
        {
            if (address[address_index] == '.')
            {
                address.replace(address_index, 1, new_point);
                address_index++;
            }
        }
        return address;
    }
};