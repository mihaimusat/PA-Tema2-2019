/* Musat Mihai-Robert
 * Grupa 323CB
 */

#include <bits/stdc++.h>

using namespace std;

const int NMAX = 105;
const int DIM = 1e4 + 5;

int n, m, k, nr, val, vertical[DIM], orizontal[DIM], mat[NMAX][NMAX];
bool viz[NMAX][NMAX];

//functie care verifica daca pot sa aplic algoritmul fill
//pentru fiecare patratica in parte
bool check(int x, int y) {
	
	if(x == 0)
        	return false;
    	if(x == (n + 1))
        	return false;
    	if(y == 0)
        	return false;
    	if(y == (m + 1))
        	return false;
    	if(viz[x][y] == true)
        	return false;
    	if((mat[x][y] < val) || (mat[x][y] > (val + k)))
        	return false;
    	return true;
}

//aplic fill considerand fiecare patratica ca un nod 
//si explorez cei 4 vecini ai sai
void fill(int x, int y) {
	
	nr++;
    	viz[x][y] = true;
   	vertical[nr] = x;
    	orizontal[nr] = y;

    	if(check(x + 1, y) == true)
        	fill(x + 1, y);
    	if(check(x - 1, y) == true)
        	fill(x - 1, y);
    	if(check(x, y + 1) == true)
        	fill(x, y + 1);
    	if(check(x, y - 1) == true)
        	fill(x, y - 1);
    	return;
}

int main() 
{
	ifstream fin("p2.in");
	ofstream fout("p2.out");
	
	//citire date de intrare
	fin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {		
			fin >> mat[i][j];
		}
	}

	//initializare matrice viz cu urmatoarea semnificatie:
	//v[i][j] = true daca am vizitat celula (i, j) din matricea mat
	for(int i = 1; i <= n; i++) {
        	for(int j = 1; j <= m; j++) {
            		viz[i][j] = false;	
		}
	}

	//calculez aria maxima ceruta
    	int maxim = 0;
    	for(int i = 1; i <= n; i++) {
        	for(int j = 1; j <= m; j++) {            		
			nr = 0; //numarul de celule conectate este initial 0
            		val = mat[i][j]; //retin valoarea celulei curente
            		fill(i, j); //aplic fill pentru aceasta celula
			//updatez numarul maxim de celule conectate            		
			if(nr > maxim) {
                		maxim = nr;
			}
			//pentru fiecare celula deja conectata la pasul curent
			//resetez matricea viz pentru a nu porni din nou un fill
            		for(int p = 1; p <= nr; p++) {
                		int x = vertical[p];
				int y = orizontal[p];	
				viz[x][y] = false;
			}
       		}		 
	}
    	
	fout << maxim << endl;
    	
	return 0;
}
