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
		l1.setFacilities("xxxx");
		l1.setTiming("xxxx");
		d1.setName("xxxx");
		d1.setDesig("xxxx");
		d1.setExp("xxxx");
		d1.setContact(000);
	}
	Hospital(string name, string address, string n, string d, string e, int c,string f,string t)
	{
		this->name=name;
		this->address=address;
		//initializing lab variables
		l1.setFacilities(f);
		l1.setTiming(t);
		
		d1.setName(n);
		d1.setDesig(d);
		d1.setExp(e);
		d1.setContact(c);
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
		cout << "Hospital Name: " << name<<endl;
		cout << "Address: " << address<<endl;
	}
	void labDisp()
	{
		l1.display();
	}
	void DocDisp()
	{
		d1.display();
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
	Location(string area, string name, string address, string dn,string des, string ex, int con,string fa,string ti)
	{
		this->area=area;
		Hospital h2(name,address,dn,des,ex,con,fa,ti);
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
	void labDisp()
	{
		h1.labDisp();
	}
	void DocDisp()
	{
		h1.DocDisp();
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
    GeneralHospital(string departments,string name,string address,string timing, string dn,string des, string ex, int con,string fa,string ti): Hospital(name, address,dn,des,ex,con,fa,ti)
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
	SpecializedHospital(string type,string name,string address,string timing, string dn,string des, string ex, int con,string fa,string ti): Hospital(name, address,dn,des,ex,con,fa,ti)
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
	string loc, search;
	int opt;
	cout<<"Do you want to search for Hospital or Lab?"<<endl;
	cin>>search;
	//HOSPITALS
	if(search=="Hospital")
	{
		cout<<"Enter Location: "<<endl;
	    cin>>loc;
		if(loc=="DHA")
	    {
		    Location dha1("DHA", "NMC","adadadadad","taha","psych","bohat",1,"mri","8AM-6PM");
		    Location dha2("DHA", "Bayview","bay","Kamran","phys","boh",2,"xray","8AM-8PM");
		    Location dha3("DHA", "NMC","adadadadad","anum","psycho","bo",3,"blood test","8AM-7PM");
		    cout<<"1: "; 
		    dha1.display();
		    cout<<endl;
		    cout<<"2: "; 
		    dha2.display();
		    cout<<endl;
		    cout<<"3: "; 
		    dha3.display();
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL"<<endl;
		    cin>>opt;
		    switch(opt)
		    {
			    case 1:
			    dha1.DocDisp();
			    break;
			    case 2:
			    dha2.DocDisp();
				break;
				case 3:
				dha3.DocDisp();
				break;

			}
		}
		else if(loc=="Nazimabad")
		{
			Location naz1("Nazimabad", "Lifeline", "khjhkgjgkjh","tah","psyc","boha",00002,"medical","9AM-5PM");
			Location naz2("Nazimabad", "Dr.Ziauddin Hospital","adadadadad","Ahmed","dentist","normal",0300,"mri","8AM-6PM");
		    	Location naz3("Nazimabad", "Liaquat National","liaquat road","Kamran","cardiologist","jis school main tum prhte thy uskay principal ",333022289,"xray","8AM-8PM");
			cout<<"1: "; 
			naz1.display();
			cout<<endl;
			cout<<"2: "; 
			naz2.display();
			cout<<endl;
			cout<<"3: "; 
			naz3.display();
			cout<<endl;
			cout<<"ENTER NUMBER TO CHOOSE HOSPITAL"<<endl;
			cin>>opt;
			switch(opt)
		    	{
			    	case 1:
			    	naz1.DocDisp();
			    	break;
			    	case 2:
			    	naz2.DocDisp();
				break;
				case 3:
				naz3.DocDisp();
				break;
			}
		}
		else if(loc=="Gulshan")
		{
			Location gul1("Gulshan", "Medicare", "gfgfgfgf","tayyab","general physician","you will be the first patient",00003,"medical","7PM-9PM");
			Location gul2("Gulshan", "Agha Khan","adadadadad","ali","radiologist","high",2382839382,"mri","8AM-6PM");
			Location gul3("Gulshan", "Liaquat National","ncc road","musawar","programmer", "normal",333022289,"xray","8AM-8PM");
			cout<<"1: "; 
			gul1.display();
			cout<<endl;
			cout<<"2: "; 
			gul2.display();
			cout<<endl;
			cout<<"3: "; 
			gul3.display();
			cout<<endl;
			cout<<"ENTER NUMBER TO CHOOSE HOSPITAL"<<endl;
			cin>>opt;
			switch(opt)
			 {
			    	case 1:
			    	gul1.DocDisp();
			    	break;
			    	case 2:
			    	gul2.DocDisp();
				break;
				case 3:
				gul3.DocDisp();
				break;
			}
		}
		else if(loc=="Clifton")
		{
			Location clif1("Clifton", "Parklane", "70 clifton","muaaz","ps","high",00004,"medical","2AM-7M");
			Location clif2("Clifton", "Altamash","shahrah e ghalib road","nashit","oncologists","highly experienced",2382856,"chemotherapy","8AM-6PM");
		   	Location clif3("Clifton", "South city","shahrah e firdousi","sameer","neurologists", "high",3289,"blood tests","8AM-8PM");
		   	cout<<"1: "; 
		    	clif1.display();
		    	cout<<endl;
		    	cout<<"2: "; 
		    	clif2.display();
		    	cout<<endl;
		    	cout<<"3: "; 
		    	clif3.display();
		   	cout<<endl;
		   	cout<<"ENTER NUMBER TO CHOOSE HOSPITAL"<<endl;
		   	cin>>opt;
			switch(opt)
		  	{
			    	case 1:
				clif1.DocDisp();
			   	break;
			   	case 2:
			    	clif2.DocDisp();
				break;
				case 3:
				clif3.DocDisp();
				break;
			}
	}
	//LABS
	else
	{
		cout<<"Enter Location: "<<endl;
	    cin>>loc;
		if(loc=="DHA")
	    {
		    Location dha1("DHA", "NMC","adadadadad","taha","Attendant","bohat",1,"mri","8AM-6PM");
		    Location dha2("DHA", "Bayview","bay","Kamran","Attendant","1 month",2,"xray","8AM-8PM");
		    Location dha3("DHA", "NMC","adadadadad","anum","Senior nurse","11 years",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital: "; 
		    dha1.display();
		    
		    cout<<endl;
		    cout<<"2: Lab at Hospital:"; 
		    dha2.display();
		   
		    cout<<endl;
		    cout<<"3: Lab at Hospital:"; 
		    dha3.display();
		   
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
		    switch(opt)
		    {
			    case 1:
			    dha1.labDisp();
			    dha1.DocDisp();
			    break;
			    case 2:
			    dha2.labDisp();
			     dha2.DocDisp();
				break;
				case 3:
				dha3.labDisp();
				 dha3.DocDisp();
				break;		
			}
		}
		else if(loc=="Nazimabad")
		
		{
			Location naz1("Nazimabad", "Lifeline lab", "khjhkgjgkjh","Maqbool Hussain","Nurse","9 months",00002,"vaccination","9AM-5PM");
			 Location naz2("Nazimabad", "Ziauddin lab","fvefvfdvdfvdfv","Ali Raza","Nurse","3 years",2,"ultra sound","8AM-8PM");
		    Location naz3("Nazimabad", "Esaa lab","avfvfvf","Zainab khan","Nurse","9 years",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital: "; 
		    naz1.display();
		    cout<<endl;
		    cout<<"2: Lab at Hospital:"; 
		    naz2.display();
		    cout<<endl;
		    cout<<"3: Lab at Hospital:"; 
		    naz3.display();
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
		    switch(opt)
		    {
			    case 1:
			    naz1.labDisp();
			    naz1.DocDisp();
			    break;
			    case 2:
			    naz2.labDisp();
			    naz2.DocDisp();
				break;
				case 3:
				naz3.labDisp();
				naz3.DocDisp();
				break;		
			}
		}
		else if(loc=="Gulshan")
		{
			Location gul1("Gulshan", "Medicare", "gfgfgfgf","Alina khan","Attendant","5 years",00003,"vaccination","7PM-9PM");
		    Location gul2("Gulshan", "Chughtai lab","fvefvfdvdfvdfv","Maryam Raza","Nure","6 year",2,"ultra sound","8AM-8PM");
		    Location gul3("Gulshan", "Aga khan lab","avfvfvf","Fatima Aamir","Nurse","8 month",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital: "; 
		    gul1.display();
		    cout<<endl;
		    cout<<"2: Lab at Hospital:"; 
		    gul2.display();
		    cout<<endl;
		    cout<<"3: Lab at Hospital:"; 
		    gul3.display();
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
		    switch(opt)
		    {
			    case 1:
			    gul1.labDisp();
			    gul1.DocDisp();
			    break;
			    case 2:
			    gul2.labDisp();
			    gul2.DocDisp();
				break;
				case 3:
				gul3.labDisp();
				gul3.DocDisp();
				break;		
			}
			
		}
		else if(loc=="Clifton")
		{
			Location clif1("Clifton", "Dow lab", "rfrgergegegre","Ifrah Adil","nurse","3 years",00004,"Vaccination","2AM-7M");
			Location clif2("Clifton", "Chughtai lab branch 2","fvefvfdvdfvdfv","Muqaddas Imran","Nurse","1 year",2,"ultra sound","8AM-8PM");
		    Location clif3("Clifton", "DOW lab","avfvfvf","Wasim Ali","Attendant","2 years",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital: "; 
		    clif1.display();
		    cout<<endl;
		    cout<<"2: Lab at Hospital:"; 
		    clif2.display();
		    cout<<endl;
		    cout<<"3: Lab at Hospital:"; 
		    clif3.display();
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
		    switch(opt)
		    {
			    case 1:
			    clif1.labDisp();
			    clif1.DocDisp();
			    break;
			    case 2:
			    clif2.labDisp();
			    clif3.DocDisp();
				break;
				case 3:
				clif3.labDisp();
				clif3.DocDisp();
				break;		
			}
					}
		else
		{
			cout<<"guru madir"<<endl;
		}	
	}
	
	return 0;
}
