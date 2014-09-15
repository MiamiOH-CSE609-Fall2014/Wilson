#include<iostream>
#include<vector>
using namespace std;

int main() {
  int rowsFirstMatrix;
  int colFirstMatrix;
  int rowsSecondMatrix;
  int colSecondMatrix;
  cin>>rowsFirstMatrix;
  cin>>colFirstMatrix;
  cin>>rowsSecondMatrix;
  cin>>colSecondMatrix;

  vector<int>firstMatrixValues;
 
  int entry;
  for (int n = 0; n < rowsFirstMatrix*colFirstMatrix; n++){
    cin>>entry;
    firstMatrixValues.push_back(entry);
  }

  vector<int>secondMatrixValues;

  for(int n = 0;n < rowsSecondMatrix*colSecondMatrix; n++){
    cin>>entry;
    secondMatrixValues.push_back(entry);
   
  }


}
