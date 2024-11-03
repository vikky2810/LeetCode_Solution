#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
		int slen = s.length();
		
		for(int i = 0 ; i < slen ; i++)
		{
			s = s.substr(1,slen) + s[0];
			if(s == goal)
			{
				return true;		
			}		
		}        
		return false;
    }
};


int main() {
 	int t ; cin >> t;
 	Solution s;
 	while(t--)
 	{
 		string str1;
		cin >> str1;
		string str2;
		cin >> str2;
		
		bool res = s.rotateString(str1,str2);
		
		if(res)
		{
			cout << "It's true " << endl;
		}
		else
		{
			cout << "It's false " << endl;
		}
	}
    return 0;
}
