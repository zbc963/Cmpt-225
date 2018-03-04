#include "char_stack.h"
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;


char reverse_pop(char item);
string multi_space(int i);

int main(int argc, char * const argv[]){

char_stack S;

char check_pop;
int length;
int test;
int line_number=0;

bool error = false;
string line;

while(getline(cin,line)){


	line_number++;
	length = line.length();
	int i =0;
	string output=" ";
	while ( i<length ){

		output = output+line[i];
		if (line[i] == '(' || line[i] == '{' || line[i] == '[' ){
			S.push(line[i]);
		}

		else if ( line[i] == ')' || line[i] == '}' || line[i] == ']' ){
		 	if ( S.empty() ){
		 	cout<<"Error on line :"<<line_number<<", col "<<i<<"there is too many "<<line[i]<<endl;
		 	cout<<output<<endl;
		 	i++;
		 	cout<<multi_space(i);
		 	while(i<length){
		 		if(line[i]=='\t'){
		 			cout<<'\t';
		 		}
		 		else if(line[i]=='\n'){
		 			cout<<'\n';
		 		}
		 		else{
		 			cout<<line[i];
		 			
		 		}
		 		i++;
		 	}
		 	cout<<endl;
		 	error = true;
		 	return 0;
		 	}
		 	check_pop = S.pop();
		 	if ( line[i] == ')' && check_pop !='(' ){
		 	cout<< "Error on line: "<<line_number<<", col: "<<i<<endl<<"report error read "<< line[i] <<" ,expected "<<reverse_pop(check_pop)<<" and halt." <<endl;
		 	cout<<output<<endl;
		 	i++;
		 	cout<<multi_space(i);
		 	while(i<length){
		 		if(line[i]=='\t'){
		 			cout<<'\t';
		 		}
		 		else if(line[i]=='\n'){
		 			cout<<'\n';
		 		}
		 		else{
		 			cout<<line[i];
		 		}
		 		i++;
		 	}
		 	cout<<endl;
		 	error = true;
            return 0;             // here, r is the closing symbol matching l
		 	}
		 	else if ( line[i] == '}' && check_pop !='{' ){
		 	cout<< "Error on line: "<<line_number<<", col "<<i<<endl<<"report error read "<< line[i]<< " ,expected "<<reverse_pop(check_pop)<<" and halt."<<endl ;
		 	cout<<output<<endl;
		 	i++;
		 	cout<<multi_space(i);
		 	while(i<length){
		 		if(line[i]=='\t'){
		 			cout<<'\t';
		 		}
		 		else if(line[i]=='\n'){
		 			cout<<'\n';
		 		}
		 		else{
		 			cout<<line[i];
		 		}
		 		i++;
		 	}
		 	cout<<endl;
		 	error = true;
            return 0;            // here, r is the closing symbol matching l
		 	}
		 	else if ( line[i] == ']' && check_pop !='[' ){
		 	cout<< "Error on line: "<<line_number<<", col "<<i<<endl<<"report error read "<< line[i] <<" ,expected "<<reverse_pop(check_pop)<<" and halt."<<endl ;
		 	cout<<output<<endl;
		 	i++;
		 	cout<<multi_space(i);
		 	while(i<length){
		 		if(line[i]=='\t'){
		 			cout<<'\t';
		 		}
		 		else if(line[i]=='\n'){
		 			cout<<'\n';
		 		}
		 		else{
		 			cout<<line[i];
		 		}
		 		i++;
		 	}
		 	cout<<endl;
		 	error = true;
		 	return 0;
                         // here, r is the closing symbol matching l
		 	}
		 	
		 }
	
		i++;
	}

}
line_number--;

if ( !S.empty()){
      check_pop = S.pop();
    cout<<"Error at the end of the file:";
	cout<< " report error too many "<<check_pop << " and halt."<<endl;
	error = true;
	return 0;
	}
if(error != true){
	cout << "No errors found. "<<endl;
	// cout<<line;
	return 0;
}




return 0;
}





char reverse_pop(char item){
	char result;
	if (item == '('){
		result = ')';
	}
	else if (item == '['){
		result = ']';
	}
	else if (item == '{'){
		result = '}';
	}

	return result;
}


string multi_space(int i){
	string result;
	int j=0;
	while(j<=i){
		result=result+" ";
		j++;
	}
	return result;
}