#pragma once
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
class Clstring
{
private:
	string _Vlaue;
	char _Ch;
public:

	void Set_String(string Lin) {
		_Vlaue = Lin;
	}
	string Get_String() { return _Vlaue; }

	__declspec(property(get = Get_String, put = Set_String))string Value;

	void Set_char(char Lin) {
		_Ch = Lin;
	}
	char Get_Char() { return _Ch; }

	__declspec(property(get = Get_Char, put = Set_char))char Chr;



	static	short Continue_Words(string S1);
	static   void Print_First_Latter(string s);
	static   string Print_Fairst_Upper_Later(string S1);
	static   string Print_Fairst_Lower_Later(string S1);
	static string Print_All_Charcter_Lower_or_upper(string s1);
	static char invert_charcter_char(char a);
	static string inverst_All_string(string a);
	static void Conter_Small_Captel(string a);
	static short Conter_Charcter(string a, char c);
	static void Conter_Mache_Case_Or_Not(string a, char c);
	static string Is_Voile(char a);
	static bool Is_Voile_c(char c);
	static short Conter_Vole(string a);
	static void Print_All_Value_string(string a);
	static void Solite_String(string S1);
	static vector<string>Splite_String(string S1, string Dilmenter = " ");
	static string Trime_Left(string L1) {
		for (short i = 0; i < L1.length(); i++)
		{
			return L1.substr(i, L1.length() - i);

		}
		return "";
	}
	static string Trime_Rigth(string L1) {
		for (short i = L1.length(); i >= 0; i--)
		{
			if (L1[i] != ' ') {
				return L1.substr(0, i + 1);
			}
		}
		return "";
	}
	static string Trime(string L1) {
		return Trime_Left(Trime_Rigth(L1));
	}
	static string Joine_Splite(vector<string>Vp, string D = " ");
	static string Joine_Splite(string* arr, const short a = 0, string D = " ");
	static string Reversite_Word(string a);
	static string Replac_String(string a, string R, string Up);
	static string To_Lower_all(string a) {
		for (int i = 0; i < a.length(); i++)
		{
			a[i] = tolower(a[i]);
		}

		return a;
	}
	static string Repace_string(string Ma, string Re, string Up, bool is = true);
	static string Remove_Panction(string a);

};
string  Clstring::Remove_Panction(string a) {
	for (int i = 0; i < a.length(); i++)
	{
		if (ispunct(a[i])) {
			a[i] = '\0';
		}
	}

	return a;
}
short Clstring::Continue_Words(string S1) {
	short Conter = 0;
	size_t Pos = 0;
	string Sword;
	string Delminter = " ";
	while ((Pos = S1.find(Delminter)) != string::npos) {
		Sword = S1.substr(0, Pos);
		if (Sword != " ")Conter++;



		S1.erase(0, Pos + Delminter.length());

	}

	if (S1 != " ")Conter++;



	return Conter;
}
void Clstring::Print_First_Latter(string s1) {
	bool isFairst_Latter = true;

	cout << "\n The Latter of string is : \n";
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != ' ' && isFairst_Latter) {
			cout << s1[i] << endl;




		}
		isFairst_Latter = (s1[i] == ' ') ? true : false;
	}


}
string Clstring::Print_Fairst_Upper_Later(string S1) {
	bool isFir = true;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFir) {
			S1[i] = toupper(S1[i]);
		}
		isFir = (S1[i] == ' ') ? true : false;
	}


	return S1;

}
string Clstring::Print_Fairst_Lower_Later(string S1) {
	bool isFir = true;

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFir) {
			S1[i] = tolower(S1[i]);
		}
		isFir = (S1[i] == ' ') ? true : false;
	}


	return S1;

}
string Clstring::Print_All_Charcter_Lower_or_upper(string s1) {
	for (int i = 0; i < s1.length(); i++)
	{
		if (isupper(s1[i])) {
			s1[i] = tolower(s1[i]);

		}
		else if (islower(s1[i]))s1[i] = toupper(s1[i]);
	}

	return s1;
}
char Clstring::invert_charcter_char(char a) {

	return isupper(a) ? tolower(a) : toupper(a);


}
string Clstring::inverst_All_string(string a) {
	for (int i = 0; i < a.length(); i++)
	{
		a[i] = (isupper(a[i])) ? tolower(a[i]) : toupper(a[i]);
	}
	return a;


}
void Clstring::Conter_Small_Captel(string a) {
	short ConterAll = 0;
	short Small_Conter = 0;
	short Captile_Conter = 0;

	for (int i = 0; i < a.length(); i++)
	{
		ConterAll++;

		if (isupper(a[i]))Captile_Conter++;
		else if (islower(a[i]))Small_Conter++;


	}
	cout << "\n=========================================================\n";
	cout << "The Conter All Carecter it is  : " << ConterAll << endl;
	cout << "The Captale Conter is : " << Captile_Conter << endl;
	cout << "The Small Conter is : " << Small_Conter << endl;
	cout << "\n============================================================\n";
}
short Clstring::Conter_Charcter(string a, char c) {
	short Conter = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == c)Conter++;
	}

	return Conter;

}
void Clstring::Conter_Mache_Case_Or_Not(string a, char c) {
	short Casae = 0;
	short Not_Caase = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == c)Casae++;
		if (tolower(a[i]) == tolower(a[i]))Not_Caase++;

	}
	cout << "\n=============================================\n";
	cout << "The Case Crcter " << c << " is : " << Casae << endl;
	cout << "The Not Case Crecter " << c << " is : " << Not_Caase << endl;
	cout << "\n=================================================\n";

}
string Clstring::Is_Voile(char a) {
	return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ? "latter is Vowel \n" : "latter is Not Vouel ";

}
bool Clstring::Is_Voile_c(char a) {

	return (tolower(a) == 'a' || tolower(a) == 'e' ||
		tolower(a) == 'i' || tolower(a) == 'o' || tolower(a) == 'u') ? true : false;

}
short Clstring::Conter_Vole(string a) {
	short Conter = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (Is_Voile_c(a[i]))Conter++;
	}

	return Conter;

}
void Clstring::Print_All_Value_string(string a) {
	for (int i = 0; i < a.length(); i++)
	{
		if (Is_Voile_c(a[i])) {
			cout << a[i] << " ";
		}
	}
	cout << endl;



}
void Clstring::Solite_String(string S1) {
	size_t Pose = 0;
	string Word = "";
	string Deltrime = "";
	while ((Pose = S1.find(Deltrime)) != string::npos) {
		Word = S1.substr(0, Pose);
		if (Word != "") cout << Word << endl;


		S1.erase(0, Pose + Deltrime.length());
	}
	if (S1 != "") cout << S1 << endl;




}


