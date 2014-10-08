#ifndef __APPCONFIG__
#define __APPCONFIG__

#include <map>
#include <fstream>
#include <string>

#include "include/utils.h"

using namespace std;

class AppConfig {
private:
	static map<string, string> configValues;
public:

	static void loadConfig(const char* configFile) {
		ifstream inStream(configFile);

		string line;

		while (getline(inStream, line).good()) {

			vector<string> configPair = Utils::split(line, '=');

			if (configPair.size() >= 2) {
				configValues.insert(pair<string, string>(
					configPair[0], configPair[1]));

				#ifdef DEBUG
					#include <iostream>
					cout << "AppConfig: " << configPair[0] << " = " << configPair[1] << endl;
				#endif
			}
		}
	}

	static string getConfig(string configKey) {
		if (configValues.find(configKey) != configValues.end())
			return configValues[configKey];
		else
			return "";
	}
};

map<string, string> AppConfig::configValues;

#endif