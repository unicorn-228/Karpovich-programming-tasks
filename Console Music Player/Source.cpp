#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
//программа позволяет записать маленькую мелодию по одной ноте в удар метронома

enum noteName {A  ,B , C , D , G , E , F , Ad, Bd, Cd, Dd, Gd, Ed, Fd};

struct note {
	int pos;
	noteName name;
	int length;
	bool isPause = false;
	note() :length(1) {};
	~note() {};
};

class mySmallMIDI {
	int length;
	vector<note> data;
	int bpm = 220;
	string songname;
public :
	mySmallMIDI();
	mySmallMIDI(const mySmallMIDI& a);
	~mySmallMIDI() {};
	note& operator [] (int n);
	mySmallMIDI operator + (mySmallMIDI& a);
	void operator += (mySmallMIDI& a);
	void play();
	void loadFromFile(string filename);
	friend ifstream& operator >> (ifstream& file, mySmallMIDI& a);
	friend ofstream& operator << (ofstream& file, mySmallMIDI a);
	int getLength();
	string getSongname();
};
int mySmallMIDI::getLength() {
	return length;
}
string mySmallMIDI::getSongname() {
	return songname;
}
mySmallMIDI::mySmallMIDI(const mySmallMIDI& a) {
	length = a.length;
	data = a.data;
	bpm = a.bpm;
	songname = a.songname;
}
ofstream& operator << (ofstream& file, mySmallMIDI a) {
	file << a.songname << endl;
	file << a.bpm << endl;
	for (int i = 0; i < a.length; i++) {
		file << a.data[i].pos << " ";
		if (a.data[i].name == A)
			file << "A";
		if (a.data[i].name == B)
			file << "B";
		if (a.data[i].name == C)
			file << "C";
		if (a.data[i].name == D)
			file << "D";
		if (a.data[i].name == E)
			file << "E";
		if (a.data[i].name == F)
			file << "F";
		if (a.data[i].name == G)
			file << "G";

		if (a.data[i].name == Ad)
			file << "Ad";
		if (a.data[i].name == Bd)
			file << "Bd";
		if (a.data[i].name == Cd)
			file << "Cd";
		if (a.data[i].name == Dd)
			file << "Dd";
		if (a.data[i].name == Ed)
			file << "Ed";
		if (a.data[i].name == Fd)
			file << "Fd";
		if (a.data[i].name == Gd)
			file << "Gd";
		file << " ";
		file << a.data[i].length << endl;
	}
	return file;
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

ifstream& operator >> (ifstream& file, mySmallMIDI& a) {
	a.length = 0;
	file >> a.songname;
	file >> a.bpm;
	while (!file.eof()) {
		note temp;
		file >> temp.pos;
		string tempname;
		file >> tempname;
		if (tempname == "p") {
			temp.isPause = true;
		}
		else {
			file >> temp.length;

			if (tempname == "A")
				temp.name = A;
			if (tempname == "B")
				temp.name = B;
			if (tempname == "C")
				temp.name = C;
			if (tempname == "D")
				temp.name = D;
			if (tempname == "E")
				temp.name = E;
			if (tempname == "F")
				temp.name = F;
			if (tempname == "G")
				temp.name = G;

			if (tempname == "Ad")
				temp.name = Ad;
			if (tempname == "Bd")
				temp.name = Bd;
			if (tempname == "Cd")
				temp.name = Cd;
			if (tempname == "Dd")
				temp.name = Dd;
			if (tempname == "Ed")
				temp.name = Ed;
			if (tempname == "Fd")
				temp.name = Fd;
			if (tempname == "Gd")
				temp.name = Gd;
		}
		a.data.push_back(temp);
		a.length++;
	}
	return file;
}

void mySmallMIDI::operator+= (mySmallMIDI& a) {
	for (int i = 0; i < a.length; i++) {
		data.push_back(a.data[i]);
		length++;
	}
	songname += "+" + a.songname;
}
mySmallMIDI mySmallMIDI::operator+ (mySmallMIDI &a) {
	mySmallMIDI result;
	result.length = 0;
	for (int i = 0; i < length; i++) {
		result.data.push_back(data[i]);
		result.length++;
	}
	for (int i = 0; i < a.length; i++) {
		result.data.push_back(a.data[i]);
		result.length++;
	}
	
	result.songname = songname + "+" + a.songname;
	return result;
}
void mySmallMIDI::loadFromFile(string filename) {
	fstream file;
	file.open(filename, ios::in);
	length = 0;
	file >> songname;
	file >> bpm;
	while (!file.eof()) {
		note temp;
		file >> temp.pos;
		string tempname;
		file >> tempname;
		if (tempname == "p") {
			temp.isPause = true;
		}
		else {
			file >> temp.length;

			if (tempname == "A")
				temp.name = A;
			if (tempname == "B")
				temp.name = B;
			if (tempname == "C")
				temp.name = C;
			if (tempname == "D")
				temp.name = D;
			if (tempname == "E")
				temp.name = E;
			if (tempname == "F")
				temp.name = F;
			if (tempname == "G")
				temp.name = G;

			if (tempname == "Ad")
				temp.name = Ad;
			if (tempname == "Bd")
				temp.name = Bd;
			if (tempname == "Cd")
				temp.name = Cd;
			if (tempname == "Dd")
				temp.name = Dd;
			if (tempname == "Ed")
				temp.name = Ed;
			if (tempname == "Fd")
				temp.name = Fd;
			if (tempname == "Gd")
				temp.name = Gd;
		}
		data.push_back(temp);
		length++;
	}
}

void outString(string toout) {
	for (int i = 0; i < toout.length(); i++) {
		cout << toout[i];
		Sleep(50);
	}
}

void mySmallMIDI::play() {
	cout << endl << endl;
	string toout =  "сейчас играет : " ;
	outString(toout);
	toout = "--------" + songname + "--------";
	cout << endl;
	outString(toout);
	cout << endl << endl;
	Sleep(1000);
	SetColor(10, 0);
	for (int i = 0; i < length; i++) {
		note now = data[i];
		if (now.isPause == true) {
			Sleep(60000 / bpm);
			cout << "- ";
			continue;
		}
		if (now.name == A)
			cout << "A";
		if (now.name == B)
			cout << "B";
		if (now.name == C)
			cout << "C";
		if (now.name == D)
			cout << "D";
		if (now.name == E)
			cout << "E";
		if (now.name == F)
			cout << "F";
		if (now.name == G)
			cout << "G";
		if (now.name == Ad)
			cout << "A#";
		if (now.name == Bd)
			cout << "B#";
		if (now.name == Cd)
			cout << "C#";
		if (now.name == Dd)
			cout << "D#";
		if (now.name == Ed)
			cout << "E#";
		if (now.name == Fd)
			cout << "F#";
		if (now.name == Gd)
			cout << "G#";
		cout << now.pos << " ";
		int freq = 0;
		if (now.pos == 1) {
			switch (now.name) {
			case C:
				freq = 261;
				break;
			case Cd:
				freq = 277;
				break;
			case D:
				freq = 293;
				break;
			case Dd:
				freq = 311;
				break;
			case E:
				freq = 329;
				break;
			case F:
				freq = 349;
				break;
			case Fd:
				freq = 369;
				break;
			case G:
				freq = 392;
				break;
			case Gd:
				freq = 415;
				break;
			case A:
				freq = 440;
				break;
			case Ad:
				freq = 466;
				break;
			case B:
				freq = 493;
				break;
			}
		}
		if (now.pos == 2) {
			switch (now.name) {
			case C:
				freq = 523;
				break;
			case Cd:
				freq = 554;
				break;
			case D:
				freq = 587;
				break;
			case Dd:
				freq = 622;
				break;
			case E:
				freq = 659;
				break;
			case F:
				freq = 698;
				break;
			case Fd:
				freq = 739;
				break;
			case G:
				freq = 783;
				break;
			case Gd:
				freq = 830;
				break;
			case A:
				freq = 880;
				break;
			case Ad:
				freq = 932;
				break;
			case B:
				freq = 987;
				break;
			}
		}
		if (now.pos == 3) {
			switch (now.name) {
			case C:
				freq = 1046;
				break;
			case Cd:
				freq = 1108;
				break;
			case D:
				freq = 1174;
				break;
			case Dd:
				freq = 1244;
				break;
			case E:
				freq = 1318;
				break;
			case F:
				freq = 1396;
				break;
			case Fd:
				freq = 1480;
				break;
			case G:
				freq = 1568;
				break;
			case Gd:
				freq = 1661;
				break;
			case A:
				freq = 1760;
				break;
			case Ad:
				freq = 1864;
				break;
			case B:
				freq = 1975;
				break;
			}
		}
		if (now.pos == 4) {
			switch (now.name) {
			case C:
				freq = 2093;
				break;
			case Cd:
				freq = 2217;
				break;
			case D:
				freq = 2349;
				break;
			case Dd:
				freq = 2489;
				break;
			case E:
				freq = 2637;
				break;
			case F:
				freq = 2793;
				break;
			case Fd:
				freq = 2960;
				break;
			case G:
				freq = 3136;
				break;
			case Gd:
				freq = 3322;
				break;
			case A:
				freq = 3520;
				break;
			case Ad:
				freq = 3729;
				break;
			case B:
				freq = 3951;
				break;
			}
		}
		if (now.pos == 5) {
			switch (now.name) {
			case C:
				freq = 4186;
				break;
			case Cd:
				freq = 4434;
				break;
			case D:
				freq = 4698;
				break;
			case Dd:
				freq = 4978;
				break;
			case E:
				freq = 5274;
				break;
			case F:
				freq = 5587;
				break;
			case Fd:
				freq = 5919;
				break;
			case G:
				freq = 6271;
				break;
			case Gd:
				freq = 6644;
				break;
			case A:
				freq = 7040;
				break;
			case Ad:
				freq = 7458;
				break;
			case B:
				freq = 7902;
				break;
			}
		}
		Beep(freq, now.length *60000 / bpm);
	}
}


mySmallMIDI::mySmallMIDI() {
	length = 0;
}

note& mySmallMIDI::operator[] (int n) {
	if (n < length) {
		return data[n];
	}
}




int main() {
	SetColor(5, 0);
	setlocale(LC_ALL, ".1251");
	string toout = "------------------    FLEX SYTHESIZER 0.0001 ALPHA   ------------------";
	outString(toout);
	cout << endl;
	Sleep(100);
	cout << "программа считывает два midi (моего формата) файла, соеденяет их и выводит один общий файл (обхединение первых двух)" << endl;
	Sleep(2000);
	cout << "5";
	for (int i = 0; i < 1000; i += 200) { cout << "."; Sleep(100); }
	cout << "4";
	for (int i = 0; i < 1000; i += 200) { cout << "."; Sleep(100); }
	cout << "3";
	for (int i = 0; i < 1000; i += 200) { cout << "."; Sleep(100); }
	cout << "2";
	for (int i = 0; i < 1000; i += 200) { cout << "."; Sleep(100); }
	cout << "1";
	for (int i = 0; i < 1000; i += 200) { cout << "."; Sleep(100); }
	cout << endl;
	mySmallMIDI midi1;
	mySmallMIDI midi2;
	midi1.loadFromFile("john cena.mymid");
	ifstream file("C.mymid");
	file >> midi2;
	midi2 += midi1;
	ofstream output("file1 + file2 .mymid");
	output << midi2;
	SetColor(12, 0);
	midi2.play();
	
	cout << endl;
	system("pause");
	return 0;
}