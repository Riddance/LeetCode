class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    	std::vector<int> indices;

    	size_t cur_pos = 0;

    	while (cur_pos < S.size())
    	{
            size_t indice = 0;

    		std::vector<string>::iterator Iter = L.begin();
    		while (Iter != L.end())
    		{
                size_t find_pos = S.find((*Iter), cur_pos);

                if (find_pos == std::string::npos)
                    break;

                if (find_pos < indice || indice == 0)
                    indice = find_pos;


    			++Iter;
    		}
    	}
        
    }
};