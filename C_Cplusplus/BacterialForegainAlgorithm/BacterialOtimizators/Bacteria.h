/*
 * Bacteria.h
 *
 *  Created on: Oct 12, 2016
 *      Author: nandi
 */

#ifndef BACTERIA_H_
#define BACTERIA_H_
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

class Bacteria {
private:
	std::vector<double> x;
	double value;
	double step;
public:

	Bacteria(std::vector<double> x,double step);
	virtual ~Bacteria();
	double getStep() const;
	void setStep(double step);
	double getValue() const;
	void setValue(double value);
	std::vector<double> getX();
	void setX(std::vector<double> x);
	std::vector<double> tumbling();
	std::vector<double> chemotaxis(std::vector<double> direction,int nrStep);
	void printBacteria();
};

#endif /* BACTERIA_H_ */
