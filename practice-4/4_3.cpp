//task 4_3
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int WIDTH = 80;
    int HEIGHT = 25;
    
    char graph[HEIGHT][WIDTH];
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            graph[i][j] = ' ';
        }
    }
    
    int center_y = HEIGHT / 2;
    for (int j = 0; j < WIDTH; j++) {
        if (j+1==WIDTH){
            graph[center_y][j] = '>';
        }
        else{
            graph[center_y][j] = '-';
        }
        
    }
    
    for (int i = 1; i < HEIGHT; i++) {
        if (i-1 == 0){
            graph[i-1][WIDTH/2] =  '^';
            
        }
        graph[i][WIDTH / 2] = '|';
        
    }
    
    for (int x = 0; x < WIDTH; x++) {
        double rad = (x * 2 * M_PI) / WIDTH * 2;
        double sin_val = sin(rad);
        
        int y = center_y - (int)(sin_val * (HEIGHT / 2 - 1));
        
        if (y >= 0 && y < HEIGHT) {
            graph[y][x] = '*';
        }
    }
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
