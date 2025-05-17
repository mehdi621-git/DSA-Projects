#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string choice, filename, line, wordToSearch;
    char caseOption;
    bool caseInsensitive = false;

    int characters = 0, words = 0, lines = 0, spaces = 0, wordFrequency = 0;
    string text = "", word = "";

    cout << "Enter (F) for file input or (T) to type manually: ";
    cin >> choice;
    cin.ignore();

    if (choice == "F" || choice == "f") {
        cout << "Enter file name (e.g., sample.txt): ";
        getline(cin, filename);

        ifstream file(filename.c_str());
        if (!file) {
            cout << "Error: Cannot open file!" << endl;
            return 1;
        }

        while (getline(file, line)) {
            lines++;
            text += line + "\n";
        }

        file.close();
    } else {
        cout << "Enter text (Ctrl+Z then Enter to end):\n";
        while (getline(cin, line)) {
            lines++;
            text += line + "\n";
        }
    }

    cout << "Case-insensitive word search? (y/n): ";
    cin >> caseOption;
    cin.ignore();
    caseInsensitive = (caseOption == 'y' || caseOption == 'Y');

    cout << "Enter a word to count frequency (or press Enter to skip): ";
    getline(cin, wordToSearch);

    // Convert search word to lowercase if needed
    if (caseInsensitive) {
        for (int i = 0; i < wordToSearch.length(); i++)
            wordToSearch[i] = tolower(wordToSearch[i]);
    }

    // Analyze the text
    for (int i = 0; i < text.length(); i++) {
        characters++;

        if (text[i] == ' ')
            spaces++;

        if (isalnum(text[i])) {
            char ch = text[i];
            if (caseInsensitive)
                ch = tolower(ch);
            word += ch;
        } else {
            if (word != "") {
                words++;
                if (wordToSearch != "" && word == wordToSearch)
                    wordFrequency++;
                word = "";
            }
        }
    }

    if (word != "") { // count last word
        words++;
        if (wordToSearch != "" && word == wordToSearch)
            wordFrequency++;
    }

    cout << "\n--- Text Analysis ---\n";
    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters (with spaces): " << characters << endl;
    cout << "Spaces: " << spaces << endl;
    if (wordToSearch != "")
        cout << "Frequency of '" << wordToSearch << "': " << wordFrequency << endl;

    return 0;
}

