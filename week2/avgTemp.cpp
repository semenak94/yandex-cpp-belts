#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> GetDaysMoreThanAvgTemperature(int avgTemperature, const vector<int>& temperatureValues)
{
	vector<int> daysWithHigherTemperature;
	for (int i = 0; i < temperatureValues.size(); i++) {
		if (temperatureValues[i] > avgTemperature) {
			daysWithHigherTemperature.push_back(i);
		}
	}

	return daysWithHigherTemperature;
}


void AvgTemperatureTask()
{
	int avgTemperature;

	cin >> avgTemperature;

	vector<int> temperatureValues;
	int n;
	//getchar();
	while (getchar() != '\n') {
		cin >> n;
		temperatureValues.push_back(n);
	}

	vector<int> output = GetDaysMoreThanAvgTemperature(avgTemperature, temperatureValues);

	cout << output.size() << endl;
	for (auto v : output) {
		cout << v << " ";
	}
}
