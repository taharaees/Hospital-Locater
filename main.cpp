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
	void setTiming(string timing)
	{
		this->timing=timing;
	}
	void setFacilities(string facilities)
	{
		this->facilities=facilities;
	}	  
	//display functions
	void display()
	{
		cout << "Timings: " << timing<<endl;
		cout << "Facilities: " << facilities<<endl;
	}

};
class Hospital
{
	string name;
	string address;
	//has a relation
	Doctor d1;
	Lab l1;
	public:
	Hospital()
	{
		name="xxxx";
		address="xxxx";
	}
	Hospital(string name, string address, string n, string d, string e, int c)
	{
		this->name=name;
		this->address=address;
	}
	public:
		//setter functions
	void setName(string name)
	{
		this->name=name;
	}
	void setAddress(string address)
	{
		this->address=address;
	}

	
	//display function
	void display()
	{
		cout << " Hospital Name: " << name<<endl;
		cout << "Address: " << address<<endl;
		d1.display();
		l1.display();
	}
};
class Location
{
	string area;
	//has a realtion
	Hospital h1;

	public:
	//Constructors
	Location()
	{
		area="xxxx";
		h1.setName("xxxx");
		h1.setAddress("xxxx");
	}
	Location(string area, string name, string address, string dn,string des, string ex, int con)
	{
		this->area=area;
		Hospital h2(name,address,dn,des,ex,con);
		h1=h2;
	}
	//setter
	void setAddress(string address)
	{
		this->area=area;
	}

	//getter
	void display()
	{
		cout<<"Area is: "<<area<<endl;
		h1.display();
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
    GeneralHospital(string departments,string name,string address,string timing, string dn,string des, string ex, int con): Hospital(name, address,dn,des,ex,con)
    {
    	this->departments=departments;
	}
	//setter
	void setDepartments(string departments)
	{
		this->departments=departments;
	}
	//getter
	void display()
	{
		cout<<"Department is: "<<departments<<endl;
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
	SpecializedHospital(string type,string name,string address,string timing, string dn,string des, string ex, int con): Hospital(name, address,dn,des,ex,con)
		{
			this->type=type;
		}
		//Setter
		void setType(string type)
		{
			this->type=type;
		}
		//getter
		void display()
		{
			cout<<"Type is: "<<type<<endl;
		}
};

int main()
{
	string loc;

	cout<<"Enter Location: "<<endl;
	cin>>loc;

	if(loc=="DHA")
	{
		Location dha("DHA", "NMC","adadadadad","taha","psych","bohat",00001);
		dha.display();
	}
	else if(loc=="Nazimabad")
	{
		Location naz("Nazimabad", "Lifeline", "khjhkgjgkjh","tah","psyc","boha",00002);
	}
	else if(loc=="Gulshan")
	{
		Location gul("Gulshan", "Medicare", "gfgfgfgf","ta","psy","boh",00003);
	}
	else if(loc=="Clifton")
	{
		Location clif("Clifton", "Parklane", "70 clifton","t","ps","bo",00004);
		clif.display();
	}
	else
	{
		cout<<"guru madir"<<endl;
	}
	return 0;
}
