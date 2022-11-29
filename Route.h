// author @ Abigail Efua Tetteh 
// 29/11/2022
// C++ FINAL PROJECT .
//

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>



using namespace std;


class Route {


public:
    string airlineCode;
    string desAirportCode;
    int stops;



    /// </summary>
    /// <param name="airlineCode"></param>
    /// <param name="desAirportCode"></param>
    /// <param name="stops"></param>
    Route(string airlineCode, string desAirportCode, int stops);

    Route();

    //getters and setters
    string getAirlineCode();
    void setAirlineCode(string airlineCode);


    void setDesAirportCode(string desAirport);

    string getDesAirportCode();

    int getStops();

    void setStops(int stops);


};

