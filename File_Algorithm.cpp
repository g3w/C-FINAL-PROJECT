// author @ Abigail Efua Tetteh 
// 29/11/2022
// C++ FINAL PROJECT .
//

#include "File_Algorithm.h"
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

File_Algorithm::File_Algorithm() {

    unordered_map<string, vector<string> > countryAirports;
    unordered_map<string, string> airport_in_a_country;
    unordered_map<string, vector<shared_ptr<Route > > > routeHashMap;

}

/*This functions gets all the various columns of the routes and airports file and creates a vector from them to help us 
compute the route*/

void File_Algorithm::journeyDetails() {
    
    vector<vector<string>> airports_storage = airports_file_reader("airports.csv"); //readif files into vectors

    vector<vector< string> > route_storage = route_file_reader("routes.csv");
 
    for (vector<string> each_line : route_storage) {
        shared_ptr<Route> route = make_shared<Route>(each_line[0], each_line[1], stoi(each_line[3]));

        if (routeHashMap.find(each_line[2]) != routeHashMap.end()) {
            vector< shared_ptr<Route> > new_route = routeHashMap.at(each_line[2]); //Populating search map
            new_route.push_back(route);
            routeHashMap[each_line[2]] = new_route;
        }
        else {
            vector<shared_ptr<Route> > unique_route_list;
            unique_route_list.push_back(route);
            routeHashMap[each_line[2]] = unique_route_list;
        }
    }




    for (vector<string> each_line : airports_storage) {
        string city_country = each_line[0] + "," + each_line[1];
        string airport_code = each_line[2];

        airport_in_a_country[airport_code] = city_country;
            

        if (countryAirports.find(city_country) != countryAirports.end()) {
            vector<string> newAirportList = countryAirports.at(city_country);
            newAirportList.push_back(airport_code);
            countryAirports[city_country] = newAirportList;
        }
        else {
            vector<string> uniqueAirportList;
            uniqueAirportList.push_back(airport_code);
            countryAirports[city_country] = uniqueAirportList;
        }
    }


    string startLocation;
    string endLocation;

    

    string line;
    ifstream input_file("sampleInput.txt");

    getline(input_file, startLocation);
    getline(input_file, endLocation);

   


    ofstream Output_file("OutputFile.txt");
    vector<string> path = bfs(startLocation, endLocation);
    int paths = 0;
    if (!path.empty()) {
        for (string flight :
        path) {
            Output_file << flight << endl;
            paths++;
        }
        Output_file << "Total flight: " << paths;
    }
    else {
        Output_file << "No solution Found";
    }
    Output_file.close();
}



/*This is the search algorithm implemented using*/


vector<string> File_Algorithm::bfs(string start_city_country, string endCityCountry) {

    cout << "Finding path..." << endl;

    deque<shared_ptr<Node> > frontier;
    unordered_set<string> explored;


    vector<string> airport_codes = countryAirports[start_city_country];


    if (!airport_codes.empty()) {
        for (string airport_code : airport_codes) {

            shared_ptr<Node> airportNode = make_shared<Node>(nullptr, airport_code,
                0, nullptr, "");
            frontier.push_back(airportNode);

        }
    }
    while (!frontier.empty()) {
        shared_ptr<Node> removedNode = frontier.front();

        frontier.pop_front();
        if (removedNode == nullptr) {

            continue;
        }

        explored.insert(removedNode->getAirportCode());


        vector<shared_ptr<Route> > successors = routeHashMap[removedNode->getAirportCode()];
        if (!successors.empty()) {
            for (shared_ptr<Route> successor :
                successors) {
                shared_ptr<Node> childNode = make_shared<Node>(removedNode, successor->getDesAirportCode(),
                    successor->getStops(), nullptr, successor->getAirlineCode());
                string destination = airport_in_a_country[childNode->getAirportCode()];
                if (destination == endCityCountry) {
                    cout << "Found a path!!" << endl;
                    return childNode->solutionPath();

                }
                if (std::find(frontier.begin(), frontier.end(), childNode) == frontier.end()
                    && explored.find(childNode->getAirportCode()) == explored.end()) {

                    frontier.push_back(childNode);
                }
            }
        }
    }
    cout << "No solution yahhh" << endl;
    return vector<string>();
}










/*This function reads the routes file and returns a vector containing airlinecode,sourceairportcode, destinationairportcode and stops*/
vector<vector<string>> File_Algorithm::route_file_reader(string filename) {
    ifstream routeCSV;

    routeCSV.open(filename);

    string routesline;
    string airlinecode, airlineid, sourceairportcode,
        sourceairportid, destinationairportcode, destinationairportid,
        codeshare, stops, equipment;


    vector<vector<string>> routes_storage;
    

    while (getline(routeCSV, routesline)) {

        vector<string> each_line;

        stringstream stream(routesline);

        getline(stream, airlinecode, ',');
        getline(stream, airlineid, ',');
        getline(stream, sourceairportcode, ',');
        getline(stream, sourceairportid, ',');
        getline(stream, destinationairportcode, ',');
        getline(stream, destinationairportid, ',');
        getline(stream, codeshare, ',');
        getline(stream, stops, ',');
        getline(stream, equipment, ',');

        each_line.push_back(airlinecode);
        // each_line.push_back(airlineid);
        each_line.push_back(sourceairportcode);
        //each_line.push_back(sourceairportid);
        each_line.push_back(destinationairportcode);
        // each_line.push_back(destinationairportid);
            //each_line.push_back(codeshare);
        each_line.push_back(stops);
        //each_line.push_back(equipment);

        routes_storage.push_back(each_line); // converts eachline into vector of some columns and push it another vector and return a vector of vector.

    }
    return routes_storage;

}







/*This function reads the airport file and returns a vector containing city, country and IATA*/

vector<vector<string>> File_Algorithm::airports_file_reader(string filename) {
    ifstream airportCSV;

    airportCSV.open(filename);

    string line, airportID, name, city, country, IATACode,
        ICAOCode, latitude, longitude, altitude,
        timezone, DST, tz, type, datasource;

    vector<vector<string>> airports_storage;

    while (getline(airportCSV, line)) {
        vector<string> each_line;

        stringstream stream(line);
        getline(stream, airportID, ',');
        getline(stream, name, ',');
        getline(stream, city, ',');
        getline(stream, country, ',');
        getline(stream, IATACode, ',');
        getline(stream, ICAOCode, ',');
        getline(stream, latitude, ',');
        getline(stream, longitude, ',');
        getline(stream, altitude, ',');
        getline(stream, timezone, ',');
        getline(stream, DST, ',');
        getline(stream, tz, ',');
        getline(stream, type, ',');
        getline(stream, datasource, ',');

        // each_line.push_back(airportID);
            //each_line.push_back(name);
        each_line.push_back(city);
        each_line.push_back(country);
        each_line.push_back(IATACode);
        //each_line.push_back(ICAOCode);
        //each_line.push_back(latitude);
        //each_line.push_back(longitude);
        //each_line.push_back(altitude);
        //each_line.push_back(timezone);
        //each_line.push_back(DST);
        //each_line.push_back(tz);
        //each_line.push_back(type);
        //each_line.push_back(datasource);

        airports_storage.push_back(each_line); // converts eachline into vector of some columns and push it another vector and return a vector of vector.
    }
    return airports_storage;
}








