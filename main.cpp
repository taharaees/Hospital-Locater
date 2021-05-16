#include<iostream>
using namespace std;
class Doctor
{
	string name;
	string designation; //type of doctor e.g psychiatrist, cardiologist, general physician, dermatologist
    string exp;
	int contact;
	public:
	//Constructors
	Doctor()
	{
		name="xxxx";
		designation="xxxx"; 
    	exp="xxxx";
		contact=0;		
	}
	Doctor(string name,string designation,string exp,int contact)
	{
		this->name=name;
		this->designation=designation;
		this->exp=exp;
		this->contact=contact;
	}
};
class Lab
{
	string timing;
	string facilities;
	public:
	//Constructors
	Lab()
	{
		timing="xxxx";
		facilities="xxxx";
	}
	Lab(string timing,string facilities)
	{
		this->timing=timing;
		this->facilities=facilities;
	}
};
class Hospital
{
	string name;
	string address;
	string timing;
	public:
	Hospital()
	{
		name="xxxx";
		address="xxxx";
		timing="xxxx";
	}
	Hospital(string name, string address, string timing)
	{
		this->name=name;
		this->address=address;
		this->timing=timing;
	}
	
    //has a relation
	Doctor d1;
	Lab l1;
};
class Location
{
	string address;
	string city;
	//has a realtion
	Hospital h1;

	public:
	//Constructors
	Location()
	{
		address="xxxx";
		city="xxxx";
	}
	Location(string address,string city)
	{
		this->address=address;
		this->city=city;
	}
		
};
//Child classes of hospital
class GeneralHospital:public Hospital
{
    string departments;
    public:
	//Constructors
	GeneralHospital():Hospital()
	{
		departments="xxxx";
	}
    GeneralHospital(string departments,string name,string address,string timing): Hospital(name, address, timing)
    {
    	this->departments=departments;
	}
};
class SpecializedHospital:public Hospital
{
	string type;
	public:
	//Constructors
	SpecializedHospital(): Hospital()
		{
			type="xxxx";
		}
	SpecializedHospital(string type,string name,string address,string timing): Hospital(name, address, timing)
		{
			this->type=type;
		}
};
int main()
{
	return 0;
}
