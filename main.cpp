#include <iostream>
#include <fstream>
#include <cassert>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;

bool check(string word)
{
    size_t length = word.length(), i;

    for (i = 1; i < length; i++)
    {
        if (word[i] == 'i')
        {
            if (word[i - 1] == 'e' && (i < 2 || word[i - 2] != 'c'))
            {
                return false;
            }

            if (i + 1 < length && word[i + 1] == 'e' && word[i - 1] == 'c')
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string word;
    ifstream input_f("input.txt");
    int count;

    assert(check("a") == true);
    assert(check("zombie") == true);
    assert(check("transceiver") == true);
    assert(check("veil") == false);
    assert(check("icier") == false);

    if (input_f.is_open())
    {
        while (getline(input_f, word))
        {
            if (!check(word))
            {
                cout << word << endl;
                count++;
            }
        }
    }

    cout << count;
    sleep_for(seconds(5));
    return 0;
};