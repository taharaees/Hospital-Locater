#include<iostream>
using namespace std;
class Location{
	string address;
	string city;
	Hospital h1;//has a relation
};
class Doctor{
	string name;
	string designation; //type of doctor e.g psychiatrist, cardiologist, general physician, dermatologist
    string exp;
	int contact;
};
class Hospital{
	string name;
	string address;
	string timing;
    //has a relation
	Doctor d1;
	Lab l1;
};
class Lab
{
	string timing;
	string facilities;
	
};
//Child classes of hospital
class GeneralHospital:public Hospital
{
    string deaprtments;
};
class SpecializedHospital:public Hospital
{
	string type;
};