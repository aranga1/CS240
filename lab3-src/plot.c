
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

char plot[MAXROWS][MAXCOLS];

void clearPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      plot[i][j] = ' ';
    }
  }
}

void printPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      printf("%c", plot[i][j]);
    }
    printf("\n");
  }
}

void plotXY(int x, int y, char c) {
  if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
  plot[y][x]=c;
}

void createPlot( char * funcFile, double minX, double maxX) {
  int nvals = MAXCOLS;
  double yy[MAXCOLS];
  double xx[MAXCOLS];
  int yAxis;
  int xAxis;
  double minY = rpn_eval(funcFile,minX);
  double maxY = rpn_eval(funcFile,maxX);
  clearPlot();
  
  double x1 =  minX;//(maxX-minX)/MAXCOLS;
 // double x = minX + (maxX-minX)/MAXCOLS;
  double xS = (maxX-minX)/MAXCOLS;
  
  for (int i = 0; i < nvals; i++) {
  	double x = minX + (maxX-minX)*i/MAXCOLS;
	double y = rpn_eval(funcFile,x);
	yy[i] = y;//rpn_eval(funcFile,x1);
	xx[i] = x;
	//x1 = x1 + xS;
  }
  for (int i = 0; i < nvals; i++) {
	if (yy[i] < minY) {
		minY = yy[i];
	}
	if (yy[i] > maxY) {
		maxY = yy[i];
	}
  }
  //determine y axis
  double y = minY;// + (maxY-minY)/MAXCOLS;
  double yS = (minY-maxY)/MAXROWS;
  if (minX >= 0) {
	yAxis = 0;
  }
  else {
	yAxis = (0-minX)/xS;
  }
  for (int i = 0; i < MAXROWS; i++) {
	plotXY(yAxis,i,'|');
  }

  //determine y axis
  if (minY >= 0) {
	xAxis = MAXROWS - 1;
  }
  else {
	xAxis = MAXROWS/2 - 1;
  }
  for (int i = 0; i < MAXCOLS; i++) {
	plotXY(i,xAxis,'_');
  }
  for (int i = 0; i < MAXCOLS; i++) {
  	plotXY(i,-(int)((yy[i]-minY)*MAXROWS/(maxY-minY))+39,'*');
//	plotXY(i,((yy[i]/yS)/(maxY-minY)),'*');
//	plotXY(i,(int) ( 40 - (minY)/yS +(yy[i]/yS)), '*');
 }
 // minY is plotted at row 0 and maxY is plotted at MAXROWS-1
  printPlot();

}

int main(int argc, char ** argv)
{
  printf("RPN Plotter.\n");
  
  if (argc < 4) {
    printf("Usage: plot func-file xmin xmax\n");
    exit(1);
  }

  // Get arguments
  createPlot(argv[1], atof(argv[2]), atof(argv[3]));
}
