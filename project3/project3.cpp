#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <vector>
#include <tuple>
using namespace std;

// Declare global variables
string header;
vector<string> comments;
string sequence;
int num_seq;
vector<string> combinations = {"AA","AG","AC","AT","GA","GG","GC","GT","CA","CG","CC","CT","TA","TG","TC","TT"};
vector<string> letters = {"A","G","C","T"};

// Declare global methods
tuple<string,vector<string>,string> parseFastaFile(string filepath);
map<string, int> digramFreqScores(string s);
vector<vector<int>> digramFreqMatrix(map<string,int> d);
vector<vector<int>> parseScoringFile(string filepath);
pair<int,int> scoreSequence(string haystack,string needle, vector<vector<int>> scoring_m);
tuple<int,int,string> findHighScore(string haystack, vector<string> needles, vector<vector<int>> scoring_m);


// Main
int main(int argc, char* argv[]) {
 
parseFastaFile(argv[1]);
map<string,int> d = digramFreqScores(sequence);
vector<vector<int>> m = digramFreqMatrix(d);
vector<vector<int>> scoring_m = parseScoringFile(argv[2]);

// Printing and formatting
cout<<'\n';
cout<<'\t'<<"Diagram Frequency Matrix"<<endl;
cout<<'\t'<<"   A  "<<"G  "<<"C  "<<"T  "<<endl;

 for(int i = 0; i < 4; i++) {
   for (int j = 0; j < 4; j++) {   
     if (j==0 & i == 0) {
       cout<<"       "<<letters[i]<<"  "<<m[i][j]<<' ';
     }
     else if (j == 0) {
       cout<<'\n'<<"       "<<letters[i]<<"  "<<m[i][j]<<' ';
     }
     else { 
       cout<<m[i][j]<<' ';
     }
   }
 }
 
cout<<'\n'<<'\n'<<'\n';
cout<<'\t'<<"Scoring Matrix"<<endl;
cout<<'\t'<<"  A"<<" G"<<" C"<<" T"<<endl;


for(int i = 0; i < 4; i++) {
   for (int j = 0; j < 4; j++) {   
     if (j==0 & i == 0) {
       cout<<"       "<<letters[i]<<"  "<<scoring_m[i][j]<<' ';
     }
     else if (j == 0) {
       cout<<'\n'<<"       "<<letters[i]<<"  "<<scoring_m[i][j]<<' ';
     }
     else { 
       cout<<scoring_m[i][j]<<' ';
     }
   }
 }

 cout <<'\n'<<'\n'<< "How many sequences would you like to score?" << endl;
 cin >> num_seq;

 vector<string> seqs;
 string temp;
 for (int i = 0; i < num_seq; i++) {
   cout<<"Enter Sequence #"<<i+1<<" on a single line:"<<endl;
   cin>> temp;
   seqs.push_back(temp);
 }
 

 for (int i = 0; i < num_seq; i++) {
   pair<int,int> theScores = scoreSequence(sequence,seqs.at(i),scoring_m);
   cout<<'\n'<<"Sequence:"<<endl;
   cout<<seqs.at(i)<<endl;
   cout<<"Score: "<<theScores.second<<" at position "<<theScores.first<<endl;
 }

tuple<int,int,string> highScore = findHighScore(sequence,seqs,scoring_m);
 cout<<'\n'<<"Best score:" <<endl;
 cout<<"Sequence: "<< get<2>(highScore) << " Score: " << get<1>(highScore) << " at position: "<< get<0>(highScore)<<'\n'<<endl;

}


// Method called parseFastaFile
// This method takes a filepath as an argument and returns a 3 parameter tuple containing the header, comments, and sequence associated with the file provided

tuple<string,vector<string>,string>parseFastaFile(string filepath) {
string temp ;
  ifstream myfile(filepath);

  while(myfile.good()) {
    getline(myfile,temp);
    if (temp.length() > 0) {
      if (temp.at(0)=='>') {
	header = temp;
      }
      else if (temp.at(0)==';') {
	comments.push_back(temp);
      }
      else {
	sequence = sequence + temp;
      }
     }
  } 
 
  return  make_tuple(header,comments,sequence);
}


