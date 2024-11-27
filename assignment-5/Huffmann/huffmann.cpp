<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

class Compare {
public:
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

Node* buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        Node* sumNode = new Node('\0', sum);
        sumNode->left = left;  
        sumNode->right = right;
        pq.push(sumNode);
    }
    return pq.top();
}

string readFile(const string& filename) {
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

void writeCompressedFile(const string& filename, const string& compressedData) {
    ofstream outFile(filename, ios::binary);
    outFile << compressedData;
    outFile.close();
}

int calculateCompressedSize(const string& text, const unordered_map<char, string>& huffmanCode) {
    int compressedSize = 0;
    for (char ch : text) {
        compressedSize += huffmanCode.at(ch).length();
    }
    return compressedSize;
}

int main() {
    string filename = "test.txt";
    string content = readFile(filename);

    Node* root = buildHuffmanTree(content);

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    string compressedData = "";
    for (char ch : content) {
        compressedData += huffmanCode[ch];
    }

    writeCompressedFile("compressed.txt", compressedData);

    int originalSize = content.length() * 8;
    int compressedSize = calculateCompressedSize(content, huffmanCode);

    double compressionRatio = (double)compressedSize / originalSize;
    double compressionPercentage = 100 * (1 - compressionRatio);

    cout << "\nOriginal File Size: " << originalSize << " bits\n";
    cout << "Compressed File Size: " << compressedSize << " bits\n";
    cout << "Compression Ratio: " << compressionRatio << '\n';
    cout << "Compression Percentage: " << compressionPercentage << "%\n";

    cout << "\nFile has been compressed and saved as 'compressed.bin'.\n";

    return 0;
}
=======
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

class Compare {
public:
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

Node* buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        Node* sumNode = new Node('\0', sum);
        sumNode->left = left;
        sumNode->right = right;
        pq.push(sumNode);
    }

    return pq.top();
}

string readFile(const string& filename) {
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

void writeCompressedFile(const string& filename, const string& compressedData) {
    ofstream outFile(filename, ios::binary);
    outFile << compressedData;
    outFile.close();
}

int calculateCompressedSize(const string& text, const unordered_map<char, string>& huffmanCode) {
    int compressedSize = 0;
    for (char ch : text) {
        compressedSize += huffmanCode.at(ch).length();
    }
    return compressedSize;
}

int main() {
    string filename = "test.txt";
    string content = readFile(filename);

    Node* root = buildHuffmanTree(content);

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    string compressedData = "";
    for (char ch : content) {
        compressedData += huffmanCode[ch];
    }

    writeCompressedFile("compressed.txt", compressedData);

    int originalSize = content.length() * 8;
    int compressedSize = calculateCompressedSize(content, huffmanCode);

    double compressionRatio = (double)compressedSize / originalSize;
    double compressionPercentage = 100 * (1 - compressionRatio);

    cout << "\nOriginal File Size: " << originalSize << " bits\n";
    cout << "Compressed File Size: " << compressedSize << " bits\n";
    cout << "Compression Ratio: " << compressionRatio << '\n';
    cout << "Compression Percentage: " << compressionPercentage << "%\n";

    cout << "\nFile has been compressed and saved as 'compressed.bin'.\n";

    return 0;
}
>>>>>>> 53c1411c0f7ca24e245570a6a7c07b5b4fd393d4
