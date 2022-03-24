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
    
    void add_row(string new_row);

    int get_rows(void) const {return rows;}

 private:
    vector<int> mat;
    int rows;
    int collumns;
};


matrix::matrix(string first_row):rows(1), collumns(0) {
    string parsed;
    stringstream input_ss(first_row);

    while (getline(input_ss, parsed, ',')) {
        mat.push_back(stoi(parsed));
        collumns ++;
    }
}


void matrix::add_row(string new_row) {
    string parsed;
    stringstream input_ss(new_row);
    int check_collumns = 0;

    while (getline(input_ss, parsed, ',')) {
        if (check_collumns >= collumns) {
            throw std::runtime_error("Additional rows must contain the same number of elements as the previous");
        }
        mat.push_back(stoi(parsed));
        check_collumns++;
    }

    rows++;
}
