/* Musat Mihai-Robert
 * Grupa 323CB
 */

#include <bits/stdc++.h>

#define ll long long
#define inf (1LL) * 1000000000 * 1000000000

using namespace std;

const int NMAX = 205;
const int TMAX = 105;

vector <pair<int, pair<int, int>>> adj[NMAX];
priority_queue <pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater <pair<ll, pair<int, int>>>> pq;
int penal[TMAX][TMAX];
ll dist[NMAX][NMAX];

int main()
{
	ifstream fin("p3.in");
	ofstream fout("p3.out");
	
	//citire date de intrare
	int n, m, t;
	fin >> n >> m >> t;

	for(int i = 1; i <= m; i++) {
		int x, y, c, t;		
		fin >> x >> y >> c >> t;
		adj[x].push_back({y, {c, t}});
        	adj[y].push_back({x, {c, t}});
	}
	
    	for(int i = 1; i <= t; i++) {
        	for(int j = 1; j <= t; j++) {
            		fin >> penal[i][j];
		}
	}

	//prima muchie folosita are cost suplimentar nul
    	for(int i = 1; i <= t; i++) {
        	penal[0][i] = 0;
	}

	//dist[i][j] = distanta minima de a ajunge la nodul i,
	//iar ultima muchie este de tip j
    	for(int i = 1; i <= n; i++) {
        	for(int j = 1; j <= t; j++) {
            		dist[i][j] = inf;
		}
	}

	//distanta pana la nodul 1 daca ultima muchie este de tip 0 este 0
	//in pq, distana initiala e 0, nodul curent e 1 si tipul ultimei muchii este 0
	//initial, costul minim este inf
    	dist[1][0] = 0LL;
    	pq.push({0LL, {1, 0}});
    	ll minim = inf;
	
    	while(!pq.empty()) {
        	ll distcrt = (0LL) + pq.top().first; //extrag distanta curenta
        	int nod = pq.top().second.first; //extrag nodul curent
        	int tip = pq.top().second.second; //extrag tipul ultimei muchii
        	if(nod == n) {
            		minim = (0LL) + distcrt; //daca am ajuns la ultimul nod, atunci distanta curenta = costul minim 
            		break;
        	}

        	pq.pop();
        	int sz = adj[nod].size();

		//parcurg toti vecinii nodului curent extras
        	for(int i = 0; i <= sz - 1; i++) {
			//calculez distanta de a ajunge de la nodul curent la vecin cu penalizare
			int vecin = adj[nod][i].first;
            		ll distnew = (0LL) + distcrt + adj[nod][i].second.first + penal[tip][adj[nod][i].second.second];
			//daca distanta e mai mica, updatez distanta curenta, nodul curent si tipul ultimei muchii in pq
			if(distnew < dist[vecin][adj[nod][i].second.second]) {
                		dist[vecin][adj[nod][i].second.second] = (0LL) + distnew;
                		pq.push({distnew, {vecin, adj[nod][i].second.second}});
            		}
        	}
    	}
    	
	//verific daca am gasit sau nu drumul de cost minim
	if(minim == inf) {
       		fout << -1 << endl;
	}
    	else {
        	fout << minim << endl;
	}

	return 0;
}
