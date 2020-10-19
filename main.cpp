#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

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

// A list of Tests, that ensures, that the values we provide are correct
vector<vector<int> > TransposeMatrix(vector<vector<int> > initialBoard) {
  vector<vector<int> > result;
  return result;
}

bool CheckLine(vector<int> line) {
  map <int, int> tempO;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] != -1) {
      try {
        tempO.at(line[i]);
      }
      catch (std::out_of_range) {
        tempO[line[i]] = 1;
        continue;
      }

      cout << "There is a repetition" << " at " << i << " for " << line[i] << endl;
      return false;
    }
  }
  cout << "There is no repetitions" << endl;
  return true;
}

bool CheckLineHorizontaly(vector<vector<int> > board, int rowNumber) {
  return true;
}

bool CheckLineVertically(vector<vector<int> > board, int columnNumber) {
  return true;
}

bool CheckThreeByThreeLine(vector<vector<int> > board, int rowNumber, int columnNumber) {
  return true;
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
  /* vector<vector<int> > boardToSolve = getUserInput();
  string result = PrintSudokuBoard(boardToSolve);
  cout << "\n" << "The board you entered is " << "\n" << endl;
  cout << result << endl;
  cout << "\n" << endl; */
  vector<int> debug;
  srand(time(NULL));
  debug.push_back(-1);
  debug.push_back(-1);
  debug.push_back(1);
  debug.push_back(9);
  debug.push_back(3);
  debug.push_back(-1);
  debug.push_back(1);
  cout << "the vector" << endl;
  for (int i : debug) {
    cout << i << endl;
  }
  CheckLine(debug);
  return 0;
}
