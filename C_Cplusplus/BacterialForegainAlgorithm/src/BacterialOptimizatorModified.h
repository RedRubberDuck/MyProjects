/*
 * BacterialOtimizatorModified.h
 *
 *  Created on: Oct 15, 2016
 *      Author: nandi
 */

#ifndef BACTERIALOPTIMIZATORMODIFIED_H_
#define BACTERIALOPTIMIZATORMODIFIED_H_

#include<vector>
#include "../BacterialOtimizators/Population.h"
#include "../BacterialOtimizators/BacterialOptimizator.h"

#include <stdio.h>
#include <string>
#include <math.h>
class BacterialOptimizatorModified: public BacterialOptimizator{
private:
	std::vector<double**> *populations;
	std::vector<double> *meanPopulation;
public:
	BacterialOptimizatorModified(Population *population,double (*function)(std::vector<double>),unsigned int maxStep,unsigned int maxChem,unsigned int maxRep,unsigned int maxED,double eliminationFactor);
	virtual ~BacterialOptimizatorModified();
	void memorizePopulation();
	void chemotaxisPhase();
	std::string getClassName();
	std::vector<double**> getPopulations();
	void printpopulations();
	void freeMemory();
	std::vector<double> getMeanPopulation();
};

#endif /* BACTERIALOPTIMIZATORMODIFIED_H_ */
