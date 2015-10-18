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
	cout << "please enter the start position:\n";
	cout << "x:";
	int px = 0;
	int py = 0;
	cin >> px;
	cout << "y:";
	cin >> py;
	cout << "please enter the destination:\n";
	int dx = 0;
	int dy = 0;
	cout << "x:";
	cin >> dx;
	cout << "y:";
	cin >> dy;
	m.setD(dx , dy);
	if (!m.dfs(px , py)){
		cout << "There's no answer for the maze!\n";
		return 0;
	}else{
		cout << "Here's the answer:\n";
		m.printOut();
	}
	return 0;
}