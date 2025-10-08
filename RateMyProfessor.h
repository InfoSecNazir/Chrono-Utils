#pragma once
 #pragma warning(disable : 4996)
#include<iostream>
#include<string>
 #include "Clstring.h"
class Data
{private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;
public:
	Data() {
		time_t t = time(0);   // get time now
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}
	Data(string Data) {
		vector<string>v = Clstring::Splite_String(Data, "/");
		 
	 
			if (v.size() != 3) { /* Handle error */ return; }
			try {
				_Day = stoi(v[0]);
				_Month = stoi(v[1]);
				_Year = stoi(v[2]);
			}
			catch (const std::invalid_argument& e) {
				 
				_Day = 1; _Month = 1; _Year = 1900;
			
		}
	}
	Data(short d, short m, short y) {
		_Day = d;
		_Month = m;
		_Year = y;
	}
	Data(short DataOrderInear, short Year) {
		Data a = GetDateFromDayOrderInYear(DataOrderInear, Year);
		_Day = a._Day;
		_Month = a._Month;
		_Year = a._Year;


	}
	void SetDay(short d) {
		_Day = d;
	}
	short GetDay() const{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;
	void SetMonthe(short m) {
		_Month = m;
	}
	short GetMonthe()const {
		return _Month;
	}
	__declspec(property(get = GetMonthe, put = SetMonthe)) short Monthe;
	void SetYear(short y) {
		_Year = y;
	}
	short GetYear()const {
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	string Date_To_string() {
		return to_string(_Day) + "/" + to_string(_Month) + "/" + to_string(_Year);
	}
	void Print() {
		cout << Date_To_string() << endl;
	}

	static Data GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Yers;
		Yers = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return Data(Day, Month, Yers);
	}


 static	bool Is_Valid_Date(Data a) {
		if (a._Day < 1 || a._Day>31)return false;
		if (a._Month < 1 || a._Month>12)return false;
		if (a._Month == 2) {
			if (Leap_Year(a._Year)) {
				if (a.Day > 29)return false;
			}
			else {
				if (a.Day > 28)return false;
			}
		}
		short Number_Day = Number_of_Day_Monthe(a._Year, a._Month);
		if (a._Day > Number_Day)return false;


		return true;
	}
 bool Isvaldtion() {
		return Is_Valid_Date(*this);
 }
	  
static  string Date_To_string(Data a) {
	 return to_string(a._Day) + "/" + to_string(a._Month) + "/" + to_string(a._Year);
 }
 string Data_to_string() {
	 return Date_To_string(*this);
 }



static bool Leap_Year(int Year)  {
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
bool Is_Leap_Year()const {
		return Leap_Year(_Year);
}


static	short Number_Of_DayinYear(int Year) {
	return Leap_Year(Year) ? 366 : 365;
}
short Number_of_Day_in_Year() {
	return Number_Of_DayinYear(_Year);
}

static	short Number_Of_hOur_in_Year(short Year) {
	return Number_Of_DayinYear(Year) * 24;
}
short Number_of_Hour_in_Year() {
	return Number_Of_hOur_in_Year(_Year);
}

static	short NumberOfMomentinYeaer(int Yaer) {
	return Number_Of_DayinYear(Yaer) * 60;
}
short Number_of_Moment_in_Year() {
	return NumberOfMomentinYeaer(_Year);
}

static	int Number_Of_Secode_in_Year(int Year) {
	return Number_Of_hOur_in_Year(Year) * 60;
}
int Number_of_Secode_in_Year() {
	return Number_Of_Secode_in_Year(_Year);
}
 
static	short Number_of_Hour_Monthe(int Y, int M) {
	return Number_of_Day_Monthe(Y, M) * 24;
}
short Number_of_Hour_Monthe() {
	return Number_of_Hour_Monthe(_Year, _Month);
}

static	short Number_of_Moment_Monthe(int Y, int M) {
	return Number_of_Hour_Monthe(Y, M) * 60;
}
short Number_of_Moment_Monthe() {
	return Number_of_Moment_Monthe(_Year, _Month);
}

static	short Number_of_Secode_Monthe(int Y, int M) {
	return Number_of_Moment_Monthe(Y, M) * 60;
}
short Number_of_Secode_Monthe() {
	return Number_of_Secode_Monthe(_Year, _Month);
}
static int DaysFromTheBeginingOfTheYear(int Day, int Monthe, int Yers) {
	int Total_Day = 0;
	for (int i = 1; i < Monthe; i++)
	{
		Total_Day += Number_of_Day_Monthe(Yers, i);
	}

	Total_Day += Day;

	return Total_Day;
}
int DaysFromTheBeginingOfTheYear(){
	return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
}




static	short Number_of_Day_Monthe(int Year, int Monthe) {
		if (Monthe < 1 || Monthe>12)return 0;
		return (Monthe == 2) ? Leap_Year(Year) ? 29 : 28 : (Monthe == 4 || Monthe == 6 || Monthe == 9 || Monthe == 11) ? 30 : 31;
	}
short Number_of_Day_Monthe() {
		return Number_of_Day_Monthe(_Year, _Month);
}

  static Data GetDateFromDayOrderInYear(int Total_Day, int Y) {
		
		Data a;
		while (Total_Day > Number_of_Day_Monthe(Y, a._Month)) {
			Total_Day -= Number_of_Day_Monthe(Y, a._Month);
			a._Month++;
			if (a._Month > 12) {
				a._Month = 1;
				Y++;
			}
		}
		a._Day = Total_Day;

		return a;

	}
	Data GetDateFromDayOrderInYear(int Total_Day) {
		return GetDateFromDayOrderInYear(Total_Day, _Year);
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
	short DayOfWeekOrder() const {
	return 	DayOfWeekOrder(_Day, _Month, _Year);
	}
	
	static	string Day_Of_Name(short Day) {
		string arrName[] = { "San","Man","Teu","Wed","Thu","Fri","Sat" };
		return arrName[Day];
	}
	string Day_Of_Week() {
		return Day_Of_Name(DayOfWeekOrder(_Day, _Month, _Year));
	}

	static string Monthe_of_Name(short Num) {
		string arrMonthe[] = { "Jan","Fab","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arrMonthe[Num - 1];
	}	
	string Monthe_of_Name() {
		return Monthe_of_Name(_Month);
	}


 static	void Print_Clenader_Monthe(int M, int Y) {
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
		}
			for (int j = 1; j <= NUM_Of_Day; j++)
			{
				printf("%5d", j);

				if (++i == 7) {
					i = 0;
					printf("\n");
				}


			

		     }
		printf("\n____________________________________________________\n");

	}
 void Print_Clenader_Monthe() {
		Print_Clenader_Monthe(_Month, _Year);
 }


 static	void Print_Clender_of_Year(int Y) {
		for (int i = 1; i <= 12; i++)
		{
			Print_Clenader_Monthe(i, Y);
			cout << "\n";
		}

	}
 void Print_Clender_of_Year() {
		Print_Clender_of_Year(_Year);
}


   void Add_Day(short Day) {
	 short Remining_Day = Day +  DaysFromTheBeginingOfTheYear(_Day,_Month,_Year);
	 int Month = 0;
	 _Month = 1;
 	 while (true) {
		 Month = Number_of_Day_Monthe(_Year, _Month);
		 if (Remining_Day > Month) {
			 Remining_Day -= Month;
			 _Month++;
			 if (_Month > 12) {
				 _Month = 1;
				 _Year++;
		      }
		 }
		 else {
			 _Day = Remining_Day;
			 break;
		 }

	 }

  }



 static bool IsDate1BeforeDate2(Data a, Data b) {
	 if (a._Year < b._Year)return true;
	 if (a._Year == b._Year && a._Month < b._Month)return true;
	 if (a._Year == b._Year && a._Month == b._Month && a._Day < b._Day)return true;
	 return false;
 }
 bool IsDate1BeforeDate2(Data b) {
	 return IsDate1BeforeDate2(*this, b);
 }

   static bool IsLastDayInMonth( Data a) {
	   return (a.Day == Number_of_Day_Monthe(a.Year, a.Monthe));
    }
   bool IsLastDayInMonth() {
   
	   return IsLastDayInMonth(*this);
   
   }
   static bool IsLastMonthInYear(int a) {
	   return (a == 12);
   }
  
   static Data AddOneDay(Data a) {
	   if (IsLastDayInMonth(a))
	   {
		   if (IsLastMonthInYear(a.Monthe)) {
			   a.Day = 1;
			   a.Monthe = 1;
			   a.Year++;




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
   void AddOneDay() {
	   *this = AddOneDay(*this);
   }
   static void Swap_Data(Data& a, Data& b) {
	   Data Temp = a;
	   a = b;
	   b = Temp;
   }
   static int GetDifferainceDays(Data a, Data b, bool IncludeEndDay = false) {
	   int Days = 0;
	   short Swap = 1;
	   if (!IsDate1BeforeDate2(a, b)) {
		   Swap_Data(a, b);
		   Swap = -1;

	   }
	   while(IsDate1BeforeDate2(a,b)) {
		   Days++;
		   a = AddOneDay(a);

	   }
	   return IncludeEndDay ? ++Days * Swap : Days * Swap;
   }
   int GetDifferainceDays(Data b, bool IncludeEndDay = false) {
	   return GetDifferainceDays(*this, b, IncludeEndDay);
   }
   static short Calculter_MyDays(Data a) {
	   return GetDifferainceDays(a, Data::GetSystemDate(), true);
   }
   short Calculter_MyDays() {
	   return Calculter_MyDays(*this);
   }
   static Data IncreaseDataByOneWeek(Data a) {


	   for (int i = 0; i <7 ; i++)
	   {
		   a = AddOneDay(a);
	   }
	   return a;
   }
   void IncreaseDataByOneWeek() {
	   *this = IncreaseDataByOneWeek(*this);
   }
   static Data IncreaseDataBy_X_Week(short Week, Data& a) {
	   for (int i = 0; i < Week; i++)
	   {
		   a = AddOneDay(a);
	   }return a;
   }
   void IncreaseDataBy_X_Week(short Week) {
	   *this = IncreaseDataBy_X_Week(Week, *this);
   }
  static  Data IncreaseDataByOneMonthe(Data& a) {
	   if (a.Monthe == 12) {
		   a.Monthe = 1;
		   a.Year++;
	   }
	   else {
		   a.Monthe++;

	   }


	   short NumDay = Number_of_Day_Monthe(a.Year, a.Monthe);

	   if (a.Day > NumDay) a.Day = NumDay;

	   return a;
   }
   void IncreaseDataByOneMonthe() {
	   *this = IncreaseDataByOneMonthe(*this);
   }
   static Data IncreaseDataBy_X_Monthe(short Monthe, Data& a) {
	   for (int i = 0; i < Monthe; i++)
	   {
		   a = IncreaseDataByOneMonthe(a);
	   }return a;
   }
   void IncreaseDataBy_X_Monthe(short Monthe) {
	   *this = IncreaseDataBy_X_Monthe(Monthe, *this);
   }
   static  Data IncreaseDateByOneYear(Data& a) {
	   a.Year++;
	   return a;
   }
   void IncreaseDateByOneYear() {
	   *this = IncreaseDateByOneYear(*this);
   }
    Data IncreaseDateBy_X_Year(short Year,Data& a) {
   
	   a.Year += Year;
	   return a;
   }
   void IncreaseDateBy_x_Year(short a) {
	   IncreaseDateBy_X_Year(a,*this );
   }
   Data IncreaseDateByOneDecade(Data& a) {
	   	   a.Year += 10;
		   return a;
   }
   void IncreaseDateByOneDecade() {
	   *this = IncreaseDateByOneDecade(*this);
   }
   Data IncreaseDateByXDecades(short Decid, Data& a) {
	   a.Year += Decid * 10;
	   return a;
   }
   void IncreaseDateByXDecades(short Decid) {
	   *this = IncreaseDateByXDecades(Decid, *this);
   }
   Data IncreaseDateByOneCentury(Data& a) {
	   a.Year += 100;
	   return a;
   }
   void IncreaseDateByOneCentury() {
	   *this = IncreaseDateByOneCentury(*this);
   }
   Data IncreaseDateByXCentury(short Cent, Data& a) {
	   a.Year += Cent * 100;
	   return a;
   }
   void IncreaseDateByXCentury(short Cent) {
	   *this = IncreaseDateByXCentury(Cent, *this);
   }
   Data IncreaseDateByOneMillennium(Data& a) {
	   a.Year += 1000;
	   return a;
   }
   void IncreaseDateByOneMillennium() {
	   *this = IncreaseDateByOneMillennium(*this);
   }
   static Data DecreaseDateByOneDay(Data &a){
	   if (a.Day == 1) {
		   if (a.Monthe == 1) {
			   a.Monthe = 12;
			   a.Year--;
			   a.Day = 31;

		   }
		   else
		   {
			   a.Monthe--;
			   a.Day = Number_of_Day_Monthe(a.Year, a.Monthe);
		   }

	   
	   
	   }
	   else {
		   a.Day--;
	   }
	   return a;
   }
   void DecreaseDateByOneDay() {
	   *this = DecreaseDateByOneDay(*this);
   }
   static Data DecreaseDateBy_X_Day(short Day, Data& a) {
	   for (int i = 0; i < Day; i++)
	   {
		   a = DecreaseDateByOneDay(a);
	   }return a;
   }
   void DecreaseDateBy_X_Day(short Day) {
	   *this = DecreaseDateBy_X_Day(Day, *this);
   }
   static Data DecreaseDateByOneWeek(Data& a) {
	   for (int i = 0; i < 7; i++)
	   {
		   a = DecreaseDateByOneDay(a);
	   }return a;
   }
   void DecreaseDateByOneWeek() {
	   *this = DecreaseDateByOneWeek(*this);
   }
   static Data DecreaseDateBy_X_Week(short Week, Data& a) {
	   for (int i = 0; i < Week; i++)
	   {
		   a = DecreaseDateByOneWeek(a);
	   }return a;
   }
   void DecreaseDateBy_X_Week(short Week) {
	   *this = DecreaseDateBy_X_Week(Week, *this);
   }
   static Data DecreaseDateByOneMonthe(Data& a) {
	   if (a.Monthe == 1) {
		   a.Monthe = 12;
		   a.Year--;
	   }
	   else {
		   a.Monthe--;
	   }
	   short NumDay = Number_of_Day_Monthe(a.Year, a.Monthe);
if(a.Day>NumDay)a.Day=NumDay;
return a;

   }
   void DecreaseDateByOneMonthe() {
	   *this = DecreaseDateByOneMonthe(*this);
   }
   static Data DecreaseDateBy_X_Monthe(short Monthe, Data& a) {
	   for (int i = 0; i < Monthe; i++)
	   {
		   a = DecreaseDateByOneMonthe(a);
	   }return a;
   }
   void DecreaseDateBy_X_Monthe(short Monthe) {
	   *this = DecreaseDateBy_X_Monthe(Monthe, *this);
   }
   static Data DecreaseDateByOneYear(Data& a) {
	   a.Year--;
	   return a;
   }
   void DecreaseDateByOneYear() {
	   *this = DecreaseDateByOneYear(*this);
   }	
   static Data DecreaseDateBy_X_Year(short Year, Data& a) {
	   a.Year -= Year;
	   return a;
   }
   void DecreaseDateBy_X_Year(short Year) {
	   *this = DecreaseDateBy_X_Year(Year, *this);
   }
   static Data DecreaseDateByOneDecade(Data& a) {
	   a.Year -= 10;
	   return a;
   }			
   void DecreaseDateByOneDecade() {
	   *this = DecreaseDateByOneDecade(*this);
   }
   static Data DecreaseDateByXDecades(short Decid, Data& a) {
	   a.Year -= Decid * 10;
	   return a;
   }
   void DecreaseDateByXDecades(short Decid) {
	   *this = DecreaseDateByXDecades(Decid, *this);
   }
   static Data DecreaseDateByOneCentury(Data& a) {
	   a.Year -= 100;
	   return a;
   }
   void DecreaseDateByOneCentury() {
	   *this = DecreaseDateByOneCentury(*this);
   }
   static Data DecreaseDateByXCentury(short Cent, Data& a) {
	   a.Year -= Cent * 100;
	   return a;
   }
   void DecreaseDateByXCentury(short Cent) {
	   *this = DecreaseDateByXCentury(Cent, *this);
   }
   static Data DecreaseDateByOneMillennium(Data& a) {
	   a.Year -= 1000;
	   return a;
   }
   void DecreaseDateByOneMillennium() {
	   *this = DecreaseDateByOneMillennium(*this);
   }
   static short IsEndofWeek(Data a){
	   return DayOfWeekOrder(a.Day, a.Monthe, a.Year) == 6;
   }
   short IsEndofWeek() {
	   return IsEndofWeek(*this);

   }

   static bool IsWeekend(Data D) {
	   short Num = DayOfWeekOrder(D.Day, D.Monthe, D.Year);

	   return (Num == 5 || Num == 6);

   }
   bool IsWeekend() {
	   return IsWeekend(*this);
   }
   static bool IsBusnesDay(Data a) {
	   return !IsWeekend(a);
   }
   bool IsBusnesDay() {
	   return IsBusnesDay(*this);
   }
   static short DaysUnteWeekEnd(Data a){
	   return 6 - DayOfWeekOrder(a.Day, a.Monthe, a.Year);
   }
   short DaysUnteWeekEnd() {
	   return DaysUnteWeekEnd(*this);
   }
   static short DaysUntilTheEndOfMonth(Data a) {
	   Data End;
	   End.Day = Number_of_Day_Monthe(a.Year, a.Monthe);
	   End.Monthe = a.Monthe;
	   End.Year = a.Year;
	   return GetDifferainceDays(a, End, true);
   }
   short DaysUntilTheEndOfMonth() {

	   return DaysUntilTheEndOfMonth(*this);
   }
   static short DaysUntilTheEndOfYear(Data a){
   
	   Data End;
	   End.Day = 31;
	   End.Monthe = 12;
	   End.Year = a.Year;
	   return GetDifferainceDays(a, End, true);
   }
   short DaysUntilTheEndOfYear() {
	   return DaysUntilTheEndOfYear(*this);
   }
   static short CalculateBusinessDays(Data From, Data To) {
	   short Days = 0;
	   while(IsDate1BeforeDate2(From, To)) {
		   if (IsBusnesDay(From)) {
			   Days++;
			   From = AddOneDay(From);
		   }

	   }
	   return Days;
	   }
   short CalculateBusinessDays(Data a) {
	   return CalculateBusinessDays(*this,a);
   }
	static short CalculateVacationDays(Data a,Data b){
		return CalculateBusinessDays(a, b);
	}
	static Data CalculateVacationReturnDate(Data From,short a) {
		short Weekend = 0;
		for (int i = 0; i <= a; i++)
		{
			if (IsWeekend(From)) { Weekend++;
			From = AddOneDay(From);
			}

		}

		for (int i = 0; i < Weekend; i++)
		{
			From = AddOneDay(From);
		}
		return From;
	}

	Data  CalculateVacationReturnDate(short a) {
		return CalculateVacationReturnDate(*this, a);
	}
	static bool IsDate1EqualDate2(Data Date1, Data Date2)
	{
		if (Date1.Year != Date2.Year)
			return false;

		if (Date1.Monthe != Date2.Monthe)
			return false;

		if (Date1.Day != Date2.Day)
			return false;

		return true;
	}

	static bool IsDate1AfterDate2(Data a, Data b) {
		return (!IsDate1BeforeDate2(a, b)&&!IsDate1EqualDate2(a,b));
	}
	bool IsDate1AfterDate2(Data b) {
		return IsDate1AfterDate2(*this, b);
	}
	enum enDateCompare{ Before = -1, Equal = 0, After = 1 };
	static enDateCompare CompercData(Data a, Data b) {

		if (IsDate1BeforeDate2(a, b))return enDateCompare::Before;
		if (IsDate1EqualDate2(a, b))return enDateCompare::Equal;
		if (IsDate1AfterDate2(a, b))return enDateCompare::After;

     }
	enDateCompare CompercData(Data a2) {
		return CompercData(*this, a2);
	}


};

