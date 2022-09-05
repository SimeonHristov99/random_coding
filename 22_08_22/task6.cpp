#include <cmath>

std::string split_concat(const std::string &text, const size_t len_text)
{
    std::string evens;
    std::string odds;

    for (size_t i = 0; i < len_text; ++i)
    {
        if (i % 2 == 0)
        {
            evens.push_back(text[i]);
        }
        else
        {
            odds.push_back(text[i]);
        }
    }

    return odds + evens;
}

std::string encrypt(std::string text, int n)
{
    size_t len_text = text.length();

    for (int i = 0; i < n; ++i)
    {
        text = split_concat(text, len_text);
    }

    return text;
}

std::string split_interlieve(const std::string &encryptedText, const size_t len_text, const bool isEven)
{
    std::string decrypted;

    for (size_t i = 0; i < len_text; ++i)
    {
        decrypted.push_back(encryptedText[i + len_text]);
        decrypted.push_back(encryptedText[i]);
    }

    if (isEven)
    {
        decrypted.push_back(encryptedText[len_text * 2]);
    }

    return decrypted;
}

std::string decrypt(std::string encryptedText, int n)
{
    size_t len_text = encryptedText.length();

    for (int i = 0; i < n; ++i)
    {
        encryptedText = split_interlieve(encryptedText, len_text / 2, len_text % 2 != 0);
    }

    return encryptedText;
}