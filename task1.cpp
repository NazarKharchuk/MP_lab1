#include <iostream>
#include <fstream>

using namespace std;

int main() {
	cout << "\tTask 1)\n";

	string word, correctWord;
	int i;

	ifstream input;
	input.open("input1.txt");

newWord:
	if (!(input >> word)) goto point;
	correctWord = "";
	i = 0;

word—ycle:
	if(!word[i]) goto mbStopWord;

	//cout << word[i] << "\t";
	if ((word[i] >= 'a' && word[i] <= 'z') || word[i] == '-' || word[i] == '\'') {
		correctWord += word[i++];
		goto word—ycle;
	}

	if (word[i] >= 'A' && word[i] <= 'Z') {
		correctWord += word[i++]+32;
		goto word—ycle;
	}

	i++;
	goto word—ycle;

mbStopWord:
	cout << correctWord << endl;

	goto newWord;

point:

	


	input.close();

	return 0;
}