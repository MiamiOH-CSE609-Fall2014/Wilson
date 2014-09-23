#include<iostream>
#include<vector>
using namespace std;

int main() {

  // Initialize variables 
  int rowsFirstMatrix;
  int colFirstMatrix;
  int rowsSecondMatrix;
  int colSecondMatrix;

  // Read in matrix dimensions
  cin>>rowsFirstMatrix;
  cin>>colFirstMatrix;
  cin>>rowsSecondMatrix;
  cin>>colSecondMatrix;

  vector<int>firstMatrixValues;
 
  // Read in first matrix values
  int entry;
  for (int n = 0; n < rowsFirstMatrix*colFirstMatrix; n++){
    cin>>entry;
    firstMatrixValues.push_back(entry);
  }

  vector<int>secondMatrixValues;

  // Read in second matrix values
  for(int n = 0;n < rowsSecondMatrix*colSecondMatrix; n++){
    cin>>entry;
    secondMatrixValues.push_back(entry);
   
  }

  // Print out first matrix formatted properly
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
  

  // Print out second matrix formatted properly
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
  
  // Check to see if number of columns in first matrix are equal to number of rows in second matrix
 
  // If they are not equal:
  if (colFirstMatrix != rowsSecondMatrix){
    cout<<"Invalid Input"<<endl;
    cout<<"1"<<endl;
  }
  

  // If they are equal, do calculation:
  else {
 
    int rowsFinalMatrix = rowsFirstMatrix;
    int colFinalMatrix = colSecondMatrix;
    vector<int>finalMatrix;

  for (int i = 0; i < rowsFinalMatrix; i++){
    for (int j = 0; j < colFinalMatrix; j++){
      int sum = 0;
      for (int k = 0; k < rowsSecondMatrix; k++) 
	sum = sum + firstMatrixValues.at(i*colFirstMatrix+k)*secondMatrixValues.at(k*colFinalMatrix+j);
      if (j%colFinalMatrix == 0){ 
	cout<<'\n'<<sum<<' ';
      }
      else {
	cout<<sum<<' '; 
      }
    }
  }
  cout<<'\n';
  }
  
}
