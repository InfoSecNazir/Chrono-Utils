#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class clData
{
private:
	int Day, Monthe, Yaers;
	struct StData
	{
		int day, monthe, yers;

	};
	string StData;
	void Calculater_Data_From_Days(int TotalDAys, int Year) {
		static int DAysinMonthe[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		this->Yaers = Year;
		Monthe = 1;
		while (TotalDAys > DAysinMonthe[Monthe - 1]) {
			TotalDAys -= DAysinMonthe[Monthe - 1];
			Monthe++;


			if (Monthe > 12) {
				Monthe = 1;
				Year++;

			}
		}


		Day = TotalDAys;
	}
public:
	clData(string StData) {
		this->StData = StData;
	}
	clData() :Day(1), Monthe(12), Yaers(2022) {}


	clData(int Day, int Monthe, int Years) {
		this->Day = Day;
		this->Monthe = Monthe;
		this->Yaers = Years;
	}
	clData(int Total_Day, int Ysers) {
		Calculater_Data_From_Days(Total_Day, Ysers);
	}

	string Number_To_Text(int Number) {
		if (Number == 0) {
			return "";
		}
		if (Number >= 1 && Number <= 19) {
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99) {
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return arr[Number / 10] + "" + Number_To_Text(Number % 10);
		}
		if (Number >= 100 && Number <= 199) {
			return "one Handred " + Number_To_Text(Number % 100);
		}
		if (Number >= 200 && Number <= 999) {
			return Number_To_Text(Number / 100) + " Handred " + Number_To_Text(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999) {
			return "one Thaothen " + Number_To_Text(Number % 1000);

		}
		if (Number >= 2000 && Number <= 99999) {
			return Number_To_Text(Number / 1000) + " Thothen " + Number_To_Text(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999) {
			return " one Million " + Number_To_Text(Number % 10000);
		}
		if (Number >= 2000000 && Number <= 9999999) {
			return Number_To_Text(Number / 10000) + " Million " + Number_To_Text(Number % 10000);
		}
		if (Number >= 1000000000 && Number <= 1999999999) {
			return "one Billion " + Number_To_Text(Number % 1000000000);
		}
		else {
			return Number_To_Text(Number / 1000000000) + " Billoin " + Number_To_Text(Number % 1000000000);
		}
	}

static   bool Leap_Year(int Year) {
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
static	short Number_Of_DayinYear(int Year) {
		return Leap_Year(Year) ? 366 : 365;
	}
static	short Number_Of_hOur_in_Year(short Year) {
		return Number_Of_DayinYear(Year) * 24;
	}
static	short NumberOfMomentinYeaer(int Yaer) {
		return Number_Of_DayinYear(Yaer) * 60;
	}
static	short Number_Of_Secode_in_Year(int Year) {
		return Number_Of_hOur_in_Year(Year) * 60;
	}

static	short Number_of_Day_Monthe(int Year, int Monthe) {
		if (Monthe < 1 || Monthe>12)return 0;
		return (Monthe == 2) ? Leap_Year(Year) ? 29 : 28 : (Monthe == 4 || Monthe == 6 || Monthe == 9 || Monthe == 11) ? 30 : 31;
	}
static	short Number_of_Hour_Monthe(int Y, int M) {
		return Number_of_Day_Monthe(Y, M) * 24;
	}
static	short Number_of_Moment_Monthe(int Y, int M) {
		return Number_of_Hour_Monthe(Y, M) * 60;
	}
static	short Number_of_Secode_Monthe(int Y, int M) {
		return Number_of_Moment_Monthe(Y, M) * 60;
	}


	static short DayOfWeekOrder(short Day, short Month, short Year) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian://0:sun, 1:
		// Mon, 2:Tue...etc 
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	string Day_Of_Name(short Day) {
		string arrName[] = { "San","Man","Teu","Wed","Thu","Fri","Sat" };
		return arrName[Day];
	}
	void My_Brthday(short Day ,short Monthe ,short Year ) {
		
	 
		cout << "The Data is :  " << Day << "/" << Monthe << "/" << Year << endl;
		cout << "The Number Day is : " << DayOfWeekOrder(Day, Monthe, Year) << endl;
		cout << "The Name Day of Week is : " << Day_Of_Name(DayOfWeekOrder(Day, Monthe, Year)) << endl;
	}

	string Monthe_of_Name(short Num) {
		string arrMonthe[] = { "Jan","Fab","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arrMonthe[Num - 1];
	}
	void Print_Clenader_Monthe(int M, int Y) {
		int NUM_Of_Day = 0;
		int Currnt = DayOfWeekOrder(1, M, Y);

		NUM_Of_Day = Number_of_Day_Monthe(Y, M);
		printf("\n____________%s_________________\n");
		Monthe_of_Name(M).c_str();
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		int i = 0;
		for (i = 0; i < Currnt; i++)
		{
			printf("     ");
			for (int j = 1; j <= NUM_Of_Day; j++)
			{
				printf("%5d", j);

				if (++i == 7) {
					i = 0;
					printf("\n");
				}


			}

		}
		printf("\n____________________________________________________\n");

	}

	void Print_Clender_of_Year(int Y) {
		for (int i = 1; i <= 12; i++)
		{
			Print_Clenader_Monthe(i, Y);
			cout << "\n";
		}

	}

 
	void TotalDay_To_Data(int Total_Day, int Y) {
		int Monthe = 1;
		int D = 0;
		while (Total_Day > Number_of_Day_Monthe(Y, Monthe)) {
			Total_Day -= Number_of_Day_Monthe(Y, Monthe);
			Monthe++;
			if (Monthe > 12) {
				Monthe = 1;
				Y++;
			}
		}
		D = Total_Day;

		cout << "The Data is : " << D << "/" << Monthe << "/" << Y << endl;

	}
	int From_Day_Beging_of_Days(int Day, int Monthe, int Yers) {
		int Total_Day = 0;
		for (int i = 1; i < Monthe; i++)
		{
			Total_Day += Number_of_Day_Monthe(Yers, i);
		}

		Total_Day += Day;

		return Total_Day;
	}
	void Add_Day_To_Data(int Day,const clData &D) {
		int Total_Day = From_Day_Beging_of_Days(D.Day, D.Monthe, D.Yaers);
		Total_Day += Day;
		TotalDay_To_Data(Total_Day, D.Yaers);
	


	}
	

	void Screen_Add_To_Data(const clData& Data,int add) {
		 
	 
		cout << "The Data After add Day is : \n";
		Add_Day_To_Data(add, Data);

	}
	bool operator<(const clData& a) {
		if (Yaers < a.Yaers)return true;
		if (Yaers == a.Yaers && Monthe < a.Monthe)return true;
		if (Yaers == a.Yaers && Monthe == a.Monthe && Day < a.Day)return true;

		return false;

	}
	clData operator=(const clData& a) {
		Day = a.Day;
		Monthe = a.Monthe;
		Yaers = a.Yaers;
		return *this;
	}
	bool operator==(const clData& a) {
		return (Day == a.Day && Monthe == a.Monthe && Yaers == a.Yaers);
	}
	bool operator!=(const clData& a) {
		return !(*this == a);
	}
	bool operator<=(const clData& a) {
		return (*this < a || *this == a);
	}
	bool operator>(const clData& a) {
		return !(*this <= a);
	}
	bool operator>=(const clData& a) {
		return !(*this < a);
	}
	
	clData &operator++() {
		*this = Increse_Day_By_One_Day(*this);
		return *this;
	}
	clData operator++(int) {
		clData Temp = *this;
		*this = Increse_Day_By_One_Day(*this);
		return Temp;
	}
	clData& operator--() {
		*this = Decreses_Day_one(*this);
		return *this;
	}
	clData operator--(int) {
		clData Temp = *this;
		*this = Decreses_Day_one(*this);
		return Temp;
	}



	void Data1_Equale_Data2(const clData& a) {
		if (*this < a) {
			cout << "Yes,The Data 1 Equale Data 2 \n";
		}
		else {
			cout << "No,The Data 1 n't Data 2 Equale \n  ";
		}
	}
 	bool Is_Last_Day_Monthe(const clData& Data) {
		return Data.Day == Number_of_Day_Monthe(Data.Yaers, Data.Day);

	}
  	 bool Is_Last_Monthe_Yesr(int M) {
		return M == 12;
	}

	clData Increse_Day_By_One_Day( clData &a) {
		if (Is_Last_Day_Monthe(a)) {
			if (Is_Last_Monthe_Yesr(a.Monthe)) {
				a.Day = 1;
				a.Monthe = 1;
				a.Yaers++;
			}
			else {
				a.Day = 1;
				a.Monthe++;
			}
		}
		else {
			a.Day++;
		}
		return a;
	}
 	int DiffinDay(const clData& b2, bool is = false) {
		int Tota = From_Day_Beging_of_Days(Day, Monthe, Yaers) - From_Day_Beging_of_Days(b2.Day, b2.Monthe, b2.Yaers);
		return (is) ? Tota + 1 : Tota;
	}
	void Print_My_Birthday(clData a) {
		cout << "My Brthday Days is " << From_Day_Beging_of_Days(a.Day, a.Monthe, a.Yaers) << endl;
	}
	int Double_the_DayDeffrence(const clData& a, const clData& b, bool is = false) {
		int Diff = From_Day_Beging_of_Days(b.Day, b.Monthe, b.Yaers) - From_Day_Beging_of_Days(a.Day, a.Monthe, a.Yaers);

		return (is) ? Diff + 1 : Diff;
	}
	void Print_Double_Day_Deffrence(const clData &a,const clData &b) {
		cout << "The Double Day Deffrence is : " << Double_the_DayDeffrence(a, b) << endl;
		cout << "The Double Day Deffrence (Including End Day ) is : " << Double_the_DayDeffrence(a, b, true) << endl;
	}

	clData& increse_Day_N(int a) {
	 
		for (int i = 0; i < a; i++)
		{
			*this = Increse_Day_By_One_Day(*this);
		}

		return *this;
	}
	clData& increse_one_Monthe() {
		if (Is_Last_Monthe_Yesr(Monthe)) {
			Monthe = 1;
			Yaers++;

		}
		else {
			Monthe++;
		}

		return *this;
	}

	clData& increse_one_Monthe_N(int N) {
 		for (int i = 0; i < N; i++)
		{
			*this=increse_one_Monthe();
		}


		return *this;
	}
	clData& increses_one_Week() {
		
		for (int i = 0; i < 7; i++)
		{
			*this = Increse_Day_By_One_Day(*this);
		}
		return *this;
	}
	clData& increses_one_Week_N(int N) {
		
		for (int i = 0; i < N; i++)
		{
			this->increses_one_Week();
		}
		return *this;
	}
	clData& increse_one_Year() {
		Yaers++;
		return *this;
	}
	clData& increse_one_Year_N(int N) {
		for (int i = 0; i < N; i++)
		{
			this->increse_one_Year();
		}
		return *this;
	}

	clData& increse_Decide() {
 
		for (int i = 0; i < 10; i++)
		{
			*this=increse_one_Year();
		}
		return *this;
	}
	clData& increse_Decide_N(int N) {
 		for (int i = 0; i < N; i++)
		{
			*this=increse_Decide();
		}
		return *this;
	}
	clData& increse_Decide_Fater(int N) {
		 
		this->Yaers += N * 10;
		return *this;
	}
	clData& increse_Century() {
		Yaers += 100;
		return *this;
	}
	clData& increse_Century_N(int N) {
		
		for (int i = 0; i < N; i++)
		{
		this->increse_Century();
		}
		return *this;
	}
	clData& increse_Millennium() {
		Yaers += 1000;
		return *this;
	}
	clData& increse_Millennium_N(int N) {
		for (int i = 0; i < N; i++)
		{
			this->increse_Millennium();
		}
		return *this;
	}
	clData Decreses_Day_one(clData a) {
		if (a.Day == 1) {
			if (a.Monthe == 1) {
				a.Monthe = 12;
				a.Yaers--;
			}
			else {
				a.Monthe--;

			}
			a.Day = Number_of_Day_Monthe(a.Yaers, a.Monthe);
		}
		else {
			a.Day--;
		}

		return a;
	}
	clData& Decreses_Day_N(int a) {
		  
		for (int i = 0; i < a; i++)
		{
			*this=Decreses_Day_one(*this);
		}
		return *this;
	}
	clData& Decres_Week_one() {
		 
		for (int i = 0; i < 7; i++)
		{
			*this= Decreses_Day_one(*this);
		}
		return *this;
	}
	clData& Decres_Week_N(int N) {
		for (int i = 0; i < N; i++)
		{
			this-> Decres_Week_one();
		}
		return *this;
	}
	clData& DecreseMonthe_one() {
		if (Monthe == 1) {
			Monthe = 12;
			Yaers--;
		}
		else {
			Monthe--;
		}

		return *this;
	}
	clData& DecreseMonthe_N(int N) {
		 
		for (int i = 0; i < N; i++)
		{
			*this=DecreseMonthe_one();
		}
		return *this;
	}
	clData& Decrese_Year_one() {
		Yaers--;
		return *this;
	}
	clData& Decrese_Year_N(int N) {
		for (int i = 0; i < N; i++)
		{
			this->Decrese_Year_one();
		}
		return *this;
	}
	clData& Decrseas_Decide() {
		Yaers -= 10;
		return *this;
	}
	clData& Decrseas_Decide_N(int N) {
 		for (int i = 0; i < N; i++)
		{
			*this=Decrseas_Decide();
		}
		return *this;
	}
	clData& Decreses_Decide_Fater(int a) {
 	this->Yaers -= a * 10;

		return *this;
	}
	clData& Decrese_Century() {
		Yaers -= 100;
		return *this;
	}
	clData& Decrese_Centry_N(int N) {
		
		for (int i = 0; i < N; i++)
		{
			*this=Decrese_Century();

		}
		return *this;
	}
	clData& Decrese_Millenium() {
		Yaers -= 1000;
		return *this;
	}
	clData& DecreseMillenum_N(int a) {
 		for (int i = 0; i < a; i++)
		{
			*this=Decrese_Millenium();
		}
		return *this;
	}
	short DayOfWeekOrder(clData a) {
		return DayOfWeekOrder(a.Day, a.Monthe, a.Yaers);
	}
	short Is_End_of_Week(clData a) {
		return DayOfWeekOrder(a) == 6;
	}
	bool Is_Weekend(clData a) {
		short Index = DayOfWeekOrder(a);
		return Index == 5 || Index == 6;
	}
	bool Is_Busnese_Day(clData a) {
		return !Is_Weekend(a);
	}
	short TheDay_Of_End(clData a) {
		return 6 - DayOfWeekOrder(a);
	}
	short The_Monthe_Is_End(clData a) {
		return Number_of_Day_Monthe(a.Yaers, a.Monthe) - a.Day;
	}
	short The_Yers_Is_End(clData a) {
		return Number_Of_DayinYear(a.Yaers) - From_Day_Beging_of_Days(a.Day, a.Monthe, a.Yaers);
	}

	void Print_The_Day_Monthe_Yers_End(clData a) {
		cout << "The Day of End in Week is : " << TheDay_Of_End(a) << endl;
		cout << "The Monthe of End in Yers is : " << The_Monthe_Is_End(a) << endl;
		cout << "The Yers of End in Century is : " << The_Yers_Is_End(a) << endl;
	}

	int CalucluterValdtionday(clData b) {
		int Number = 0;
		while ( *this<(b)) {
			if (Is_Busnese_Day(b)) {
				Number++;
			}
			b = Increse_Day_By_One_Day(b);
		}
		return Number;
	}
	bool Is_D1_After_D2(clData a) {
		return !(*this<a);
	}
	short Calculter_Number_one_Nagtive(clData a) {
		return ( *this<(a)) ? -1 : ( *this<(a) ? 1 : 0);

	}

	bool Is_Day1_Day2(clData b, clData a) {

		if (b.Yaers < a.Yaers)return true;
		if (b.Yaers == a.Yaers && b.Monthe < a.Monthe)return true;
		if (b.Yaers == a.Yaers && b.Monthe == a.Monthe && b.Day < a.Day)return true;

		return false;
	}
 	bool Is_Format(const clData& a1, const clData& a2, const clData& b1, const clData& b2) {
		bool a2_before_b1 = Is_Day1_Day2(a2, b1); // a2 < b1
		bool b2_before_a1 = Is_Day1_Day2(b2, a1); // b2 < a1

		return !(a2_before_b1 || b2_before_a1);
	}
	void Print_Is_Format(clData a1, clData a2, clData b1, clData b2) {
		if (Is_Format(a1, a2, b1, b2)) {
			cout << "Yes, The Two Format is Format \n";
		}
		else {
			cout << "No, The Two Format isn't Format \n ";
		}
	}
	void Print_Format_Alfark_Pereoud1(clData a1, clData a2) {
		cout << "Enter The Peroude one Please : " << endl;
		 

		cout << "The Peroud Lengthe is : " << Double_the_DayDeffrence(a1, a2) << endl;
		cout << "The Persoude Lengthe(Incloude Day ) is : " << Double_the_DayDeffrence(a1, a2, true) << endl;
	}

	bool Is_Day1_after_Day2(clData a, clData b, clData X) {
		bool x_after_a = Is_Day1_Day2(X, a);
		bool x_before_b = Is_Day1_Day2(b, X);
		return !(x_after_a || x_before_b);
	}
	void Print_Is_Day1_after_Day2(clData a, clData b, clData X) {
		if (Is_Day1_after_Day2(a, b, X)) {
			cout << "Yes, The Day is in The Pereoud \n";
		}
		else {
			cout << "No, The Day isn't in The Pereoud \n ";


		}

	}
	int overLeapPeroud(clData a1, clData a2, clData b1, clData b2) {
		int Count = 0;
		return (From_Day_Beging_of_Days(a2.Day, a2.Monthe, a2.Yaers) - From_Day_Beging_of_Days(b1.Day, b1.Monthe, b1.Yaers));
	}
 	bool Is_Valid_Date(clData a) {
		if (a.Day < 1 || a.Day>31)return false;
		if (a.Monthe < 1 || a.Monthe>12)return false;
		if (a.Monthe == 2) {
			if (Leap_Year(a.Yaers)) {
				if (a.Day > 29)return false;
			}
			else {
				if (a.Day > 28)return false;
			}
		}
		short Number_Day = Number_of_Day_Monthe(a.Yaers, a.Monthe);
		if (a.Day > Number_Day)return false;


		return true;
	}

	void Print_Is_Valid_Date(clData a) {
		if (Is_Valid_Date(a)) {
			cout << "Yes, The Data is Valid \n";
		}
		else {
			cout << "No, The Data isn't Valid \n ";
		}
	}
	string Data_To_string(clData a, string Sparetor = "/") {
		return to_string(a.Day) + Sparetor + to_string(a.Monthe) + Sparetor + to_string(a.Yaers);
	}
	static vector<string>Split_strintg(string s1, string Sparetor = "/") {
		string Word = "";
		size_t pos = 0;
		vector<string>VDAta;
		clData a;
		while ((pos = s1.find(Sparetor)) != string::npos) {
			Word = s1.substr(0, pos);

			if (Word != "")VDAta.push_back(Word);

			s1.erase(0, pos + Sparetor.length());
		}
		if (s1 != "")VDAta.push_back(s1);
;

		return VDAta;
	}

	clData String_To_Data(string S1, string Sparetor = "/") {
		vector<string>VData = Split_strintg(S1);
		clData a;
		if (VData.size() == 3) {
			a.Day = stoi(VData[0]);
			a.Monthe = stoi(VData[1]);
			a.Yaers = stoi(VData[2]);

		}

		return a;
	}
	void Print_string_Data(clData a) {
		cout << "The Day is : " << a.Day << endl;
		cout << "The Monthe is : " << a.Monthe << endl;
		cout << "The Yers is : " << a.Yaers << endl;

	}


	void Print_Data(string N) {
		cout << "Please Enter The Data in The Format dd/mm/yyyy : \n";
		cin >> N;

		clData a = String_To_Data(N);


		Print_string_Data(a);


		cout << "\n___________________________________________________________________\n";
		cout << "The Data is : " << Data_To_string(a) << endl;
		cout << "\n___________________________________________________________________\n";



	}

	string Replace_To_string(string s1, string ToRplace, string ReplaceWith) {
		short pos = s1.find(ToRplace);
		while (pos != string::npos) {
			s1 = s1.replace(pos, ToRplace.length(), ReplaceWith);
			pos = s1.find(ToRplace);


		}
		return s1;


	}

	string Format_Data(clData a, string Format_Data = "dd/mm/yyyy") {
		string F = Format_Data;
		F = Replace_To_string(F, "dd", to_string(a.Day));
		F = Replace_To_string(F, "mm", to_string(a.Monthe));
		F = Replace_To_string(F, "yyyy", to_string(a.Yaers));
		return F;
	}

public:
    // Add public getter for Monthe
    int GetMonth() const { return Monthe; }

friend clData Read_Data();
friend istream& operator>>(istream& in, clData& a);
friend ostream& operator<<(ostream& out, const clData& a);
 friend void DiffinKy(clData a);




  };
  istream&operator>>(istream&in,clData&a) {
	  cout << "Enter The Day Please : ";
	  in >> a.Day;
	  cout << "Enter The Monthe Please : ";
	  in >> a.Monthe;
	  cout << "Enter The Yaers Please : ";
	  in >> a.Yaers;
	  return in;
  }
  ostream& operator<<(ostream& out, const clData& a) {
	  	  out << a.Day << "/" << a.Monthe << "/" << a.Yaers;
		  return out;
  }



 
