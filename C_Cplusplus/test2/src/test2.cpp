//============================================================================
// Name        : test2.cpp
// Author      : Nandi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <plplot/plstream.h>
#include <plplot/plplot.h>

using namespace std;

int main() {
	PLFLT xmin =0, ymin=0, xmax=10, ymax=30;
	PLINT just=0, axis=0;
	 plstream *pls;
	 pls = new plstream();
	 //pls->init();
	 pls->scolbg(255,255,255);
	 pls->sdev("xwin");
	 pls->init();
	 PLFLT x1=1.0,y1=1.0,x2=5.0,y2=5.0;
	 pls->scol0(0,0,0,0);
	 pls->col0(0);
	 pls->env(xmin, xmax, ymin, ymax, just, axis );


	 pls->col0(3);
	 pls->join(x1,y1,x2,y2);



	delete pls;
	return 0;
}
