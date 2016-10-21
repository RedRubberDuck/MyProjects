/*
 * DrawerRunner.h
 *
 *  Created on: Oct 19, 2016
 *      Author: nandi
 */

#ifndef DRAWERRUNNER_H_
#define DRAWERRUNNER_H_
#include <string>
#include <python2.7/Python.h>
#include <fstream>
#include <iostream>

class DrawerRunner {
	std::string destination,fileName;
	int argc;
	char** argv;
	std::string pyFile="test.py";
public:
	DrawerRunner(std::string,std::string,int,char**);
	virtual ~DrawerRunner();
	void drawing();
};

#endif /* DRAWERRUNNER_H_ */