//لا تنسى Token
vector<string>Clstring::Splite_String(string S1, string Dilmenter) {
	size_t Pose = 0;
	vector<string >P;
	string Word = "";
	string Deltrime = " ";
	while ((Pose = S1.find(Deltrime)) != string::npos) {
		Word = S1.substr(0, Pose);
		if (Word != "") P.push_back(Word);


		S1.erase(0, Pose + Deltrime.length());
	}
	if (S1 != " ") P.push_back(S1);



	return P;
}

string Clstring::Joine_Splite(vector<string>Vp, string Delimeter) {
	string S1 = " ";
	for (auto& a : Vp) {
		S1 += a + Delimeter;
	}
	return S1.substr(0, S1.length() - Delimeter.length());




}

string Clstring::Joine_Splite(string* arr, const short n, string D) {
	string S = " ";
	for (int i = 0; i < n; i++)
	{
		S += arr[i] + D;
	}
	return S.substr(0, S.length() - D.length());
}


string Clstring::Reversite_Word(string a) {
	vector<string>VString;
	string a2;
	VString = Splite_String(a, " ");

	vector<string>::iterator iter = VString.end();

	while (iter != VString.begin()) {
		--iter;
		a2 += *iter + " ";
	}
	a2 = a2.substr(0, a2.length() - 1);
	return a2;
}

string Clstring::Replac_String(string a, string R, string Up) {
	short Pos = a.find(R);
	while (Pos != std::string::npos) {
		a = a.replace(Pos, R.length(), Up);

		Pos = a.find(R);

	}
	return a;
}

string Clstring::Repace_string(string Ma, string Re, string Up, bool is) {

	vector<string>Sp = Splite_String(Ma);
	for (auto& C : Sp) {
		if (is) {
			if (C == Re) {
				C = Up;
			}
		}
		else {
			if (To_Lower_all(C) == To_Lower_all(Re))C = Up;

		}





	}


	return Joine_Splite(Sp);



}
