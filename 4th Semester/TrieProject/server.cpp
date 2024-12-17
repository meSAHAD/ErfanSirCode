#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

class node
{
public:
    char info;
    string Word;
    map<char, node *> ptrs;
    node() : info(0), Word("") {}
};

void insertword(string word, int pos, node *root)
{
    if (pos == word.length())
    {
        root->Word = word;
        return;
    }
    if (root->ptrs.find(word[pos]) == root->ptrs.end())
    {
        root->ptrs[word[pos]] = new node;
        root->ptrs[word[pos]]->info = word[pos];
    }
    insertword(word, pos + 1, root->ptrs[word[pos]]);
}

bool find(string key, int pos, node *root)
{
    if (key == root->Word)
        return true;
    if (root->ptrs.find(key[pos]) != root->ptrs.end())
        return find(key, pos + 1, root->ptrs[key[pos]]);
    return false;
}

void printall(node *root)
{
    for (auto p : root->ptrs)
        printall(p.second);
    if (!root->Word.empty())
        cout << " -> " << root->Word << "<br>";
}

void suggest(string key, int pos, node *root)
{
    if (key == root->Word || root->ptrs.find(key[pos]) == root->ptrs.end())
    {
        printall(root);
        return;
    }
    suggest(key, pos + 1, root->ptrs[key[pos]]);
}

int main()
{
    cout << "Content-Type: text/html\n\n";
    string word, key, current;
    ifstream in("wordlist.txt");

    node *root = new node;
    while (in >> word)
        insertword(word, 0, root);
    in.close();

    char *data = getenv("QUERY_STRING");
    string input(data ? data : "");

    // Parsing query
    size_t pos = input.find("word=");
    if (pos != string::npos)
    {
        key = input.substr(pos + 5);
        if (find(key, 0, root))
            cout << "The spelling of the word '" << key << "' is correct.";
        else
        {
            cout << "The spelling might be incorrect. Possible suggestions:<br>";
            suggest(key, 0, root);
        }
    }
    else
    {
        cout << "No word provided.";
    }
    return 0;
}
