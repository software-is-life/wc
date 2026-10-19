#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
* `-c` command to count the number of bytes in a given text.
*
* output example:
* 1234 test.txt
*/
int count_bytes(string text) {
    return text.size() * sizeof(char); 
}

/*
* `-l` command to count number of lines in a given text.
*/
int count_lines(string text) {
    int lines = 0;
    for (int i {0}; i < text.size(); i++) {
        if (text[i] == '\n') {
            ++lines;
        }
    }
    return lines;
}

/*
* `-w` command to count number of lines in a given text.
*/
int count_words(string text) {
    int n = text.size();
    int i = 0;
    int j = 0;
    int wc = 0;
    while (i < n && j < n) {
        if (i < n && iswspace(text[i])) {
            ++i;
            j = i;
            continue;
        }
        while (j < n && !iswspace(text[j]))
            j++;

        ++wc;
        i = j;
    }
    return wc;
}

/*
* `-m` command to count number of lines in a given text.
*/
int count_characters(string text) {
    int count = 0;
    for (int i {0}; i < text.size(); ++i) {
        char ch = text[i];
        if (ch != '\n')
            ++count;
    }
    return count;
}

string copy_file(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return "";
    }

    string file_contents;
    string line;
    while (getline(file, line))
        file_contents += line + '\n';

    file.close();
    return file_contents;
}


int main(int argc, char* argv[]) {
    auto lang = "C++";
    const string extension = ".txt";
    vector<string> legal_commands = {"-c", "-l", "-w", "-m"};


    vector<string> filenames;
    vector<string> commands;

    for (int count{0}; count < argc; ++count) {
        string curr_arg = argv[count];

        // identify .txt extensions to read
        size_t suffix_pos = curr_arg.rfind(extension);
        if (suffix_pos != string::npos) {
            filenames.push_back(curr_arg);
            continue;
        }

        // if a legal command like `-c`, `-w`, etc does not exist in commands add to vector to 
        // be used for function calling in next block of code.
        if (
            find(legal_commands.begin(), legal_commands.end(), curr_arg) != legal_commands.end() &&
            find(commands.begin(), commands.end(), curr_arg) == commands.end()
        ) {
            commands.push_back(curr_arg);
        }
    }

    for (string &filename : filenames) {

        string text_content = copy_file(filename);

        if (commands.empty()) {
            cout << count_bytes(text_content) << " " << count_lines(text_content) << " " << count_words(text_content) << " " << filename << endl;
            continue;
        }

        for (string &cmd : commands) {
            if (cmd == "-c") {
                cout << count_bytes(text_content) << " ";
            } else if (cmd == "-w") {
                cout << count_words(text_content) << " ";
            } else if (cmd == "-l") {
                cout << count_lines(text_content) << " ";
            } else if (cmd == "-m") {
                cout << count_characters(text_content) << " ";
            }
        }
        cout << filename << endl;
    }
    return 0;
}