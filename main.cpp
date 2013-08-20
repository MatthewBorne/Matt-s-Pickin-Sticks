/* 
 * File:   main.cpp
 * Author: educkface
 *
 * Created on August 20, 2013, 12:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ncurses.h>

using namespace std;


void printLevel(char lvl [][25], int score, int rows, int columns){
    
    cout << endl;
    for(int p = 0; p <= columns+1; p++){
        cout << "*";
    }
    cout << endl;
    
    for(int i = 0; i < rows; i++){
        cout << "*";
        for(int j = 0; j < columns; j++){
            cout << lvl[i][j];
        }
        cout << "*" << endl;
    
    }
    
    for(int p = 0; p <= columns+1; p++){
        cout << "*";
    }
    cout << endl;
    cout << "Score: " << score << endl;
        
}

int main(int argc, char** argv) {
    
    const int NUM_ROWS = 10;
    const int NUM_COLUMNS = 25;
    
    char level [NUM_ROWS][NUM_COLUMNS]; 
    
    for(int i = 0; i < NUM_ROWS; i++){
        for(int j = 0; j < NUM_COLUMNS; j++){
             level[i][j] = '.';
        }
    }
    
    level[0][0] = '@';
    level[0][9] = '-';
    
    char moveDirection;
    char c;
    int charLocation = 0;
    int stickLocation = 9;
    int score = 0;
    
    
    while(moveDirection != 'q'){
        
        printLevel(level,score,NUM_ROWS,NUM_COLUMNS);
    
        cout << "Use wasd to move your character" << endl;
        
        
        cin >> moveDirection;
        

        if((char)tolower(moveDirection) == 'w')
        {
            if(charLocation >= NUM_COLUMNS)
            {
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '.';
                charLocation = charLocation - NUM_COLUMNS;
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '@';
                
                if(charLocation == stickLocation){
                        score += 1;
                        stickLocation = rand() % (NUM_ROWS*NUM_COLUMNS);
                        level[(int)stickLocation/NUM_COLUMNS][stickLocation % NUM_COLUMNS] = '-';
                }
            }
        }
        else if((char)tolower(moveDirection) == 's')
        {
            if(charLocation < NUM_ROWS*NUM_COLUMNS-NUM_COLUMNS)
            {
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '.';
                charLocation = charLocation + NUM_COLUMNS;
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '@';
                
                if(charLocation == stickLocation){
                        score += 1;
                        stickLocation = rand() % (NUM_ROWS*NUM_COLUMNS);
                        level[(int)stickLocation/NUM_COLUMNS][stickLocation % NUM_COLUMNS] = '-';
                }
            }
        }
        else if((char)tolower(moveDirection) == 'd')
        {
            if(charLocation != NUM_ROWS*NUM_COLUMNS-1)
            {
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '.';
                charLocation = charLocation + 1;
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '@';
                
                if(charLocation == stickLocation){
                        score += 1;
                        stickLocation = rand() % (NUM_ROWS*NUM_COLUMNS);
                        level[(int)stickLocation/NUM_COLUMNS][stickLocation % NUM_COLUMNS] = '-';
                }
            }
        }
        else if((char)tolower(moveDirection) == 'a')
        {
            if(charLocation != 0)
            {
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '.';
                charLocation = charLocation - 1;
                level[(int)charLocation/NUM_COLUMNS][charLocation % NUM_COLUMNS] = '@';
                
                if(charLocation == stickLocation){
                        score += 1;
                        stickLocation = rand() % (NUM_ROWS*NUM_COLUMNS);
                        level[(int)stickLocation/NUM_COLUMNS][stickLocation % NUM_COLUMNS] = '-';
                }
            }
        }

    }
    
    
}
