//============================================================================
// Name        : Testcontour.cpp
// Author      : Nandi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <plplot/plstream.h>
#include <plplot/plplot.h>
#include "TestContour.h"
using namespace std;




int main( int argc, const char **argv ) {

	TestContour *x=new TestContour(argc,argv );
	delete x;

	return 0;
}


