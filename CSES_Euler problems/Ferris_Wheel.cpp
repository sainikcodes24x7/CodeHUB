#include <bits/stdc++.h>

using namespace std;

const int maxn=2e5+10;

// Variables used for the current problem
int n,x,p[maxn],i,j,ans;
// Keeps track of the number of children who have had their own gondola
bool have_gondola_yet[maxn];

void solve() {
	cin >> n >> x;
	for (int i=0;i<n;++i) cin >> p[i];
	sort(p,p+n);
	i=0;j=n-1;
	while (i<j){
		if (p[i]+p[j]>x){
			// If the total weight of two children exceeds x
			// Then we move to the lighter child.
			--j;
		}
		else{ // If it satisfies the condition.
			++ans; // Increment the number of gondolas used
			// Mark that they have had their gondola
			have_gondola_yet[i]=have_gondola_yet[j]=true;
			++i; --j; //Move to the next children.
		}
	}
	for (int i=0;i<n;++i){
		// Calculate the number of children not having gondolas yet
		// to get the total number of gondolas needed for the problem.
		ans+= have_gondola_yet[i] == false;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}