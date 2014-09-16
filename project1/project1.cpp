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


  for (int n = 0; n < firstMatrixValues.size(); n++){
    if (n%colFirstMatrix != 0){ 
      cout<< firstMatrixValues.at(n)<< " ";
    }
    else if (n%colFirstMatrix == 0) {
      cout<<"\n"<<firstMatrixValues.at(n)<< " ";
    }
    else {
      cout<<firstMatrixValues.at(n)<< " ";
    }
   
  }
  cout<<"\n";
  


  for (int n = 0; n <secondMatrixValues.size(); n++){
    if (n%colSecondMatrix != 0){ 
      cout<< secondMatrixValues.at(n)<< " ";
    }
    else if (n%colSecondMatrix == 0) {
      cout<<"\n"<<secondMatrixValues.at(n)<< " ";
    }
    else {
      cout<<secondMatrixValues.at(n)<< " ";
    }
   
  }
  cout<<"\n";

  if (colFirstMatrix != rowsSecondMatrix){
    cout<<"Invalid Input"<<endl;
    cout<<"1"<<endl;
  }


  int rowsFinalMatrix = rowsFirstMatrix;
  int colFinalMatrix = colSecondMatrix;
  int finalMatrixSize = rowsFinalMatrix*colFinalMatrix;

  for (int n = 0; n < finalMatrixSize; n++){
    if (n%colFinalMatrix != 0){
      double entry = 0;
      for (int m = 0; m <= colFirstMatrix; m++)
	entry += (firstMatrixValues.at(m)*secondMatrixValues.at(m));
      
      cout<< entry<< " ";
    }
    else if (n%colFinalMatrix == 0){
      double entry = 0;
      for (int m = 0; m <= colFirstMatrix; m++)
	entry += (firstMatrixValues.at(m)*secondMatrixValues.at(m));
      
      cout<<"\n"<<entry<<" ";
    }
    else {
      double entry = 0;
      for (int m = 0; m <= colFinalMatrix; m++)
	entry += (firstMatrixValues.at(m)*secondMatrixValues.at(m));
      
      cout<<entry<< " ";
    }
  }
  cout<< colFirstMatrix;



    }
