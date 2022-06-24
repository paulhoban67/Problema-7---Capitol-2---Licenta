// Programul de mai jos, citeste un string si afiseaza stringul codificat astfel:
// fiecarei litere i se stribuie urmatoarea litera, iar la z sau Z se atribuie a sau A
// ana -> bob
// aza -> bab
// gift -> hjgu

#include <cctype>
#include <string>
#include <iostream>
using namespace std;

char UrmL(char l) {
	switch (l) {
	case 'Z':
		return 'A';
	case 'z':
		return 'a';
	default:
		return l + 1;
	}
}

char Decod(char l) { // functia inversa = decodificare
	switch (l) {
	case 'A':
		return 'Z';
	case 'a':
		return 'z';
	default:
		return l - 1;
	}
}

char ModC(char c) {
	if (std::isalpha(c))
		return UrmL(c);
	else
		return c;
}

char ModCDecod(char c) { // functia inversa = decodificare
	if (std::isalpha(c))
		return Decod(c);
	else
		return c;
}

std::string Modif(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = ModC(s[i]);
	}
	return s;
}

std::string Decod(std::string s) { // functia inversa = decodificare
	for (int i = 0; i < s.length(); i++) {
		s[i] = ModCDecod(s[i]);
	}
	return s;
}

int main() {
	std::string s;
	do {
		cin >> s;
		cout << Modif(s) << endl;

		// Decodificarea
		cout << Modif(s) << " decodificat = " << Decod(Modif(s)) << endl;
	} while (s != "stop");
	return 0;
}