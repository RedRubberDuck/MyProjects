/*
 * EvoluationCollector.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: nandi
 */

#include "../Collector/EvolutionCollector.h"

EvolutionCollector::EvolutionCollector() {
	this->collection=new std::vector<std::vector<double> >();
}

EvolutionCollector::~EvolutionCollector() {
	// TODO Auto-generated destructor stub
}

void EvolutionCollector::add(std::vector<double> evolution){
	this->collection->push_back(evolution);
}


std::vector<double> EvolutionCollector::getEvolution(unsigned int index){
	return (*this->collection)[index];
}

unsigned int EvolutionCollector::getNrEvolution(){
	return this->collection->size();
}
