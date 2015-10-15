#include "Maze.h"

int main(void){
	int length = 0;
	int width = 0;
	cout << "Please enter the length and the width of the maze:\n";
	cout << "length: ";
	cin >> length;
	cout << "\nwidth :";
	cin >> width;
	
	Maze m(length , width);
	
	cout << "Please enter the maze:\n";
	m.readin();
	if (!m.dfs(0, 0)){
		cout << "There's no answer for the maze!\n";
		return 0;
	}else{
		cout << "Here's the answer:\n";
		m.printOut();
	}
	return 0;
}