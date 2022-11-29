// author @ Abigail Efua Tetteh 
// 29/11/2022
// C++ FINAL PROJECT .
//

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
#include "Route.h"
using namespace std;


class Node {
public:
    shared_ptr<Node> parent;
    string airport_code;
    int stops;
    shared_ptr<vector<Route>> successors;
    string airLineCode;

    Node();
 
    /// <param name="parent"></param>
    /// <param name="airportCode"></param>
    /// <param name="stops"></param>
    /// <param name="successors"></param>
    /// <param name="airLineCode"></param>
    Node(shared_ptr<Node> parent, string airportCode, int stops, shared_ptr<vector<Route> > successors,
        string airLineCode) ;

    string getAirportCode();

    int getStops();

    string getAirlineCode();

    bool operator==(const Node& node);


    /* This the solution path function which is responsible for returning the route accessed through out the journey*/
    vector<string> solutionPath();

};
