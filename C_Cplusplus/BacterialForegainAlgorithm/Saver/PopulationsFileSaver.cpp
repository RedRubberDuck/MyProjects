/*
 * PopulationsFileSaver.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: nandi
 */

#include "PopulationsFileSaver.h"

PopulationsFileSaver::PopulationsFileSaver(std::vector<double**> populations,unsigned int nrDimension,unsigned int nrBac,std::string fileName,std::string destination,double *intervals,double (*function)(std::vector<double>)) {
	this->populations=populations;
	this->fileName=fileName;
	this->destination=destination;
	this->nrDimension=nrDimension;
	this->nrBac=nrBac;
	this->intervals=intervals;
	this->function=function;
}

PopulationsFileSaver::~PopulationsFileSaver() {
	// TODO Auto-generated destructor stub
}

void PopulationsFileSaver::intervalsSetting(){
		unsigned long points=0;
		for(int i=0;i<populations.size();i++){
			double **population=populations[i];
			for(int j=0;j<this->nrBac;j++){
				double *bacX=population[j];
				for(unsigned int k=0;k<this->nrDimension;k++){
					if(intervals[k*2]>bacX[k]){
						intervals[k*2]=bacX[k];
					}
					if(intervals[k*2+1]<bacX[k]){
						intervals[k*2+1]=bacX[k];
					}
				}
			}
		}
}

void PopulationsFileSaver::saveInTheFile(){
	Json::Value data;
	Json::Value collection;
	for(unsigned int i=0;i<this->populations.size();i++){
		double **population=this->populations[i];
		Json::Value popJson;
		for(unsigned int j=0;j<this->nrBac;j++){
			double *bac=population[j];
			Json::Value bacJson;
			for(unsigned int k=0;k<this->nrDimension;k++){
				bacJson.append(bac[k]);
			}
			popJson.append(bacJson);
		}
		collection.append(popJson);
	}
	data["collection"]=collection;
	std::string planeNet=generate2D();

	data["planeNet"]=planeNet;
	FILE *out=fopen((destination+fileName).c_str(),"w");
	fprintf(out,"%s",data.toStyledString().c_str());
	fclose(out);

}

std::string PopulationsFileSaver::generate2D(){
	intervalsSetting();
	unsigned int nrPoints=100;
	double deltaX=(intervals[1]-intervals[0])/(float)nrPoints;
	double deltaY=(intervals[3]-intervals[2])/(float)nrPoints;
	Json::Value xJson,yJson,zJson,data;
	for(unsigned int i=0;i<nrPoints;i++){
		Json::Value xRow,yRow,zRow;
		for(unsigned int j=0;j<nrPoints;j++){
			xRow.append(intervals[0]+deltaX*j);
			yRow.append(intervals[2]+deltaY*i);
			std::vector<double> vec;
			vec.push_back(intervals[0]+deltaX*j);vec.push_back(intervals[2]+deltaY*i);
			double temp=(*function)(vec);
			zRow.append(temp);
		}
		xJson.append(xRow);
		yJson.append(yRow);
		zJson.append(zRow);
	}
	data["xMatrix"]=xJson;
	data["yMatrix"]=yJson;
	data["zMatrix"]=zJson;
	return data.toStyledString();
}

