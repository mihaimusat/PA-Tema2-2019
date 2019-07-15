/* Musat Mihai-Robert
 * Grupa 323CB
 */

#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 5;

int main()
{
	ifstream fin("p1.in");
	ofstream fout("p1.out");
		
	int n;
	vector<int> mat[NMAX];
	pair<int, int> edges[NMAX];

	fin >> n;
	
	//sortez crescator nodurile dupa distanta fata de nodul 1
	//pun rezultatul in matricea v[i][j] = distanta de la un nod de pe nivelul i la un nod de pe nivelul j
	int maxim = 0;
	for(int i = 1; i <= n; i++) {
		int x;		
		fin >> x;
		mat[x].push_back(i);
		if(x > maxim) {
			maxim = x;
		}
	}	
    
	bool flag = true;
	int numEdges = 0;
	int dist = mat[0].size(); //verific distanta de la nodul de pe nivelul 0 la celelalte noduri
	
	//aceasta distanta trebuie sa fie 1, din modul de constructie al grafului
	if(dist >= 2) {
		flag = false;
	}

	//pentru fiecare nod aflat la distanta cel putin 1 in vector
	//calculez distanta de la nodul de pe nivelul i la celelalte noduri
	for(int i = 1; i <= maxim; i++) {
		dist = mat[i].size();
		if(dist == 0) {
			flag = false;
			break;
		}
		dist--;
		//incerc sa leg toate nodurile aflate la distanta dist de un nod aflat la (dist - 1)
		int pos = mat[i - 1][0];
		for(int j = 0; j <= dist; j++) {
			edges[++numEdges].first = pos;
			edges[numEdges].second = mat[i][j];
		}
	}
    	
	//daca nu am reusit sa realizez conexiunea de mai sus
	//atunci nu pot sa construiesc graful
	if(flag == false) {
		fout << -1 << endl;
	}

	//altfel, pot sa construiesc graful
	//si afisez numarul de muchii si capetele muchiilor
	else {
		fout << numEdges << endl;
		for(int i = 1; i <= numEdges; i++) {
			fout << edges[i].first << " " << edges[i].second << endl;
		}
	}
   
	return 0;
}
