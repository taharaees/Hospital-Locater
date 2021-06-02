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
		cout<<"Contact: 0"<<contact<<endl;
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
	void Hdisplay()
	{
		cout << "Hospital Name: " << name<<endl;
		cout << "   Address: " << address<<endl;
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

//Child classes of hospital
class SpecializedHospital:public Hospital
{
	string type;
	public:
	//Constructors
	SpecializedHospital(): Hospital()
		{
			type="xxxx";
		}
	SpecializedHospital(string type,string name,string address, string dn,string des, string ex, int con,string fa,string ti): Hospital(name, address,dn,des,ex,con,fa,ti)
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
			Hdisplay();
			cout<<"   Type of hospital is: "<<type<<endl;
		}
};



class Location
{
	string area;
	//has a realtion
	SpecializedHospital sh1;

	public:
	//Constructors
	Location()
	{
		area="xxxx";
		sh1.setName("xxxx");
		sh1.setAddress("xxxx");
	}
	Location(string area, string type, string name, string address, string dn,string des, string ex, int con,string fa,string ti)
	{
		this->area=area;
		SpecializedHospital sh2(type, name,address,dn,des,ex,con,fa,ti);
		sh1=sh2;
	}
	//setter
	void setAddress(string address)
	{
		this->area=area;
	}

	//getter
	void display()
	{
		sh1.display();
	}
	void labDisp()
	{
		sh1.labDisp();
	}
	void DocDisp()
	{
		sh1.DocDisp();
	}
		
};


