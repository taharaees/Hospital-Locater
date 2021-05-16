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
	//setter functions
	void setName(string n)
	{
		name=n;
	}
	void setDesig(string d)
	{
		designation=d;
	}
	void setExp(string e)
	{
		exp=e;
	}
	void setContact(int c)
	{
		contact=c;
	}
	// getter functions
	void display()
	{
		cout<<"Name of doctor: "<<name<<endl;
		cout<<"Designation: "<<designation<<endl;
		cout<<"Experience: "<<exp<<endl;
		cout<<"Contact: "<<contact<<endl;
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
	public:
	//setter functions
	void settiming(string timing)
	{
		this->timing=timing;
	}
	void setfacilities(string facilities)
	{
		this->facilities=facilities;
	}	  
	//display functions
	void display()
	{
		cout << "Timings: " << timing;
		cout << "Facilities: " << facilities;
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
	
	
	public:
		//setter functions
	void setname(string name)
	{
		this->name=name;
	}
	void setaddress(string address)
	{
		this->address=address;
	}
	void settiming(string timing)
	{
		this->timing=timing;
	}
	
	//display function
	void display()
	{
		cout << "Name: " << name;
		cout << "Address: " << address;
		cout << "Timings: " << timing;
	}
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
		//setter
	void set_address(string address)
	{
		this->address=address;
	}
	void set_city(string city)
	{
		this->city=city;
	}
	void display()
	{
		cout<<"Address is: "<<address;
		cout<<"City is: "<<city;
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
	//setter
	void set_departments(string departments)
	{
		this->departments=departments;
	}
	void display()
	{
		cout<<"Department is: "<<departments;
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
		//Setter
		void set_type(string type)
		{
			this->type=type;
		}
		void display()
		{
			cout<<"Type is: "<<type;
		}
};
int main()
{
	return 0;
}
