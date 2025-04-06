/*Для заданной строки s найдите длину самой длинной подстроки без повторяющихся символов.*/

#include <iostream>
#include <string>


using namespace std;

int lengthOfLongestSubstring(string s) {
    int count = 0, maxcount = 0;
    string substring = "";
    size_t pos;
    
    for (auto i = 0; i != s.size(); ++i)
    {
        pos = substring.find(s[i]);
        if (pos == string::npos)
        {
            count++;
            substring = substring + s[i];
        }
        else 
        {
            maxcount = max(maxcount, count);
            substring.erase(0, 1 + pos);
            substring += s[i];
            count -= pos;
        }
        
    }
    maxcount = max(maxcount, count);
    return maxcount;
}




int main()
{
    cout << lengthOfLongestSubstring("ohvhjdml");
}