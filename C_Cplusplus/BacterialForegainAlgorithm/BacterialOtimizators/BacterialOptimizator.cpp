/*
 * BacterialOptimizator.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: nandi
 */

#include "BacterialOptimizator.h"

#include <stdio.h>

BacterialOptimizator::BacterialOptimizator(Population *population,double (*function)(std::vector<double>),unsigned int maxStep,unsigned int maxChem,unsigned int maxRep,unsigned int maxED,double eliminationFactor){
	this->population=population;
	this->function=function;
	this->maxChem=maxChem;
	this->maxStep=maxStep;
	this->maxRep=maxRep;
	this->maxED=maxED;
	this->eliminationFactor=eliminationFactor;
}

BacterialOptimizator::~BacterialOptimizator() {
	// TODO Auto-generated destructor stub
}


void BacterialOptimizator::initPopulationWithValue(){
	for(unsigned int i=0;i<this->population->getPopulationSize();i++){
		Bacteria *bacteria=this->population->getBacteria(i);
		double value=(*this->function)(bacteria->getX());
		bacteria->setValue(value);
	}
}

void BacterialOptimizator::chemotaxisPhase(){
	for(unsigned int j=0;j<this->maxChem;j++){
		for(unsigned int i=0;i<this->population->getPopulationSize();i++){
			Bacteria *bacteria=this->population->getBacteria(i);
			double lastValue=bacteria->getValue();
			std::vector<double> direction=bacteria->tumbling();
			unsigned int step=1;
			while(step<=this->maxStep){
				std::vector<double> X=bacteria->chemotaxis(direction, 1);

				double value=(*this->function)(X);
				step++;
				if(lastValue>value){
					bacteria->setValue(value);
					bacteria->setX(X);
					lastValue=value;
				}
				else{
					break;
				}
			}

		}
	}
}

void BacterialOptimizator::reproductionPhase(){
	for(unsigned int i=0;i<this->maxRep;i++){
		this->chemotaxisPhase();
		this->population->sortPopulation();
		this->population->reproduction();
	}
}

void BacterialOptimizator::eliminationDispersalPhase(){
	for(unsigned int i=0;i<this->maxED;i++){
		reproductionPhase();
		for(unsigned int j=0;j<this->population->getNrBac();j++){
				double randDouble=rand()%10000/10000.0;
				if(randDouble<this->eliminationFactor){
					Bacteria newBac=this->population->getRandomBacteria();
					double value=(*this->function)(newBac.getX());
					newBac.setValue(value);
					this->population->setBacteria(j, newBac);
				}
			}
	}
}

void BacterialOptimizator::optimizate(){
	eliminationDispersalPhase();
}

Population* BacterialOptimizator::getPopulation(){
	return this->population;
}
std::string BacterialOptimizator::getClassName(){
	std::string className="Bacterial Optimizator\n";
	return className;
}

void BacterialOptimizator::print(){
	printf("%s",getClassName().c_str());
}
