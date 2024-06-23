//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <Windows.h>
//
//using namespace std;
//
//class VigenereCipher {
//public:
//    static string encrypt(const string& plaintext, const string& key, const string& alphabet) {
//        string ciphertext;
//        string lower_plaintext = toLowerCase(plaintext);
//        string lower_key = toLowerCase(key);
//        int keyLength = lower_key.length();
//        int alphabetLength = alphabet.length();
//
//        for (size_t i = 0, j = 0; i < lower_plaintext.length(); ++i) {
//            char plainChar = lower_plaintext[i];
//            char cipherChar;
//            char keyChar = lower_key[j % keyLength];
//            int plainIndex = alphabet.find(plainChar);
//            int keyIndex = alphabet.find(keyChar);
//            int cipherIndex = (plainIndex + keyIndex) % alphabetLength;
//            cipherChar = alphabet[cipherIndex];
//            ++j;
//
//            if (isUpperCase(plaintext[i])) {
//                cipherChar = toupper(cipherChar);
//            }
//
//            ciphertext.push_back(cipherChar);
//        }
//
//        return ciphertext;
//    }
//
//    static string decrypt(const string& ciphertext, const string& key, const string& alphabet) {
//        string plaintext;
//        string lower_ciphertext = toLowerCase(ciphertext);
//        string lower_key = toLowerCase(key);
//        int keyLength = lower_key.length();
//        int alphabetLength = alphabet.length();
//
//        for (size_t i = 0, j = 0; i < lower_ciphertext.length(); ++i) {
//            char cipherChar = lower_ciphertext[i];
//            char plainChar;
//            char keyChar = lower_key[j % keyLength];
//            int cipherIndex = alphabet.find(cipherChar);
//            int keyIndex = alphabet.find(keyChar);
//            int plainIndex = (cipherIndex - keyIndex + alphabetLength) % alphabetLength;
//            plainChar = alphabet[plainIndex];
//            ++j;
//
//            if (isUpperCase(ciphertext[i])) {
//                plainChar = toupper(plainChar);
//            }
//
//            plaintext.push_back(plainChar);
//        }
//
//        return plaintext;
//    }
//
//private:
//    static string toLowerCase(const string& str) {
//        string result = str;
//        transform(result.begin(), result.end(), result.begin(), ::tolower);
//        return result;
//    }
//
//    static bool isUpperCase(char c) {
//        return isupper(static_cast<unsigned char>(c));
//    }
//};
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    setlocale(LC_ALL, "ru");
//
//    string plaintext = "HelloWorldÁîëüøîé ìàëü÷èê";
//    string key = "Keyäøèâìôèì2783414=ı.()ÚÕÇÆıææş.áş--==++_";
//    string alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿabcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|} ~ ";
//
//    string encrypted = VigenereCipher::encrypt(plaintext, key, alphabet);
//    string decrypted = VigenereCipher::decrypt(encrypted, key, alphabet);
//
//    cout << "Plaintext: " << plaintext << endl;
//    cout << "Encrypted: " << encrypted << endl;
//    cout << "Decrypted: " << decrypted << endl;
//
//    return 0;
//}
