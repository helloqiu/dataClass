#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <stack>
using namespace std;

class Maze{
public:
	Maze(int length , int width);
	void readin();
	bool dfs(int l , int w);
	void printOut();

private:
	int length;
	int width;
	int maze[1000][1000];
	bool ifFind[1000][1000];
	stack<int> s;
};
#endif