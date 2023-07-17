#include <iostream>
#include <string>
#include <cctype>

#include "Text.cpp"

using namespace std;

class CaesarCipher
{
    private:
        string output;
        string text;
        int key;
        
    public:
        CaesarCipher()
        {
            this->text = toUpper(getText());
            this->key = getKey();

            this->output = "";
        }

        void runProgram()
        {   
            Text text_obj(this->text, this->key);
            string response; 

            cout << "What do you want to do ENCRYPT or DECRYPT?" << endl;
            cin >> response; 
            

            if(toUpper(response) == "ENCRYPT")
            {
                this->output = text_obj.encrypt();

                cout << "Original: " << this->text << endl;
                cout << "Encrypted: " << this->output << endl;
            }
            else
            {
                this->output = text_obj.decrypt();

                cout << "Original: " << this->text << endl;
                cout << "Decrypted: " << this->output << endl;
            }
        }

    private:
        string getText()
        {
            string text;

            cout << "Enter text you want to encrypt: " << endl;
            getline(cin, text);
            return text;
        }

        int getKey()
        {
            int key;

            cout << "Enter encryption key: " << endl;
            cin >> key;

            return key;
        }
        
        string toUpper(string text)
        {
            string upperCase = "";
            for(int i = 0; i < text.length(); i++)
            {
                char c = text[i];
                upperCase += toupper(c);
            }
            return upperCase;
        }
};