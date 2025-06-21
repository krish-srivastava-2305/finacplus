#include <iostream>
#include <string>
using namespace std;

class CaesarCipher
{
private:
    int shift;

    string encode(string text)
    {
        string encodedText;
        int i = 0;
        while (i < text.length())
        {
            char ch = text[i];
            int count = 1;

            while (i + 1 < text.length() && text[i + 1] == ch)
            {
                count++;
                i++;
            }

            if (count > 1)
            {
                encodedText += ch + to_string(count);
            }
            else
            {
                encodedText += ch;
            }

            i++;
        }
        return encodedText;
    }

public:
    CaesarCipher(int shift)
    {
        this->shift = shift % 26;
    }

    string encrypt(string text)
    {
        string encryptedText;

        for (char ch : text)
        {
            char shifted = ((ch - 'A' + shift) % 26) + 'A';
            encryptedText += shifted;
        }

        return encode(encryptedText);
    }
};

int main()
{
    CaesarCipher cipher(3);
    cout << cipher.encrypt("AABCCC") << endl; // Output: D2EF3
    cout << cipher.encrypt("HELLO") << endl;  // Output: KHO2
    return 0;
}
