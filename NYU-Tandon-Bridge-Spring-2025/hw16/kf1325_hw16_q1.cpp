#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

static bool isKeyword(const string& word) {
    return word == "begin" || word == "end";
}

static bool isPascalSymbolsBalanced(ifstream& infile)
{
    stack<string> symbolStack;
    string word;
    char ch;

    while (infile.get(ch))
    {
        if (isalpha(ch))
        {
            word = ch;
            while (infile.peek() != EOF && isalpha(infile.peek()))
            {
                infile.get(ch);
                word += ch;
            }
            if (word == "begin")
            {
                symbolStack.push("begin");
            }
            else if (word == "end")
            {
                if (symbolStack.empty() || symbolStack.top() != "begin")
                    return false;
                symbolStack.pop();
            }
            continue;
        }

        if (ch == '{' || ch == '(' || ch == '[')
            symbolStack.push(string(1, ch));
        else if (ch == '}' || ch == ')' || ch == ']')
        {
            if (symbolStack.empty()) return false;
            char open = symbolStack.top()[0];
            if ((ch == '}' && open != '{') ||
                (ch == ')' && open != '(') ||
                (ch == ']' && open != '['))
                return false;
            symbolStack.pop();
        }
    }
    return symbolStack.empty();
}

int main()
{
    // Example 1: Balanced
    ofstream out1("test1.pas");
    out1
        << "begin [{}][] end";
    out1.close();

    ifstream in1("test1.pas");
    cout
        << "Test 1 (should be True): "
        << (isPascalSymbolsBalanced(in1) ? "True" : "False")
        << endl;
    in1.close();

    // Example 2: Unbalanced
    ofstream out2("test2.pas");
    out2 
        << "begin [{}(]) end";
    out2.close();

    ifstream in2("test2.pas");
    cout 
        << "Test 2 (should be False): " 
        << (isPascalSymbolsBalanced(in2) ? "True" : "False") 
        << endl;
    in2.close();

    // Example 3: Nested begin/end
    ofstream out3("test3.pas");
    out3 
        << "begin begin {} end [] end";
    out3.close();

    ifstream in3("test3.pas");
    cout 
        << "Test 3 (should be True): " 
        << (isPascalSymbolsBalanced(in3) ? "True" : "False") 
        << endl;
    in3.close();

    // Example 4: Missing end
    ofstream out4("test4.pas");
    out4 
        << "begin [{}][]";
    out4.close();

    ifstream in4("test4.pas");
    cout 
        << "Test 4 (should be False): " 
        << (isPascalSymbolsBalanced(in4) ? "True" : "False") 
        << endl;
    in4.close();

    return 0;
}
