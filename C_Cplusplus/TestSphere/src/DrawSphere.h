/*
 * DrawSphere.h
 *
 *  Created on: Oct 17, 2016
 *      Author: nandi
 */

#ifndef DRAWSPHERE_H_
#define DRAWSPHERE_H_

#include<plplot/plplot.h>
#include<plplot/plstream.h>
#include<math.h>
#include<iostream>

#define M_PI 3.14

class DrawSphere {
public:
	DrawSphere(int argc, const char**argv);
	virtual ~DrawSphere();
	void drawSphere();
private:
	plstream *pls;
	static const int PERIMETERPTS=100;
	static const int RPTS=40;//sugar
	static const int THETAPTS=40;//szog
};

#endif /* DRAWSPHERE_H_ */