// Method called digramFreqScores
// This method takes a string and returns a map of scores that the number of occurances of each digram in the string
map<string, int> digramFreqScores(string s) {
  map<string,int> scores;
  int count = 0;
  int ix = 0;
  string temp = s;

  for (int i = 0; i < combinations.size(); i++) {
    while(true) {
      ix = temp.find(combinations[i]);
      if (ix != string::npos) {
	temp.replace(ix,1,"/");
	count = count + 1;
            }
    else {
	break; 
	 }
    }
    scores[combinations[i]]=count;
    count = 0;
    ix = 0;
    temp = s;
  }
  return scores;
}


// Method called digramFreqMatrix
// This method takes the map created by digramFreqScores and converts it to a matrix
vector<vector<int>> digramFreqMatrix (map<string,int> d) {
  int count; 
  vector<vector<int>> m;
  vector<int> chunk1;
  vector<int> chunk2;
  vector<int> chunk3;
  vector<int> chunk4;
 
  for (int i = 0; i < 4; i++) {
    chunk1.push_back(d[combinations[i]]);
  }
  m.push_back(chunk1);
  for (int i = 4; i < 8; i++) {
    chunk2.push_back(d[combinations[i]]);
  }
  m.push_back(chunk2);
  for (int i = 8; i < 12; i++) {
	chunk3.push_back(d[combinations[i]]);
  }
  m.push_back(chunk3);
     
  for (int i = 12; i < 16; i++) {
    chunk4.push_back(d[combinations[i]]);
  }
  m.push_back(chunk4);

	 return m;
       }

// Method called parseScoringFile
// This method takes in a filepath as its only argument and parse that file to create a scoring matrix
vector <vector<int>> parseScoringFile(string filepath) {
   string temp;
ifstream myfile(filepath);
 
vector<vector<int>> scoringMatrix(4,vector<int>(4));
//vector<vector<int>> scoringMatrix;
  for (int i = 0; i < 4; i++) {
    getline(myfile,temp);
    for (int j = 0; j < 4; j++) {
      scoringMatrix[i][j] = atoi(temp.substr(0,1).c_str());
      if (j > 3 || j < 3) {
	temp = temp.substr(temp.find(",")+1);
      }
    }
  }
  return scoringMatrix;
}


// Method called scoreSequence
// This method takes a needle, a haytack, and a scoring matrix and compares the needle against every position on the haystack and gives it a score. It returns the maximum score that it is able to find
pair<int,int> scoreSequence(string haystack,string needle, vector<vector<int>> scoring_m) {
  int highScorer = 0;
  int highScorerIx = 0;
  int currentScore;
  string substring;
  map<char,int> scores = {{'A',0},{'G',1},{'C',2},{'T',3}};

    for (int i = 0; i < haystack.length()-needle.length()+1; i++) {
      currentScore = 0;
      substring = haystack.substr(i,needle.length());
      for (int j = 0; j < needle.length(); j++) {
	currentScore = currentScore + scoring_m[scores[substring[j]]][scores[needle[j]]];
      }   
	if(currentScore > highScorer) {
	highScorer = currentScore;
	highScorerIx = i;
    }
  }
    return make_pair(highScorerIx,highScorer);
}

// Method called findHighScore
// This method takes a haystack, a vector of neeldes, and a scoring matrix. It then returns a tuple that contains the position, score, and needle with the highest score of the bunch
tuple<int,int,string> findHighScore(string haystack, vector<string> needles, vector<vector<int>> scoring_m) {
  
  pair<int, int> score;
  int maxIndex = 0;
  int maxScore = 0;
  string winningNeedle = "";

  for (int i = 0; i < needles.size(); i++) {
    score = scoreSequence(haystack,needles[i], scoring_m);
    if (score.second> maxScore) {
      maxIndex = get<0>(score);
      maxScore = get<1>(score);
      winningNeedle = needles[i];
    }
  }
  return make_tuple(maxIndex,maxScore,winningNeedle);
}
