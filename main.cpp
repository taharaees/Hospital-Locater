#include<iostream>
using namespace std;
class Location{
	string address;
	string city;
	Hospital h1;//has a relation

	public:
		Location()
		{
			address="xxxx";
			city="xxxx";
		}
		Location(string address,string city, string H)
		{
			this->address=address;
			this->city=city;
		}
		
};
class Doctor{
	string name;
	string designation; //type of doctor e.g psychiatrist, cardiologist, general physician, dermatologist
    string exp;
	int contact;
	public:
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
class Hospital{
	public:
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
	public:
		Lab()
		{
			timing="xxxx";
			facilities="xxxx";
		}
		Lab(string timing,string facilities)
		{
			this->timing=timing;
			this->facilities;
		}
};
//Child classes of hospital
class GeneralHospital:public Hospital
{
    string departments;
    public:
    GeneralHospital(string departments,string name,string address,string timing)
    {
    	this->departments=departments;	
    	this->name=name;
    	this->address=address;
    	this->timing=timing;
	}
	GeneralHospital()
	{
		departments="xxxx";
		name="xxxx";
		address="xxxx";
		timing="xxxx";
	}
};
class SpecializedHospital:public Hospital
{
	string type;
	public:
		SpecializedHospital(string type,string name,string address,string timing)
		{
			this->type=type;
			this->name=name;
    		this->address=address;
    		this->timing=timing;
		}
		SpeciaizedHospital()
		{
			type="xxxx";
			name="xxxx";
			address="xxxx";
			timing="xxxx";
		}
};
int main()
{
	
}
