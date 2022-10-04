#include <bits/stdc++.h>
using namespace std;
//AKASH DINKAR PATIL 
//Q--> print all the unique combination of target int .combination may in any order
//eg.  arr=[2,3,6,7], target=7
//o/p--> [[2,2,3],[7]]
//explanation--> 2+2+3=7 (here 2 is taken twice) and 7=7;

//technique --> just dont increment the index of take element because it may be repeted

void combinationSumI(int index,vector<int>&ds,int target,vector<int>&arr)
{
	if(index>=arr.size())
	{
		if(target==0)
		{
			for(auto it:ds){
				cout<<it<<" ";
			}
			cout<<"\n";

			//to get result [[2,2,3],[7]] just add 1 more parameter vector and  "res.push_back(ds)" where res is final vector 
		}
		return;
	}
	


	//take
	if(target-arr[index]>=0)
	{
		ds.push_back(arr[index]);
		
		combinationSumI(index,ds,target-arr[index],arr);
		ds.pop_back(); //push_back and pop_back are associated with "take" only because we take element 
						//after call we have to relese or remove that element for "non-take" 

	}
	

	//not take
	
	combinationSumI(index+1,ds,target,arr);
}

int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/

	int n,target;
	cin>>n>>target;
	vector<int>arr(n),ds;
	
	for(int i=0;i<n;++i) cin>>arr[i];
	combinationSumI(0,ds,target,arr);

	
	/* code */
	return 0;
}

