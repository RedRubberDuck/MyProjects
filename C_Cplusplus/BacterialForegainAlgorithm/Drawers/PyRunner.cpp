/*
 * PyRunner.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: nandi
 */

#include "../Drawers/PyRunner.h"

PyRunner::PyRunner(char **argv) {
	this->argv=argv;
	this->main=NULL;
	this->needShow=false;
}

PyRunner::~PyRunner() {
	// TODO Auto-generated destructor stub
}

PyObject* PyRunner::getMainPyObject(){
	return this->main;
}

void PyRunner::star(){
	Py_SetProgramName(this->argv[0]);
	Py_Initialize();
	this->main=PyImport_AddModule("__main__");

}

void PyRunner::end(){
	if(this->needShow)PyRun_SimpleString("matplotlib.pyplot.show();");
	PyErr_Print();
	Py_Finalize();
}
