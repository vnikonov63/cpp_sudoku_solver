#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > getUserInput() {
  vector<vector<int> > result;
  string input;
  for (int i = 0; i < 9; i++) {
    vector<int> resultTemp;
    for (int j = 0; j < 9; j++) {
      cout << "Enter the digit for row " << i << " column " << j << " . Type x in the cell to intentionali leave the cell blank" << endl;
      cin >> input;
      if (input == "x") {
        resultTemp.push_back(-1);
      }
      else {
        int digit;
        digit = stoi(input);
        resultTemp.push_back(digit);
      }
    }
    result.push_back(resultTemp);
  }
  return result;
}

string PrintSudokuBoard(vector<vector<int> > board) {
  string result = "";
  for (int i = 0; i < board.size(); ++i) {
    result += '|';
    for (int j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == -1) {
        result += ' ';
        result += '|';
      }
      else {
        result += to_string(board[i][j]);
        result += '|';
      }
    }
    result += "\n";
  }
  return result;
}

int main() {
  // Get the user input and display it
  string result = PrintSudokuBoard(getUserInput());
  cout << "\n" << "The board you entered is " << "\n" << endl;
  cout << result << endl;
  cout << "\n" << endl;
  return 0;
}
