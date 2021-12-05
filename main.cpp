#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	// Maze matrix
	//size
	int** maze = new int*[N];
	//getting the values
	for (int i = 0; i < N; ++i)
		maze[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			cin >> maze[i][j];

	int dir = 1;
	int i = 0;
	int j = 0;
	vector<int> path;
	path.push_back(dir);
	while (true)
	{
	   
		if (i == N - 1 && j == N - 1) {
			break;
		}
	    else if (maze[j][i+1] == 0 && i<N-1)  //right
		{
// 			cout<<"\nright"<<endl;
			i++;
			dir++ ;
// 			cout<<dir;
			path.push_back(dir);
			
			
		}
		else if (maze[j+1][i] == 0 && j<N - 1)  //bottom
		{
// 			cout<<"\nbottom"<<endl;
			j++;
			dir += N;
			path.push_back(dir);
			
			
		}
		else if (maze[j][i-1] == 0 && i>0)  //left
		{
// 			cout<<"\nleft"<<endl;
			i--;
			dir--;			
			int counter = count(path.begin(), path.end(), dir);
			if (counter > 0)
			{
				path.pop_back();
				maze[j][i+1]=1;
			}
			else {
				path.push_back(dir);
			}			
		}
		else if (maze[j-1][i] == 0 && j>0)  //up
		{
// 			cout<<"\nup"<<endl;
			j--;
			dir -=N;
// 			cout<<"\ndir"<<dir<<endl;
			int counter = count(path.begin(), path.end(), dir);
			if (counter > 0)
			{
				path.pop_back();
				maze[j+1][i]=1;
			}
			else {
				path.push_back(dir);
				
			}
		}
		else {
			cout << "-1";
			break;
		}
// 		 cout<<i<<" "<<j<<endl;
	}
	
	for (int k = 0; k < path.size(); k++)
		cout << path[k] << " ";
	
	
	
	return 0;
}

