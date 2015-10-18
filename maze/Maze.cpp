#include "Maze.h"

Maze::Maze(int length , int width){
	this -> length = length;
	this -> width = width;
}
void Maze::setD(int dx , int dy){
	this -> dx = dx;
	this -> dy = dy;
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
	if((l == dx - 1) && (w == dy - 1)){
		s.push(w);
		s.push(l);
		return true;
	}
	ifFind[l][w] = true;
	int order[4] = {0 , 1 , 2 , 3};
	for (int i = 0 ; i < 4 ; i ++){
		for (int j = i + 1 ;j < 4 ; j ++){
			if (manhattan_Distance(l, w, order[i]) > manhattan_Distance(l, w, order[j])){
				int tmp = order[i];
				order[i] = order[j];
				order[j] = tmp;
			}
		}
	}
	for (int i = 0 ; i < 4 ; i ++){
		switch(order[i]){
			case 0:
				if (dfs(l + 1 , w)){
					s.push(w);
					s.push(l);
					return true;
				}
			case 1:
				if (dfs(l , w + 1)){
					s.push(w);
					s.push(l);
					return true;
				}	
			case 2:
				if (dfs(l, w - 1)){
					s.push(w);
					s.push(l);
					return true;
				}
			case 3:
				if (dfs(l - 1, w)){
					s.push(w);
					s.push(l);
					return true;
				}
		}
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
int Maze::manhattan_Distance(int x , int y , int direction){
	if (direction == 0){
		return (x + 1 - dx)^2 + (y - dy)^2;
	}
	if (direction == 1){
		return (x - dx)^2 + (y + 1 - dy)^2;
	}
	if (direction == 2){
		return (x - dx)^2 + (y - 1 - dy)^2;
	}
	return (x - 1 - dx)^2 + (y - dy)^2;
}