int main()
{
	string loc, search;
	int opt;
	cout<<"Do you want to search for Hospital or Lab?"<<endl;
	cin>>search;
	//HOSPITALS
	if(search=="Hospital"||search=="hospital")
	{
		cout<<"Enter Location: "<<endl;
	    cin>>loc;
		if(loc=="DHA"||loc=="dha")
	    {
		    Location dha1("DHA","Skin care", "NMC","sunset boulevard street 11","Taha","psychiatrist","more than 8 years of experience",211345445,"mri","8AM-6PM");
			Location dha1A("DHA","Skin care", "NMC","sunset boulevard street 11","Malaecah","Dermotologist","2 years of experience",213476672,"mri","8AM-6PM");
			Location dha1B("DHA","Skin care", "NMC","sunset boulevard street 11","Alina","Neurologist","3 years of experience",217468928,"mri","8AM-6PM");
		    Location dha2("DHA", "cardic and heart disease", "Bayview", "6th lane, phase 8","Kamran","Cardiologist","7 years of experience",333022289,"xray","8AM-8PM");
			Location dha2A("DHA", "cardic and heart disease", "Bayview", "6th lane, phase 8","Shoaib","Pediatrician","at house job",213578734,"mri","8AM-8PM");
			Location dha2B("DHA", "cardic and heart disease", "Bayview", "6th lane, phase 8","Altaf","psych","6 years of experience",21376657,"mri","8AM-6PM");
		    Location dha3("DHA", "Abdomen and pelvis", "Shifa Hospital","sailor st, bukhari lane 6","Aisha","Gynecologist","12 years of experience",21345883,"blood test","8AM-7PM");
			Location dha3A("DHA", "Abdomen and pelvis", "Shifa Hospital","sailor st, bukhari lane 6","Ali","Rheumatologist","4 years of experience",21900786,"mri","8AM-6PM");
			Location dha3B("DHA", "Abdomen and pelvis", "Shifa Hospital","sailor st, bukhari lane 6","Malaika","Genral physician","3 years of experience",21674699,"full body scan","8AM-6PM");
			
			
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
			cout<<endl;
		    switch(opt)
		    {
			    case 1:
			    dha1.DocDisp();
				cout<<endl;
				dha1A.DocDisp();
				cout<<endl;
				dha1B.DocDisp();
				cout<<endl;
			    break;
			    case 2:
			    dha2.DocDisp();
				cout<<endl;
				dha2A.DocDisp();
				cout<<endl;
				dha2B.DocDisp();
				cout<<endl;
				break;
				case 3:
				dha3.DocDisp();
				cout<<endl;
				dha3A.DocDisp();
				cout<<endl;
				dha3B.DocDisp();
				cout<<endl;
				break;
				default:
					cout << "Invalid option selected";
			}
		}
		else if(loc=="Nazimabad"||loc=="nazimabad")
		{
			Location naz1("Nazimabad", "ENT","Lifeline", "st near Aisha masjid","Hina","Ophthalmologist","5 years of experience",2137619,"medical","9AM-5PM");
			Location naz1A("Nazimabad","ENT", "Lifeline", "16th st, near Aisha masjid","Alia","Dentist","7 years of experience",343768793,"medical","9AM-5PM");
			Location naz1B("Nazimabad","ENT", "Lifeline", "16th st, near Aisha masjid","Imran","ENT specialist","3 years of experience",2138789,"medical","9AM-5PM");
			Location naz2("Nazimabad", "skin","Ziauddin Hospital","Nazimabad 3, block 3","Ahmed","Eye specialist","9 years of experience",21084980,"mri","8AM-6PM");
			Location naz2A("Nazimabad","skin", "Ziauddin Hospital", "Nazimabad 3, block 3","Asjid","Endocrinologist","2 years of experience",21083979,"medical","9AM-5PM");
			Location naz2B("Nazimabad","skin", "Ziauddin Hospital", "Nazimabad 3, block 3","Aliyan","Dermotologist","5 years of experience",397862878,"scan","9AM-5PM");
		    Location naz3("Nazimabad", "surgeries","Liaquat National","liaquat road","Faisal","cardiologist","9 years of experience",333024532,"xray","8AM-8PM");
			Location naz3A("Nazimabad","surgeries", "Liaquat National", "liaquat road","Ashiq Hussain","Neuro surgeon","3 years of experience",323727672,"citiscan","9AM-5PM");
			Location naz3B("Nazimabad", "surgeries","Liaquat National", "liaquat road","Areeba","physiotherapist","5 years of experience",219379483,"blood test","9AM-5PM");
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
			cout<<endl;
			switch(opt)
		    {
				case 1:
				naz1.DocDisp();
				cout<<endl;
				naz1A.DocDisp();
				cout<<endl;
				naz1B.DocDisp();
				cout<<endl;
				break;
				case 2:
				naz2.DocDisp();
				cout<<endl;
				naz2A.DocDisp();
				cout<<endl;
				naz2B.DocDisp();
				cout<<endl;
				break;
				case 3:
				naz3.DocDisp();
				cout<<endl;
				naz3A.DocDisp();
				cout<<endl;
				naz3B.DocDisp();
				cout<<endl;
				break;
				default:
					cout << "Invalid option selected";
			}
		}
		else if(loc=="Gulshan"||loc=="gulshan")
		{
			Location gul1("Gulshan","Bones", "Medicare", "shaheedemillat rd","Tayyab","Rheumatologist","9 years of experience",33347479,"medical","7PM-9PM");
			Location gul2("Gulshan", "Lungs","Agha Khan","near national stadium","Ali","Pulmonogistt","14 years of experience",213828393,"mri","8AM-6PM");
			Location gul3("Gulshan","Psychiatry", "Liaquat National","ncc road","Musawar","Pediatrician", "1 year of experience",33304973,"xray","8AM-8PM");
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
			cout<<endl;
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
				default:
					cout << "Invalid option selected";
			}
		}
		else if(loc=="Clifton"||loc=="clifton")
		{
			Location clif1("Clifton", "cancer", "Parklane", "70 clifton","Muaaz","Infectious disease specialist","8 years of experience",23768090,"medical","2AM-7M");
			Location clif1A("Clifton", "Cancer", "Parklane", "70 clifton","Mahira","Oncologist","15 years of experience",333343244,"medical","2AM-7M");
			Location clif1B("Clifton", "Cancer", "Parklane", "70 clifton","Anum","Endocrinologist","3 years of experience",21333442,"medical","2AM-7M");
			Location clif2("Clifton", "Dental",  "Altamash","shahrah e ghalib road","Nashit","Oncologists","2 years of experience",23828562,"chemotherapy","8AM-6PM");
			Location clif2A("Clifton", "Dental",  "Altamash", "shahrah e ghalib road","Sahab","Dentist","6 years of experience",33282893,"medical","2AM-7M");
			Location clif2B("Clifton", "Dental",  "Altamash", "shahrah e ghalib road","Sameer","Otolaryngologist","7 years of experience",214869833,"medical","2AM-7M");
		   	Location clif3("Clifton", "Brain disease", "South city","shahrah e firdousi","sameer","neurologists", "6 year of experience",345779892,"blood tests","8AM-8PM");
			Location clif3A("Clifton", "Brain disease", "Parklane", "70 clifton","Amitabh","General practitioner","1 years of experience",334687981,"medical","2AM-7M");
			Location clif3B("Clifton", "Brain disease",  "Parklane", "70 clifton","Haseeb","Radiologist","11 years of experience",221874948,"medical","2AM-7M");
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
			cout<<endl;
			switch(opt)
		  	{
			    case 1:
				clif1.DocDisp();
				cout<<endl;
				clif1A.DocDisp();
				cout<<endl;
				clif1B.DocDisp();
				cout<<endl;
			   	break;
			   	case 2:
			    clif2.DocDisp();
				cout<<endl;
				clif2A.DocDisp();
				cout<<endl;
				clif2B.DocDisp();
				cout<<endl;
				break;
				case 3:
				clif3.DocDisp();
				cout<<endl;
				clif3A.DocDisp();
				cout<<endl;
				clif3B.DocDisp();
				cout<<endl;
				break;
				default:
					cout << "Invalid option selected";
			}
		}
		else
		{
			cout<<"Invalid Location for Hospitals selected. \nNo such location exits."<<endl;
		}	
}
	//LABS
	else if(search=="Lab" || "lab")
	{
		cout<<"Enter Location: "<<endl;
	    cin>>loc;
		if(loc=="DHA"||loc=="dha")
	    {
		    Location dha1("DHA", "MRI", "NMC","adadadadad","taha","Attendant","bohat",1,"mri","8AM-6PM");
		    Location dha2("DHA", "X-RAY", "Bayview","bay","Kamran","Attendant","1 month",2,"xray","8AM-8PM");
		    Location dha3("DHA", "Blood Test", "NMC","adadadadad","anum","Senior nurse","11 years",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital:\n "; 
		    dha1.display();
		    
		    cout<<endl;
		    cout<<"2: Lab at Hospital:\n"; 
		    dha2.display();
		   
		    cout<<endl;
		    cout<<"3: Lab at Hospital:\n"; 
		    dha3.display();
		   
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
			cout<<endl;
		    switch(opt)
		    {
			    case 1:
			    dha1.labDisp();
			    break;
			    case 2:
			    dha2.labDisp();
				break;
				case 3:
				dha3.labDisp();
				break;	
				default:
					cout << "Invalid option selected";	
			}
		}
		else if(loc=="Nazimabad"||loc=="nazimabad")
		
		{
			Location naz1("Nazimabad","Vaccination", "Lifeline lab", "khjhkgjgkjh","Maqbool Hussain","Nurse","9 months",00002,"vaccination","9AM-5PM");
			 Location naz2("Nazimabad","Ultrasound",  "Ziauddin lab","fvefvfdvdfvdfv","Ali Raza","Nurse","3 years",2,"ultra sound","8AM-8PM");
		    Location naz3("Nazimabad", "Blood test", "Esaa lab","avfvfvf","Zainab khan","Nurse","9 years",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital:\n"; 
		    naz1.display();
		    cout<<endl;
		    cout<<"2: Lab at Hospital:\n"; 
		    naz2.display();
		    cout<<endl;
		    cout<<"3: Lab at Hospital:\n"; 
		    naz3.display();
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
			cout<<endl;
		    switch(opt)
		    {
			    case 1:
			    naz1.labDisp();
			    break;
			    case 2:
			    naz2.labDisp();
				break;
				case 3:
				naz3.labDisp();
				break;	
				default:
					cout << "Invalid option selected";	
			}
		}
		else if(loc=="Gulshan"||loc=="gulshan")
		{
			Location gul1("Gulshan", "Vaccination", "Medicare", "gfgfgfgf","Alina khan","Attendant","5 years",00003,"vaccination","7PM-9PM");
		    Location gul2("Gulshan", "Ultrasound", "Chughtai lab","fvefvfdvdfvdfv","Maryam Raza","Nure","6 year",2,"ultra sound","8AM-8PM");
		    Location gul3("Gulshan", "Blood test", "Aga khan lab","avfvfvf","Fatima Aamir","Nurse","8 month",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital:\n"; 
		    gul1.display();
		    cout<<endl;
		    cout<<"2: Lab at Hospital:\n"; 
		    gul2.display();
		    cout<<endl;
		    cout<<"3: Lab at Hospital:\n"; 
		    gul3.display();
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
			cout<<endl;
		    switch(opt)
		    {
			    case 1:
			    gul1.labDisp();
			    break;
			    case 2:
			    gul2.labDisp();
				break;
				case 3:
				gul3.labDisp();
				break;	
				default:
					cout << "Invalid option selected";	
			}
			
		}
		else if(loc=="Clifton"||loc=="clifton")
		{
			Location clif1("Clifton", "Vaccination", "Dow lab", "rfrgergegegre","Ifrah Adil","nurse","3 years",00004,"Vaccination","2AM-7M");
			Location clif2("Clifton", "Ultra sound", "Chughtai lab branch 2","fvefvfdvdfvdfv","Muqaddas Imran","Nurse","1 year",2,"ultra sound","8AM-8PM");
		    Location clif3("Clifton", "Blood test", "DOW lab","avfvfvf","Wasim Ali","Attendant","2 years",3,"blood test","8AM-7PM");
		    cout<<"1: Lab at Hospital:\n"; 
		    clif1.display();
		    cout<<endl;
		    cout<<"2: Lab at Hospital:\n"; 
		    clif2.display();
		    cout<<endl;
		    cout<<"3: Lab at Hospital:\n"; 
		    clif3.display();
		    cout<<endl;
		    cout<<"ENTER NUMBER TO CHOOSE HOSPITAL LAB"<<endl;
		    cin>>opt;
			cout<<endl;
		    switch(opt)
		    {
			    case 1:
			    clif1.labDisp();
			    break;
			    case 2:
			    clif2.labDisp();
				break;
				case 3:
				clif3.labDisp();
				break;	
				default:
					cout << "Invalid option selected";	
			}
					}
		else
		{
			cout<<"Invalid Location for Labs selected. \nNo such location exits."<<endl;
		}	
	}
	
	return 0;
}
