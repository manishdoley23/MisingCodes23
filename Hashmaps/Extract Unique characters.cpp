#include<unordered_map>
string uniqueChar(string str) {
	string ans;
	unordered_map<int, bool> map;
	for(int i=0; i<str.size(); ++i){
		if(map[str[i]]) continue;
		ans.push_back(str[i]);
		map[str[i]] = 1;
	}
	return ans;
}
