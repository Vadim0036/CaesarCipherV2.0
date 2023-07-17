#include <iostream>
#include <string>

using namespace std;

class Text
{
    private:
        string alphabet; 
        string text;
        int key;

    public:
        Text(string text, int key)
        {
            this->alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            this->text = text;
            this->key = key;
        }

        string encrypt()
        {   
            string encrypted_text = "";

            for(int i = 0; i < this->text.length(); i ++)
            {
                char current_char = this->text[i];
                int current_index = this->alphabet.find(current_char);
                int encrypted_index = current_index + this->key;
                while(encrypted_index > 26)
                {
                    encrypted_index -= 26;
                }
                if(current_char == ' ')
                {
                    encrypted_text = encrypted_text + " ";
                    continue;
                }
                encrypted_text = encrypted_text + this->alphabet[encrypted_index];
            }
            return encrypted_text;
        }

        string decrypt()
        {
            string decrypted_text = "";

            for(int i = 0; i < this->text.length(); i++)
            {
                char current_char = this->text[i];
                char current_index = this->alphabet.find(current_char);
                int decrypted_index = current_index - this->key;
                while(decrypted_index < 0)
                {
                    decrypted_index += 26;
                }
                if(current_char == ' ')
                {
                    decrypted_text += " ";
                    continue;
                }
                decrypted_text += this->alphabet[decrypted_index];
            }
            return decrypted_text;
        }
};