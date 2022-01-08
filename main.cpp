#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string toLowerCase(string a, int l);
string toReverseString(string b, int l);
bool checkPalindrome(string a, string b, int l);
void writeToFile(string a, bool flag);

int main()
{
    string fileName = "test.txt";
    string iniStr;
    string lowStr;
    string revStr;
    //read string in word text
    ifstream scanner("test.txt");
    while (getline(scanner, iniStr))
    {
        int l = iniStr.length();
        //to lower case
        lowStr = toLowerCase(iniStr, l);

        //reverse a string
        revStr = toReverseString(lowStr, l);

        // check palindrome or not
        bool flag = checkPalindrome(revStr, lowStr, l);

        //write to file
        writeToFile(iniStr, flag);
    }
}

string toLowerCase(string a, int l)
{
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = tolower(a[i]);
    }
    return a;
}

string toReverseString(string a, int l)
{
    string rev = "";
    for (int i = l - 1; i >= 0; i--)
    {
        rev = rev + a[i];
    }
    return rev;
}

bool checkPalindrome(string a, string b, int l)
{
    bool flag;
    a == b ? flag = true : flag = false;
    return flag;
}

void writeToFile(string a, bool flag)
{
    string fileName = "negative.txt";
    if (flag == true)
    {
        fileName = "positive.txt";
    }
    ofstream file(fileName, file.app);
    file << a << endl;
}