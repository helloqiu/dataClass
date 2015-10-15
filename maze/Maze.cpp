#include "Maze.h"

Maze::Maze(int length , int width){
	this -> length = length;
	this -> width = width;
}

void Maze::readin(){
	for (int i = 0 ; i < length ; i ++){
		for (int j = 0 ; j < width ; j ++){
			cin >> maze[i][j];
			ifFind[i][j] = false;
		}
	}
}

bool Maze::dfs(int l , int w){
	if ((l > length - 1) || (l < 0)||(w < 0)||(w > width - 1)||ifFind[l][w]||(maze[l][w] == 1)){
		return false;
	}
	if((l == length - 1) && (w == width - 1)){
		s.push(w);
		s.push(l);
		return true;
	}
	ifFind[l][w] = true;
	if (dfs(l + 1 , w)){
		s.push(w);
		s.push(l);
		return true;
	}
	if (dfs(l , w + 1)){
		s.push(w);
		s.push(l);
		return true;
	}
	if (dfs(l, w - 1)){
		s.push(w);
		s.push(l);
		return true;
	}
	if (dfs(l - 1, w)){
		s.push(w);
		s.push(l);
		return true;
	}
	return false;
}
void Maze::printOut(){
	while(!s.empty()){
		cout << "(" << s.top() + 1;
		s.pop();
		cout << " , " << s.top() + 1 << ")\n";
		s.pop();
	}
}