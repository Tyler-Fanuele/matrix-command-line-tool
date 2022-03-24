#include <unistd.h>

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "matrix.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum math_type {
    add,
    sub,
    mul,
    div,
};

int main(int argc, char** argv) {
    try {
        int opt;
        size_t first_row_size = 0;
        size_t first_col_size = 0;
        size_t second_row_size = 0;
        size_t second_col_size = 0;

        // cmd line only for now
        string cmd_arg;
        vector<string> cmd_strings;
        size_t pos;

        math_type operation;

        while ((opt = getopt(argc, argv, "c:t:")) != -1) {
            switch (opt) {
                case '?':  // unknown option

                    break;

                case 'c':  // commandline input
                    if (argc < 3) {
                        throw std::runtime_error("not enough arguments given");
                    }

                    // formatt r,c,o,r,c,

                    cmd_arg = optarg;
                    pos = 0;
                    while ((pos = cmd_arg.find(',')) != string::npos) {
                        cmd_strings.push_back(cmd_arg.substr(0, pos));
                        cmd_arg.erase(0, pos + 1);
                        cout << cmd_arg << endl;
                    }
                    if (cmd_strings.size() < 3) {
                        throw std::runtime_error("not enough args");
                    }

                    if (cmd_strings.size() == 5) {
                        if (cmd_strings[2] == "+") {
                            operation = add;
                        } else if (cmd_strings[2] == "-") {
                            operation = sub;
                        } else if (cmd_strings[2] == "*") {
                            operation = mul;
                        }
                        first_row_size = stoi(cmd_strings.at(0));
                        first_col_size = stoi(cmd_strings.at(1));
                        second_row_size = stoi(cmd_strings.at(4));
                        second_col_size = stoi(cmd_strings.at(5));
                    }

                    for (size_t i = 0; i < first_col_size; i++) {
                        
                    }

                    break;

                case 't':  // text file input
                    cout << "Text file support not yet implmented" << endl;
                    break;
            }
        }
    } catch (std::runtime_error err) {
        cout << err.what() << endl;
    }

    return 0;
}