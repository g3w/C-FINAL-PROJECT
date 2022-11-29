#include "Node.h"

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


Node::Node() {

    shared_ptr<Node> parent;
    string airport_code;
    int stops;
    shared_ptr<vector<Route>> successors;
    string airLineCode;

}


/// <param name="parent"></param>
/// <param name="airportCode"></param>
/// <param name="stops"></param>
/// <param name="successors"></param>
/// <param name="airLineCode"></param>
Node::Node(shared_ptr<Node> parent, string airportCode, int stops, shared_ptr<vector<Route> > successors,
    string airLineCode) {
    this->parent = parent;
    this->airport_code = airportCode;
    this->stops = stops;
    this->successors = successors;
    this->airLineCode = airLineCode;
}



string   Node:: getAirportCode() {
    return airport_code;
}

int   Node::getStops() {
    return stops;
}

string   Node::getAirlineCode() {
    return airLineCode;
}

bool   Node:: operator==(const Node& node) {
    return node.airport_code == this->airport_code && node.airLineCode == this->airLineCode &&
        node.successors == this->successors;
}


/* This the solution path function which is responsible for returning the route accessed through out the journey*/
vector<string>   Node:: solutionPath() {
    vector<string> airport_codes;
    vector<string> solution;
    vector<string> airline_codes;
    vector<int> stops;
    Node* this_node = this;

    while (this_node != nullptr) {
        airline_codes.push_back(this_node->getAirlineCode());
        airport_codes.push_back(this_node->getAirportCode());
        stops.push_back(this_node->getStops());
        this_node = this_node->parent.get();

    }
    /*This aspect of the solution path function reverses the contents of the vector in order to get the right order of the flights*/
    reverse(airline_codes.begin(), airline_codes.end());
    reverse(airport_codes.begin(), airport_codes.end());

    for (int i = 0; i < airline_codes.size() - 1; i++) {
        string result = airline_codes.at(i + 1) + " from " + airport_codes.at(i) + " to " +
            airport_codes.at(i + 1) + " " + to_string(stops.at(i)) + " stops.";
        solution.push_back(result);
    }
    return solution;

}



