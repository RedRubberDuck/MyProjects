/*
 * EvoluationCollector.h
 *
 *  Created on: Oct 21, 2016
 *      Author: nandi
 */

#ifndef EVOLUTIONCOLLECTOR_H_
#define EVOLUTIONCOLLECTOR_H_

#include <vector>

class EvolutionCollector {
private:
	std::vector<std::vector<double> > *collection;
public:
	EvolutionCollector();
	virtual ~EvolutionCollector();
	void add(std::vector<double> );
	std::vector<double> getEvolution(unsigned int index);
	unsigned int getNrEvolution();
};

#endif /* EVOLUTIONCOLLECTOR_H_ */
