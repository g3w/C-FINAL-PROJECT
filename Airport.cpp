#include "Airport.h"


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


Airport::Airport() {

    airportID;
    name;
    city;
    country;
    IATACode;
    ICAOCode;
    latitude;
    longitude;
    altitude;
    timezone;
    DST;
    tz;
    type;
    datasource;
}


Airport::Airport(int airportID, string name, string city, string country, string IATACode,
    string ICAOCode, double latitude, double longitude, double altitude,
    double timezone, string DST, string tz, string type, string datasource) {

    this->airportID = airportID;
    this->name = name;
    this->city = city;
    this->country = country;
    this->IATACode = IATACode;
    this->ICAOCode = ICAOCode;
    this->latitude = latitude;
    this->longitude = longitude;
    this->altitude = altitude;
    this->timezone = timezone;
    this->DST = DST;
    this->tz = tz;
    this->type = type;
    this->datasource = datasource;
}





int Airport::getAirportID() {
    return airportID;
}


string Airport::getName() {
    return name;
}

string Airport:: getCity() {
    return city;
}

string Airport:: getCountry() {
    return country;
}

string Airport:: getIATACode() {
    return IATACode;
}

string Airport:: getICAOCode() {
    return ICAOCode;
}

double Airport::getLatitude() {
    return latitude;
}

double Airport:: getLongitude() {
    return longitude;
}

double Airport::getAltitude() {
    return altitude;
}

double Airport::getTimezone() {
    return timezone;
}

string Airport::getDST() {
    return DST;
}

string Airport::getTz() {
    return tz;
}

string Airport::getType() {
    return type;
}

string Airport::getDatasource() {
    return datasource;
}
