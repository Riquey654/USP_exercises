#include <bits/stdc++.h>

using namespace std;

struct TrieNode {

    TrieNode* childNode[26];
    int wordCount;

    TrieNode() {

        wordCount = 0;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }

    }
};

void insert(TrieNode* raiz, string& palavra);
bool remove(TrieNode* raiz, string& palavra);
int countPrefix(TrieNode* raiz, string& prefix);
int contaPalavras(TrieNode* node);

int main() {
    TrieNode* raiz = new TrieNode();

    int q;
    int option;
    string word;
    vector<int> vetorOption;
    vector<string> vetorWord;
    cin >> q;

    for (int h = 0; h < q; h++) {
        cin >> option;
        vetorOption.push_back(option);
        cin >> word;
        vetorWord.push_back(word);
    }

    for (int h = 0; h < q; h++) {
        switch (vetorOption[h]) {
            case 1:
                insert(raiz, vetorWord[h]);
                break;
            case 2:
                remove(raiz, vetorWord[h]);
                break;
            case 3:
                int resultado = countPrefix(raiz, vetorWord[h]);
                cout << resultado << endl;
                break;
        }
    }
    return 0;
}

void insert(TrieNode* raiz, string& palavra) {

    TrieNode* noAtual = raiz;

    for (auto c : palavra) {

        if (noAtual->childNode[c - 'a'] == NULL) {
            noAtual->childNode[c - 'a'] = new TrieNode();
        }
        noAtual = noAtual->childNode[c - 'a'];
    }

    noAtual->wordCount++;
}

bool remove(TrieNode* raiz, string& palavra) {

    TrieNode* noAtual = raiz;
    TrieNode* lastBranchNode = NULL;
    char lastBranchChar = 'a';

    for (auto c : palavra) {

        if (noAtual->childNode[c - 'a'] == NULL) {
            return false;
        } else {

            int count = 0;
            for (int i = 0; i < 26; i++) {
                if (noAtual->childNode[i] != NULL) count++;
            }

            if (count > 1) {

                lastBranchNode = noAtual;
                lastBranchChar = c;
            }
            noAtual = noAtual->childNode[c - 'a'];
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (noAtual->childNode[i] != NULL) count++;
    }

    if (count > 0) {

        noAtual->wordCount--;
        return true;
    }

    if (lastBranchNode != NULL) {
        lastBranchNode->childNode[lastBranchChar] = NULL;
        return true;
    } else {
        raiz->childNode[palavra[0] - 'a'] = NULL;
        return true;
    }
}

int countPrefix(TrieNode* raiz, string& prefix) {

    TrieNode* noAtual = raiz;

    for (char c : prefix) {

        if (noAtual->childNode[c - 'a'] == NULL) {
            return 0;
        }
        noAtual = noAtual->childNode[c - 'a'];
    }

    return contaPalavras(noAtual);
}

int contaPalavras(TrieNode* node) {

    if (node == NULL) return 0;

    int count = node->wordCount;

    for (int i = 0; i < 26; i++) {
        count += contaPalavras(node->childNode[i]);
    }

    return count;
}
