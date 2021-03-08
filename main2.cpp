#include <iostream>
#include <fstream>

using namespace std;

class file {
		
		public:
		ifstream plik1;
 		ofstream plik2;
 		
 		string picture;
 		string s;
		
		void plik();
		int max = 0;
		void szukaj();
		void max2(int x);
};

void file::szukaj() {
	int biale = 0;
	int czarne = 0;
	int rewers = 0;
	plik1.open("dane_obrazki.txt");
 	plik2.open("wyjscie.txt");
	
	while(!plik1.eof()){
		
		plik1>>s;
		if (s.length() == 21) {
			for( int i = 0; i < s.length()-1; i++ ) {
				picture += s[i];
			}
		}
		else {
			for( int i = 0; i < picture.length(); i++ ) {
				if (picture[i] == '0') {
					biale++;
				}
			}
			
			czarne = picture.length() - biale;
			
			max2(czarne);
			
			if (czarne > biale) {
				rewers++;
			}	
			
			picture = "";
			biale = 0;
		}
	}
	cout<<"Ilosc: "<<rewers<<endl;
	cout<<"Najwieksza ilosc czarnych pikseli: "<<max;
}

void file::max2(int x) {
	if (x > max) {
		max = x;
	}
}

int main(int argc, char** argv) {
	file f;
	f.szukaj();
	return 0;
}
