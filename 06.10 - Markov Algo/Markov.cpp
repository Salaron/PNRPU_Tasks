#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int rulesCount;
	string baseString;
	cin >> baseString >> rulesCount;

	vector<string> rulesFrom;
	vector<string> rulesTo;

	for (int i = 0; i < rulesCount; i++) {
		string rule1, ruleType, rule2;
		cin >> rule1 >> ruleType >> rule2;
		rulesFrom.insert(rulesFrom.end(), rule1);
		rulesTo.insert(rulesTo.end(), rule2);
	}

	int RulesExecuted = rulesCount;
	while (RulesExecuted != 0) {
		RulesExecuted = rulesCount;
		for (int i = 0; i < rulesCount; i++) {
			int ind = baseString.find(rulesFrom[i]);
			if (ind != -1) {
				baseString.replace(ind, rulesTo[i].length(), rulesTo[i]);
			}
			else {
				RulesExecuted--;
			}
		}
	}

	cout << baseString << endl;

	return 0;
}