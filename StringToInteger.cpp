
class Solution {
public:
    int atoi(const char *str) {
    	int integer = 0;
    	int flag = 0;

    	size_t pos = 0;
    	while (pos < str.size())
    	{
    		if (str[pos] == ' ' && !flag && !integer)
    			continue;
    		else 
    			break;

    		
    	}

        

        return integer;
    }
};