//
//  main.cpp
//  CPP_2018project
//
//  Created by MJMacBook on 05/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

enum CommandType { ADD, SORT, PRINT, CLEAR, EXIT} ;

struct Rectangle {
    int width;
    int height;
    int area;
};
bool cmp(Rectangle& a, Rectangle& b)
{ return a.width<b.width; }

CommandType getCommandType();
Rectangle getRectangle();
void print(const vector<Rectangle>& inp);
void sort(vector<Rectangle>& inp);

int main() {
    vector<Rectangle> rectangles ;
    while (true) {
        CommandType command = getCommandType() ;
        switch ( command ) {
            case ADD : {
                const Rectangle& newRectangle = getRectangle() ;
                rectangles.push_back(newRectangle) ;
                break ;
            }
            case PRINT: {
                print(rectangles) ;
                break ;
            }
            case SORT: {
                sort(rectangles) ;
                print(rectangles) ;
                break ;
            }
            case CLEAR : {
                rectangles.clear() ;
                break ;
            }
            case EXIT : {
                break ;
            }
            default: {
                assert (false) ;
                break ;
            }
        }
        if ( command == EXIT ) break ;
    }
    
    return 0;
}

CommandType getCommandType()
{
    string cmd;
    cin >> cmd;
    CommandType recmd = EXIT;
    if ( !cmd.compare("ADD") )
        recmd = ADD;
    else if( !cmd.compare("SORT")  )
        recmd = SORT;
    else if( !cmd.compare("PRINT")  )
        recmd = PRINT;
    else if( !cmd.compare("CLEAR")  )
        recmd = CLEAR;
    else
        recmd = EXIT;
    return recmd;
}

Rectangle getRectangle()
{
    Rectangle tmp;
    cin >> tmp.width >> tmp.height;
    tmp.area = tmp.width * tmp.height;
    return tmp;
}

void print(const vector<Rectangle>& inp){
    cout << "Rectangle Count: " << inp.size() <<endl;
    
    for (vector<Rectangle>::size_type i = 0; i < inp.size(); ++i) {
        cout << "\t" << inp[i].width << " " << inp[i].height << " "  << inp[i].area<< endl;
    }
}

void sort(vector<Rectangle>& inp)
{
    sort(inp.begin(),inp.end(), cmp);
}
