/*
 * PyEvolutionDrawer.h
 *
 *  Created on: Oct 21, 2016
 *      Author: nandi
 */

#ifndef PYEVOLUTIONDRAWER_H_
#define PYEVOLUTIONDRAWER_H_

#include <python2.7/Python.h>
#include <vector>
#include <iostream>
#include "../PyRunner.h"

class PyEvolutionDrawer {
private:
	PyRunner *runnerPy;
	std::vector<double> meanPopulation;
	PyObject* converter();
public:
	PyEvolutionDrawer(std::vector<double>,PyRunner*);
	virtual ~PyEvolutionDrawer();
	void drawEvolution();
};

#endif /* PYEVOLUTIONDRAWER_H_ */
