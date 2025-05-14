#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> buildBadCharTable(const string& pattern) {
    const int CHAR_SIZE = 256;
    vector<int> badChar(CHAR_SIZE, -1);
    for (int i = 0; i < pattern.length(); ++i) {
        badChar[(unsigned char)pattern[i]] = i;
    }
    return badChar;
}

int boyerMooreSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    if (m == 0) return 0;

    vector<int> badChar = buildBadCharTable(pattern);
    int shift = 0;

    while (shift <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            return shift;  
        }
        else {
            int badCharIndex = badChar[(unsigned char)text[shift + j]];
            shift += max(1, j - badCharIndex);
        }
    }

    return -1;  
}

int main() {
    string text, pattern;

    cout << "Metni girin: ";
    getline(cin, text);

    cout << "Aranacak deseni girin: ";
    getline(cin, pattern);

    int result = boyerMooreSearch(text, pattern);

    if (result != -1) {
        cout << "Desen metin icinde bulundu. Konum: " << result << endl;
    }
    else {
        cout << "Desen metin icinde bulunamadi." << endl;
    }

    return 0;
}