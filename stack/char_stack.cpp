/* File: char_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/
#include "char_stack.h"// contains the declarations of the variables and functions.
#include<iostream>
using namespace std;
// Fill this in.
char_stack::char_stack(){
	top_index = -1;
}


void char_stack::push( char item ){
	top_index=top_index+1;
	A[top_index]=item;
}
char char_stack::pop(){
	top_index=top_index-1;
	return A[top_index+1];

}


char char_stack::top(){
	return A[top_index];
}
    
bool char_stack::empty(){
	return top_index == -1;
}
    
int char_stack::size(){
	return top_index+1;
}
