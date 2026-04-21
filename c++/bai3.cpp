#include<iostream>
using namespace std;
int X(int n);
int Y(int n);

int X(int n){
	if(n == o)
	     return 1;
	if(n > 1);
	     return X(n-1) + Y (n-1);
	else
	    cout << "n klhong hop le ";
}
   
int Y(int n){
	if(n == 0)
	     return 0;
	if(n > 0)
	     return 3*X(n-1) + 2*Y(n-1);
}

int main (){
	cout << "nhap x" ;
	int n;
	cout " x " << X << endl;
	cout " y " << Y << endl;
	
	
	return 0;
	
	
}
