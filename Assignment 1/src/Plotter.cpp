#include "Plotter.h"
#include "GUI/SimpleTest.h"
#include <iostream>
#include "strlib.h"
#include "vector.h"
using namespace std;

struct Point{
    double x;
    double y;
};

void draw(Point &curPos,Point nextPos,bool penState,PenStyle style){
    if(penState){
        drawLine(curPos.x,curPos.y,nextPos.x,nextPos.y,style);
    }
    curPos = nextPos;
}

double convertNum(Vector<string> vec,int pos){
    /*get next position*/
    return stringToDouble(vec[pos]);
}

void runPlotterScript(istream& input) {
    /*Initialize state of pen*/
    PenStyle info = {1,"black"};
    Point curPos = {0,0};
    bool penIsDown = false;
    for(string line;getline(input,line);){
        Point nextPos;
        Vector<string> vec = stringSplit(line," ");
        vec[0] = toLowerCase(vec[0]); /* convert command to lower case*/
        if(vec[0] == "penup"){
            penIsDown = false;
        }else if(vec[0] == "pendown"){
            penIsDown = true;
        }else if(vec[0] == "moveabs"){
            nextPos.x = convertNum(vec,1);
            nextPos.y = convertNum(vec,2);
            draw(curPos,nextPos,penIsDown,info);
        }else if(vec[0] == "moverel"){
            nextPos.x = convertNum(vec,1) + curPos.x;
            nextPos.y = convertNum(vec,2) + curPos.y;
            draw(curPos,nextPos,penIsDown,info);
        }else if(vec[0] == "pencolor"){
            info.color = vec[1];
        }
        else if(vec[0] == "penwidth"){
            info.width = stringToDouble(vec[1]);
        }
    }
}





