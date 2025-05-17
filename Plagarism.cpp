#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Convert string to lowercase
string toLowerCase(const string& str) {
    string lower = str;
    for (size_t i = 0; i < str.length(); ++i) {
        lower += tolower(str[i]);
    }
    return lower;
}

// Remove punctuation and extra spaces
string cleanText(const string& str) {
    string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (isalnum(str[i]) || isspace(str[i])) {
            result += tolower(str[i]);
        }
    }
    return result;
}

// Split text into words
int tokenize(const string& text, string words[], int maxWords) {
    int count = 0;
    string word;
    for (size_t i = 0; i <= text.length(); ++i) {
        if (i == text.length() || isspace(text[i])) {
            if (!word.empty() && count < maxWords) {
                words[count++] = word;
                word.clear();
            }
        } else {
            word += text[i];
        }
    }
    return count;
}

// Calculate Jaccard similarity
double jaccardSimilarity(string words1[], int size1, string words2[], int size2) {
    int intersectionCount = 0;
    int unionCount = size1 + size2;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (words1[i] == words2[j]) {
                intersectionCount++;
                break;
            }
        }
    }
    unionCount -= intersectionCount;
    return (unionCount == 0) ? 0.0 : (double)intersectionCount / unionCount * 100;
}

int main() {
    const int MAX_DOCS = 10;
    const int MAX_WORDS = 1000;
    int numDocs;
    cout << "Enter the number of documents to compare: ";
    cin >> numDocs;
    cin.ignore();

    string documents[MAX_DOCS];
    for (int i = 0; i < numDocs; ++i) {
        cout << "\nEnter text for document " << i + 1 << ":\n";
        string line, text;
        while (getline(cin, line) && !line.empty()) {
            text += line + " ";
        }
        documents[i] = cleanText(text);
    }

    for (int i = 0; i < numDocs; ++i) {
        for (int j = i + 1; j < numDocs; ++j) {
            string words1[MAX_WORDS], words2[MAX_WORDS];
            int size1 = tokenize(documents[i], words1, MAX_WORDS);
            int size2 = tokenize(documents[j], words2, MAX_WORDS);
            double similarity = jaccardSimilarity(words1, size1, words2, size2);
            cout << "\nSimilarity between Document " << i + 1 << " and Document " << j + 1 << ": " << similarity << "%\n";
        }
    }

    return 0;
}

