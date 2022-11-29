#include "Route.h"


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




    /// </summary>
    /// <param name="airlineCode"></param>
    /// <param name="desAirportCode"></param>
    /// <param name="stops"></param>
Route::Route(string airlineCode, string desAirportCode, int stops) {
        this->airlineCode = airlineCode;
        this->desAirportCode = desAirportCode;
        this->stops = stops;
    }

Route::Route() {
        airlineCode = "";
        desAirportCode = "";
        stops = 0;
    }


    //getters and setters
    string Route:: getAirlineCode() {
        return airlineCode;
    }

    void Route:: setAirlineCode(string airlineCode) {
        airlineCode = airlineCode;
    }


    void Route:: setDesAirportCode(string desAirport) {
        desAirport = desAirportCode;
    }

    string Route::getDesAirportCode() {
        return desAirportCode;
    }

    int Route:: getStops() {
        return stops;
    }

    void Route::setStops(int stops) {
        stops = stops;
    }





