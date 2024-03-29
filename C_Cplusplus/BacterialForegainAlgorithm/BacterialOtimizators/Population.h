/*
 * Population.h
 *
 *  Created on: Oct 12, 2016
 *      Author: nandi
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <time.h>

#include "Bacteria.h"

class Population {
private:
	std::vector<Bacteria> bacteries;
	double *intervals;
	double initStep;
	unsigned int nrBac;
	unsigned int dimension;


public:

	Population(unsigned int nrBac,unsigned int dimension,double *intervals,double initStep);
	void InitailizeRandom();
	void printIntervals();
	void printBacteries();
	Bacteria getRandomBacteria();
	virtual ~Population();
};

#endif /* POPULATION_H_ */
