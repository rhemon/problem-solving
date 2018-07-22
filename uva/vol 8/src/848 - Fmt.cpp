#include <iostream>

using namespace std;

#define WIDTH 72

string buffer;

bool empty_line(string & line)
{
    return line.length() == 0;
}

bool new_line(string & line)
{
    if (empty_line(line))
        return false;
    return line[0] == ' ';
}

void trim_line(string & line)
{
    for (string::iterator it = line.end() - 1; it >= line.begin(); it--)
        if (*it == ' ')
            line.erase(it);
        else
            break;
}

void process_buffer()
{
    if (buffer.length() > 0)
    {
        if (buffer.length() <= WIDTH)
        {
            cout << buffer << endl;
            buffer.clear();
            return;
        }

        string line, word;
        string::iterator it = buffer.begin();
        string spaces;

        for (; it != buffer.end() && *it == ' '; spaces.append(1, ' '), it++)
            ;

        line.append(spaces);
        spaces.clear();

        for (; it != buffer.end() && *it != ' '; line.append(1, *it), it++)
            ;

        if (line.length() >= WIDTH)
        {
            cout << line << endl;
            line.clear();
        }

        while (line.length() <= WIDTH && it != buffer.end())
        {
            if (word.length() == 0)
            {
                for (; it != buffer.end() && *it == ' '; spaces.append(1, ' '), it++)
                    ;
                for (; it != buffer.end() && *it != ' '; word.append(1, *it), it++)
                    ;
            }

            if (word.length() >= WIDTH)
            {
                cout << line << endl << word << endl;
                line.clear();
                word.clear();
                spaces.clear();
            }
            else
            {
                if (line.length() == 0)
                    spaces.clear();

                if ((line.length() + spaces.length() + word.length()) <= WIDTH)
                {
                    line.append(spaces).append(word);
                    word.clear();
                    spaces.clear();
                }
                else
                {
                    cout << line << endl;
                    line.clear();
                    spaces.clear();
                }
            }
        }

        if (line.length() > 0)
            cout << line << endl;
        if (word.length() > 0)
            cout << word << endl;

        buffer.clear();
    }
}

int main(int ac, char *av[])
{
    string line;

    while (getline(cin, line))
    {
        trim_line(line);

        if (empty_line(line) || new_line(line))
        {
            process_buffer();

            if (empty_line(line))
                cout << endl;
            else
                buffer.append(line);
        }
        else
        {
            if (buffer.length() == 0)
                buffer.append(line);
            else
                buffer.append(1, ' ').append(line);
        }
    }

    process_buffer();

    return 0;
}
