#include <iostream>
#include <string>

using namespace std;

/*
* `-c` command to count the number of bytes in a given text.
*
* output example:
* 1234 test.txt
*/
int count_bytes(string text) {
    return 0;
}

/*
* `-l` command to count number of lines in a given text.
*/
int count_lines(string text) {
    return 0;
}

/*
* `-w` command to count number of lines in a given text.
*/
int count_words(string text) {
    return 0;
}

/*
* `-m` command to count number of lines in a given text.
*/
int count_characters(string text) {
    return 0;
}


int main(int argc, char* argv[]) {
    auto lang = "C++";
    const string extension = ".txt";
    vector<string> legal_commands = {"-c", "-l", "-w", "-m"};
    cout << "There are " << argc << " arguments\n";


    vector<string> source_text;
    vector<string> commands;

    for (int count{0}; count < argc; ++count) {
        string curr_arg = argv[count];

        // identify .txt extensions to read
        size_t suffix_pos = curr_arg.rfind(extension);
        if (suffix_pos != string::npos) {
            source_text.push_back(curr_arg);
            continue;
        }

        // if a legal command like `-c`, `-w`, etc does not exist in commands add to vector to 
        // be used for function calling in next block of code.
        if (
            find(legal_commands.begin(), legal_commands.end(), curr_arg) != legal_commands.end() &&
            find(commands.begin(), commands.end(), curr_arg) != commands.end()
        ) {
            commands.push_back(curr_arg);
        }
    }
    return 0;
}