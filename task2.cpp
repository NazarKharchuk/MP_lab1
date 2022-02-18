#include <iostream>
#include <fstream>

using namespace std;

int main() {
	cout << "\tTask 2)\n";

	string word, correctWord, tempStr, tempPages, strToStr;
	int i, j, countStop = 22, tempInt;
	string stopWords[] = { "the", "for", "at", "a", "in", "is", "on", "are", "am", "do", "did", "to", "so", "of", "or", "not", "and", "was", "no", "but", "has", "us" };
	int countWords = 0;
	string* allWords = new string[countWords];
	int* allCount = new int[countWords];
	int* allLastPages = new int[countWords];
	string* allPages = new string[countWords];
	string* tempAllWords;
	int* tempAllCount;
	string* tempAllPages;
	int* tempLastPages;
	int lines = 1, pages, tempPage;

	ifstream input;
	input.open("input.txt");

newLine:

	if (input.peek() == '\n') {
		lines++;
		input.get();
		goto newLine;
	}
	//cout << lines << endl;

	pages = lines / 45 + 1;
	if (lines % 45 == 0) pages = lines / 45;

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
		correctWord += word[i++] + 32;
		goto wordÑycle;
	}

	i++;
	goto wordÑycle;

mbStopWord:
	if (stopWords[i] == correctWord || correctWord == "" || correctWord == "-" || correctWord == "\'") goto newLine;

	if (i < countStop - 1) {
		i++;
		goto mbStopWord;
	}

	//cout << correctWord << ";\t" << pages << endl;

	i = 0;
countPoint:
	if (i < countWords) {
		if (allWords[i] == correctWord) {
			allCount[i]++;
			if (allCount[i] <= 100 && allLastPages[i] != pages) {
				strToStr = "";
				tempPage = pages;
				toStr:
					if (tempPage != 0) {
						strToStr = char(tempPage % 10 + 48) + strToStr;
						tempPage = tempPage / 10;
						goto toStr;
					}
				allPages[i] += ", " + strToStr ;
				//cout << "!!!\t" <<strToStr << endl;
				allLastPages[i] = pages;
			}
			goto newLine;
		}
		i++;
		goto countPoint;
	}

	tempAllWords = new string[countWords + 1];
	tempAllCount = new int[countWords + 1];
	tempAllPages = new string[countWords + 1];
	tempLastPages = new int[countWords + 1];
	i = 0;
copyMass:
	if (i < countWords) {
		tempAllWords[i] = allWords[i];
		tempAllCount[i] = allCount[i];
		tempAllPages[i] = allPages[i];
		tempLastPages[i] = allLastPages[i];
		i++;
		goto copyMass;
	}
	tempAllWords[countWords] = correctWord;
	tempAllCount[countWords] = 1;
	tempAllPages[countWords] = "";
	strToStr = "";
	tempPage = pages;
	toStr2:
		if (tempPage != 0) {
			strToStr = char(tempPage % 10 + 48) + strToStr;
			tempPage = tempPage / 10;
			goto toStr2;
		}
	tempAllPages[countWords] += strToStr;
	//cout << "!\t" << tempAllPages[i] << endl;
	tempLastPages[countWords] = pages;

	countWords++;
	delete[] allWords;
	delete[] allCount;
	delete[] allLastPages;
	delete[] allPages;
	allWords = tempAllWords;
	allCount = tempAllCount;
	allPages = tempAllPages;
	allLastPages = tempLastPages;
	goto newLine;

point:
	i = 0;
sort1:
	if (i < countWords)
	{
		j = i + 1;
	sort2:
		if (j < countWords)
		{
			if (allWords[i] > allWords[j])
			{
				tempStr = allWords[i];
				allWords[i] = allWords[j];
				allWords[j] = tempStr;

				tempInt = allCount[i];
				allCount[i] = allCount[j];
				allCount[j] = tempInt;

				tempStr = allPages[i];
				allPages[i] = allPages[j];
				allPages[j] = tempStr;

				/*tempInt = allLastPages[i];
				allLastPages[i] = allLastPages[j];
				allLastPages[j] = tempInt;*/
			}
			j++;
			goto sort2;
		}
		i++;
		goto sort1;
	}

	i = 0;
outPoint:
	if (i < countWords) {
		if (allCount[i]<=100) {
			cout << allWords[i] << " - ";
			//cout << allCount[i] << " - ";
			//cout << allLastPages[i] << " - ";
			cout << allPages[i] << endl;
		}
		i++;
		goto outPoint;
	}

	input.close();

	delete[] allWords;
	delete[] allCount;
	delete[] allPages;
	delete[] allLastPages;

	return 0;
}