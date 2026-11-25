#include <iostream>
using namespace std;

int main() {
	int valores[] = {9, 2, 6, 1, 8};
	int n = 5;
	
	for (int i = 1; i < n; i++) {
		int clave = valores[i];             
            int j = i;
		
		while (j > 0 && valores[j - 1] > clave) {
			valores[j] = valores[j - 1];
			j--;
		}
		
		valores[j] = clave;
	}
	
	for (int i = 0; i < n; i++)
		cout << valores[i] << " ";
	
	return 0;
}