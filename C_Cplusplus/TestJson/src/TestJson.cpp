//============================================================================
// Name        : TestJson.cpp
// Author      : Nandi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
using namespace std;

int main() {
	Json::Value root;
	root.append(1);
	root.append(2);
	//root["ss"]="ss";
	//string ss;
	//ss=root.get("encoding","UTF-8").asString();
	cout << "Testeles11" <<root<< endl; // prints Testeles
	return 0;
}
