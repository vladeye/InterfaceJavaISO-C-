
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class utility
{
public:
	utility(void);
	~utility(void);
	void Tokenize(const string& str,vector<string>& tokens, string del);

};
