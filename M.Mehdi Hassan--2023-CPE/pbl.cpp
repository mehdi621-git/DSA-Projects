#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include <sys/stat.h> // For file size
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : ch('\0'), freq(l->freq + r->freq), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, unordered_map<char, string>& codes, string str) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = str;
    }
    buildCodes(root->left, codes, str + "0");
    buildCodes(root->right, codes, str + "1");
}

string compressText(const string& text, unordered_map<char, string>& codes) {
    string encoded = "";
    for (char c : text) {
        encoded += codes[c];
    }
    return encoded;
}

void writeBinaryFile(const string& encoded, const string& filename) {
    ofstream out(filename, ios::binary);
    for (size_t i = 0; i < encoded.size(); i += 8) {
        string byte = encoded.substr(i, 8);
        while (byte.length() < 8) byte += '0'; // Padding
        bitset<8> bits(byte);
        char c = static_cast<char>(bits.to_ulong());
        out.write(&c, 1);
    }
    out.close();
}

long getFileSize(const string& filename) {
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

int main() {
    string inputFilename = "input.txt";
    string outputFilename = "compressed.bin";

    ifstream inFile(inputFilename);
    if (!inFile) {
        cerr << "Error opening input file.\n";
        return 1;
    }

    string text((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        pq.push(new Node(it->first, it->second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(new Node(left, right));
    }

    Node* root = pq.top();
    unordered_map<char, string> codes;
    buildCodes(root, codes, "");

    string encodedText = compressText(text, codes);
    writeBinaryFile(encodedText, outputFilename);

    long originalSize = getFileSize(inputFilename);
    long compressedSize = getFileSize(outputFilename);

    cout << "Original Size    : " << originalSize << " bytes\n";
    cout << "Compressed Size  : " << compressedSize << " bytes\n";
    cout << "Space Saved      : " << (originalSize - compressedSize) << " bytes\n";

    return 0;
}
