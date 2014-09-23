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
  
  else {
 
  vector<int>finalMatrix;

  for (int i = 0; i < rowsFirstMatrix; i++){
    for (int j = 0; j < colSecondMatrix; j++){
      int sum = 0;
      for (int k = 0; k < rowsSecondMatrix; k++) 
	sum = sum + firstMatrixValues.at(i*colFirstMatrix+k)*secondMatrixValues.at(k*colSecondMatrix+j);
      if (j%colSecondMatrix == 0){ 
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
