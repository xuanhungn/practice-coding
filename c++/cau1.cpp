/*n = 1 -> 1/2
S(n) += S (n-1)+1/n(n+1)*/ 


#include<iostream>
using namespace std;
float S(int n){
	if( n == 1)
	   return 1.0/2;
	return S(n -1 )+ 1.0/(n*(n+1));
}


int main(){
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Tong la: "<< S(n);
	
}
