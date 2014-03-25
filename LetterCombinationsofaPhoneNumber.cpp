class Solution {
public:
    vector<string> letterCombinations(string digits) {

    	std::unordered_map<char, std::string> phonePad;
    	std::std::vector<std::string> combinationStrs;

    	phonePad['2'] = "abc";
    	phonePad['3'] = "def";
    	phonePad['4'] = "ghi";
    	phonePad['5'] = "jkl";
    	phonePad['6'] = "mno";
    	phonePad['7'] = "pqrs";
    	phonePad['8'] = "tuv";
    	phonePad['9'] = "wxyz";

    	if (digits.size() == 0) {
    		return combinationStrs.push_back("");
    	}

    	std::vector<std::string> interResult = letterCombinations(std::string(digits.begin() + 1, digits.end()));
    	std::string wordStr = phonePad[digits[0]];

    	for (int i = 0; i < (int)wordStr.size(); ++i) {
    		for (int j = 0; j < (int)interResult.size(); ++j) {
    			combinationStrs.push_back("" + wordStr[i] + interResult[j]);
    		}
    	}

    	return combinationStrs;
    }
};
