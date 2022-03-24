#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using std::stringstream;
using std::vector;
using std::string;
using std::getline;

class matrix {
    public:
        explicit matrix():rows(0), collumns(0) {}
        explicit matrix(string first_row);

    private:
        vector<int> mat;
        int rows;
        int collumns;
};


matrix::matrix(string first_row):rows(1), collumns(0) {
    string parsed;
    stringstream input_ss(first_row);

    while(getline(input_ss, parsed, ',')) {
        mat.push_back(stoi(parsed));
        collumns ++;
    }
}
