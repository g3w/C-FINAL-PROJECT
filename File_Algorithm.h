#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Node.h"
#include <deque>
#include "Route.h"
using namespace std;

/*This file algorithm class is responsible reading all the files needed for the project
and computes the route using a breadth first search*/

class File_Algorithm
{
public:


    unordered_map<string, vector<string> > countryAirports;
    unordered_map<string, string> airport_in_a_particular_country;
    unordered_map<string, vector<shared_ptr<Route > > > routeHashMap;

    File_Algorithm();


    void journeyDetails();



    vector<string> bfs(string start_city_country, string endCityCountry);





    /*This function reads the routes file and returns a vector containing airlinecode,sourceairportcode, destinationairportcode and stops*/
    vector<vector<string>> route_file_reader(string filename);
     



    /*This function reads the airport file and returns a vector containing city, country and IATA*/

    vector<vector<string>> airports_file_reader(string filename);
       
   


};

