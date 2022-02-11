#include <iostream>
#include <fstream>

using namespace std;

int main() {
	cout << "\tTask 1)\n";

	string word, correctWord, tempStr;
	int i, j , countStop = 22, tempInt, N = 25;
	string stopWords[] = {"the", "for", "at", "a", "in", "is", "on", "are", "am", "do", "did", "to", "so", "of", "or", "not", "and", "was", "no", "but", "has", "us" };
	int countWords = 0;
	string* allWords = new string[countWords];
	int* allCount = new int[countWords];
	string* tempAllWords;
	int* tempAllCount;

	ifstream input;
	input.open("input1.txt");

newWord:
	if (!(input >> word)) goto point;
	correctWord = "";
	i = 0;

wordÑycle:
	if (!word[i]) {
		i = 0;
		goto mbStopWord;
	}

	if ((word[i] >= 'a' && word[i] <= 'z') || word[i] == '-' || word[i] == '\'') {
		correctWord += word[i++];
		goto wordÑycle;
	}

	if (word[i] >= 'A' && word[i] <= 'Z') {
		correctWord += word[i++]+32;
		goto wordÑycle;
	}

	i++;
	goto wordÑycle;

mbStopWord:
	if(stopWords[i] == correctWord || correctWord == "" || correctWord == "-" || correctWord == "\'") goto newWord;

	if (i < countStop-1) {
		i++;
		goto mbStopWord;
	}

	//cout << correctWord << ";" << endl;

	i = 0;
countPoint:
	if (i < countWords) {
		if (allWords[i] == correctWord) {
			allCount[i]++;
			goto newWord;
		}
		i++;
		goto countPoint;
	}

	tempAllWords = new string[countWords+1];
	tempAllCount = new int[countWords+1];
	i = 0;
copyMass:
	if (i < countWords) {
		tempAllWords[i] = allWords[i];
		tempAllCount[i] = allCount[i];
		i++;
		goto copyMass;
	}
	tempAllWords[countWords] = correctWord;
	tempAllCount[countWords] = 1;

	countWords++;
	delete[] allWords;
	delete[] allCount;
	allWords = tempAllWords;
	allCount = tempAllCount;
	goto newWord;

point:
	i = 0;
sort1:
	if (i < countWords)
	{
		j = i + 1;
	sort2:
		if (j < countWords)
		{
			if (allCount[i] < allCount[j])
			{
				tempStr = allWords[i];
				allWords[i] = allWords[j];
				allWords[j] = tempStr;

				tempInt = allCount[i];
				allCount[i] = allCount[j];
				allCount[j] = tempInt;
			}
			j++;
			goto sort2;
		}
		i++;
		goto sort1;
	}

	i = 0;
outPoint:
	if (i < countWords && i < N) {
		cout << allWords[i] << " - ";
		cout << allCount[i] << endl;
		i++;
		goto outPoint;
	}

	input.close();

	delete[] allWords;
	delete[] allCount;

	return 0;
}