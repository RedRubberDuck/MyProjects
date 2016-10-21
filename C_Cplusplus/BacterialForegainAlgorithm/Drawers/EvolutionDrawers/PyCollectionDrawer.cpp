/*
 * PyCollectionDrawer.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: nandi
 */

#include "PyCollectionDrawer.h"

PyCollectionDrawer::PyCollectionDrawer(EvolutionCollector* collector,PyRunner* runner) {
	this->collector=collector;
	this->runnerPy=runner;

}

PyCollectionDrawer::~PyCollectionDrawer() {
	// TODO Auto-generated destructor stub
}

void PyCollectionDrawer::drawCollection(){
	std::cout<<"Start drawing collection! "<<this->collector->getNrEvolution()<<std::endl;

	PyRun_SimpleString("import matplotlib.pyplot;matplotlib.pyplot.figure()");
	PyRun_SimpleString("matplotlib.pyplot.hold(True)");
	for(unsigned int i=0;i<this->collector->getNrEvolution();i++){
		PyObject* meanOfPopPy=this->convert(i);
		FILE *f=fopen("PyCode/drawEvolution.py","r");
		PyObject *m,*globalDict;
		m=this->runnerPy->getMainPyObject();
		if(m==NULL) return;
		PyModule_AddObject(m,"meanPopulation",meanOfPopPy);
		globalDict=PyModule_GetDict(m);
		PyRun_File(f,"PyCode/drawEvolution.py",Py_file_input,globalDict,globalDict);
		fclose(f);
	}
	PyRun_SimpleString("matplotlib.pyplot.xlabel('Chemotaxis index');matplotlib.pyplot.ylabel('Mean value (log10)')");
	PyRun_SimpleString("matplotlib.pyplot.hold(False)");
	this->runnerPy->setNeedShow(true);


	std::cout<<"End drawing evoluation!"<<std::endl;
}


PyObject* PyCollectionDrawer::convert(unsigned int index){
	std::vector<double> meanPopulation=this->collector->getEvolution(index);
	std::cout<<"Evolution length:"<<meanPopulation.size()<<std::endl;
	PyObject* list=PyList_New(meanPopulation.size());
	for(unsigned int i=0;i<meanPopulation.size();i++){
		PyObject* temp=Py_BuildValue("f",meanPopulation[i]);
		PyList_SetItem(list,i,temp);
	}
	PyList_Fini();
	return list;
}
