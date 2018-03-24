#include <iostream>
#include <string>
using namespace std;

string solve(string s) {

	if (s.size() == 1) {
		return s;
	}

	//cout << "Solving " << s << endl;
	string firstOperand;
	string secondOperand;
	string operateur;

	int i = 1;
	if (s[0] == '(') {
		int count = 1;
		while (count != 0) {
			if (s[i] == '(') {
				count++;
			}
			if (s[i] == ')') {
				count--;
			}
			i++;
		}
		if (i == s.size()) {
			return solve(s.substr(1, i-2));
		}
		firstOperand = solve(s.substr(0, i));
	} else {
		firstOperand = s[0];
	}

	operateur = s[i];

	secondOperand = solve(s.substr(i+1, s.size()-1));

	return firstOperand + secondOperand + operateur;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		string s;
		cin >> s;

		cout << solve(s) << endl;
	}
	return 0;
}