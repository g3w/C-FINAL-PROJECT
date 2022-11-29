
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


class Airport {
public:
    int airportID;
    string name;
    string city;
    string country;
    string IATACode;
    string ICAOCode;
    double latitude;
    double longitude;
    double altitude;
    double timezone;
    string DST;
    string tz;
    string type;
    string datasource;



    Airport(int airportID, string name, string city, string country, string IATACode,
        string ICAOCode, double latitude, double longitude, double altitude,
        double timezone, string DST, string tz, string type, string datasource);

    Airport();


    int getAirportID();


    string getName();

    string getCity();

    string getCountry();

    string getIATACode();

    string getICAOCode();

    double getLatitude();

    double getLongitude();

    double getAltitude();

    double getTimezone();

    string getDST();

    string getTz();

    string getType();

    string getDatasource();
};