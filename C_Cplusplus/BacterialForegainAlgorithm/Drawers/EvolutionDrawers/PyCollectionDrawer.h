/*
 * PyCollectionDrawer.h
 *
 *  Created on: Oct 21, 2016
 *      Author: nandi
 */

#ifndef EVOLUTIONDRAWERS_PYCOLLECTIONDRAWER_H_
#define EVOLUTIONDRAWERS_PYCOLLECTIONDRAWER_H_

#include "../../Collector/EvolutionCollector.h"
#include "PyEvolutionDrawer.h"
#include "../PyRunner.h"

class PyCollectionDrawer{
private:
	EvolutionCollector *collector;
	PyRunner* runnerPy;
	PyObject* convert(unsigned int index);
public:
	PyCollectionDrawer(EvolutionCollector*,PyRunner*);
	virtual ~PyCollectionDrawer();
	void drawCollection();
};

#endif /* EVOLUTIONDRAWERS_PYCOLLECTIONDRAWER_H_ */
