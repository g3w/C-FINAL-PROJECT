#include<iostream>
#include "Node.h"
#include "Route.h"
#include <unordered_map>
#include<vector>
#include<deque>
#include<unordered_set>
#include <algorithm>
#include "File_Algorithm.h"

using namespace std;

void journeyDetails();
vector<string> bfs(string start_city_country, string endCityCountry);
vector<vector<string>> route_file_reader(string filename);
vector<vector<string>> airports_file_reader(string filename);

int main() {
	File_Algorithm File_Algorithm; //Instance of the main class file that contains all the functions to compute the route.
	File_Algorithm.journeyDetails();

}