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
      return false;
    }
  }
  return true;
}

bool CheckLineHorizontaly(vector<vector<int> > board, int rowNumber) {
  vector<int> line = board[rowNumber];
  return CheckLine(line);
}

vector<vector<int> > TransposeMatrix(vector<vector<int> > board) {
  vector<vector<int> > result;
  for (int i = 0; i < board.size(); ++i) {
    vector<int> temp;
    for (int j = 0; j < board[i].size(); ++j) {
      temp.push_back(board[j][i]);
    }
    result.push_back(temp);
  }
  return result;
}

bool CheckLineVertically(vector<vector<int> > board, int columnNumber) {
  vector<vector<int> > transposedMatrix;
  transposedMatrix = TransposeMatrix(board);
  vector<int> line = board[columnNumber];
  return CheckLine(line);
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

// this is the way to Test my tests
void TestEachCell(vector<vector<int> > boardToSolve) {
  for (int i = 0; i < boardToSolve.size(); ++i) {
    for (int j = 0; j < boardToSolve.size(); ++j) {
      bool one = CheckLineHorizontaly(boardToSolve, i);
      bool two = CheckLineVertically(boardToSolve, j);
      cout << "The cell at row " << i << " an column " << j << "is " << boolalpha << one << noboolalpha << " horizontaly and is " << boolalpha << two << noboolalpha << " vertically." << endl;
    }
  }
}

int main() {
  vector<vector<int> > boardToSolve = getUserInput();
  string result = PrintSudokuBoard(boardToSolve);
  cout << "\n" << "The board you entered is " << "\n" << endl;
  cout << result << endl;
  cout << "\n" << endl;

  return 0;
}
