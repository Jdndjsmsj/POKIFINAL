#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct Pokemon {
	string name;
	string type;
	int no;
	int hlt = 0;
	int atk = 0;
	int def = 0;
	int spdef = 0;
	int spatk = 0;
	int spd = 0; // Added Speed stat
	int bs = 0;

};

void preloadDatabase(vector<Pokemon>& poki) {
	poki = {
		// Name, Type, No, HP, Atk, Def, SpDef, SpAtk, Speed, Total
		{"Bulbasaur", "Grass", 1, 45, 49, 49, 65, 65, 45, 318},
		{"Ivysaur", "Grass", 2, 60, 62, 63, 80, 80, 60, 405},
		{"Venusaur", "Grass", 3, 80, 82, 83, 100, 100, 80, 525},
		{"Charmander", "Fire", 4, 39, 52, 43, 50, 60, 65, 309},
		{"Charmeleon", "Fire", 5, 58, 64, 58, 65, 80, 80, 405},
		{"Charizard", "Fire", 6, 78, 84, 78, 85, 109, 100, 534},
		{"Squirtle", "Water", 7, 44, 48, 65, 64, 50, 43, 314},
		{"Wartortle", "Water", 8, 59, 63, 80, 80, 65, 58, 405},
		{"Blastoise", "Water", 9, 79, 83, 100, 105, 85, 78, 530},
		{"Pikachu", "Electric", 25, 35, 55, 40, 50, 50, 90, 320},
		{"Raichu", "Electric", 26, 60, 90, 55, 80, 90, 110, 485},
		{"Geodude", "Rock", 74, 40, 80, 100, 30, 30, 20, 300},
		{"Graveler", "Rock", 75, 55, 95, 115, 45, 45, 35, 390},
		{"Golem", "Rock", 76, 80, 120, 130, 65, 55, 45, 495},
		{"Gastly", "Ghost", 92, 30, 35, 30, 35, 100, 80, 310},
		{"Haunter", "Ghost", 93, 45, 50, 45, 55, 115, 95, 405},
		{"Gengar", "Ghost", 94, 60, 65, 60, 75, 130, 110, 500},
		{"Mewtwo", "Psychic", 150, 106, 110, 90, 90, 154, 130, 680},
		{"Mew", "Psychic", 151, 100, 100, 100, 100, 100, 100, 600},
		{"Dragonite", "Dragon", 149, 91, 134, 95, 100, 100, 80, 600}
	};
}

void displayPoki(const vector<Pokemon>& poki) {
	if (poki.empty()) { cout << "No Pokémon found!\n"; return; }
	for (const Pokemon& s : poki) {
		cout << "#" << s.no << " " << s.name << " (" << s.type << ")" << endl;
	}
}

void displayStats(const vector<Pokemon>& poki) {
	string d;
	cout << "Enter Pokemon Name:" << endl;
	cin >> d;
	bool found = false;
	for (size_t i = 0; i < poki.size(); i++) {
		if (poki[i].name == d) {
			cout << "\n--- STATS FOR " << poki[i].name << " ---" << endl;
			cout << "Health: " << poki[i].hlt << endl;
			cout << "Attack: " << poki[i].atk << endl;
			cout << "Defense: " << poki[i].def << endl;
			cout << "Special Attack: " << poki[i].spatk << endl;
			cout << "Special Defense: " << poki[i].spdef << endl;
			cout << "Speed: " << poki[i].spd << endl; // Added output for Speed
			cout << "Base Stat Total: " << poki[i].bs << endl;
			found = true;
		}
	}
	if (!found) cout << "Pokemon not found!\n";
}

void sortPokihlt(vector<Pokemon>& poki) {
	if (poki.empty()) { cout << "No Pokémon to sort!\n"; return; }
	sort(poki.begin(), poki.end(), [](const Pokemon& a, const Pokemon& b) { return a.hlt < b.hlt; });
	cout << "Sorting by Health Complete!\n";
}

void delepoki(vector<Pokemon>& poki) {
	string p;
	cout << "Enter Pokemon Name to remove:" << endl;
	cin >> p;
	bool removed = false;
	for (int i = poki.size() - 1; i >= 0; i--) {
		if (poki[i].name == p) {
			poki.erase(poki.begin() + i);
			cout << "Pokemon Removed\n";
			removed = true;
		}
	}
	if (!removed) cout << "Pokemon not found!\n";
}

void displaypokitype(const vector<Pokemon>& poki) {
	string f;
	cout << "Enter Pokemon Type:" << endl;
	cin >> f;
	for (char& c : f) c = ::tolower((unsigned char)c);

	bool found = false;
	for (size_t z = 0; z < poki.size(); z++) {
		string t = poki[z].type;
		for (char& c : t) c = tolower((unsigned char)c);

		if (t == f) {
			cout << "#" << poki[z].no << " " << poki[z].name << endl;
			found = true;
		}
	}
	if (!found) cout << "No Pokémon found with that type.\n";
}

void strongestpoki(vector<Pokemon>& poki) {
	if (poki.empty()) { cout << "No Pokémon in party!\n"; return; }
	sort(poki.begin(), poki.end(), [](const Pokemon& a, const Pokemon& b) { return a.bs < b.bs; });
	int k = poki.size() - 1;
	cout << "Strongest Pokemon is: " << poki[k].name << " with Base Stat of: " << poki[k].bs << endl;
}

void strongestpokibystat(vector<Pokemon>& poki) {
	if (poki.empty()) { cout << "No Pokémon in party!\n"; return; }
	int n;
	cout << "Choose Your Stat (1.ATK, 2.HEALTH, 3.DEFENSE, 4.SPEED):" << endl;
	cin >> n;
	switch (n) {
	case 1:
		sort(poki.begin(), poki.end(), [](const Pokemon& a, const Pokemon& b) { return a.atk > b.atk; });
		cout << "Highest Attack is of: " << poki[0].name << " (" << poki[0].atk << ")" << endl;
		break;
	case 2:
		sort(poki.begin(), poki.end(), [](const Pokemon& a, const Pokemon& b) { return a.hlt > b.hlt; });
		cout << "Highest Health is of: " << poki[0].name << " (" << poki[0].hlt << ")" << endl;
		break;
	case 3:
		sort(poki.begin(), poki.end(), [](const Pokemon& a, const Pokemon& b) { return a.def > b.def; });
		cout << "Highest Defense is of: " << poki[0].name << " (" << poki[0].def << ")" << endl;
		break;
	case 4: // Added case for Speed
		sort(poki.begin(), poki.end(), [](const Pokemon& a, const Pokemon& b) { return a.spd > b.spd; });
		cout << "Highest Speed is of: " << poki[0].name << " (" << poki[0].spd << ")" << endl;
		break;
	default:
		cout << "INVALID STAT" << endl;
	}
}
pair<int, int> battle(vector <Pokemon>& poki) {
	string l, a;
	cout << "First Player: Choose Your Pokemon:" << endl;
	cin >> l;
	cout << "Second Player: Choose Your Pokemon:" << endl;
	cin >> a;

	// Convert input names to lowercase to make checking foolproof
	for (char& c : l) c = ::tolower((unsigned char)c);
	for (char& c : a) c = ::tolower((unsigned char)c);

	int h1 = 0, h2 = 0, a1 = 0, a2 = 0, s1 = 0, s2 = 0;
	bool found1 = false, found2 = false;
	string realName1, realName2;

	// Dynamic lower-case verification check loops
	for (int i = 0; i < poki.size(); i++) {
		string dbName = poki[i].name;
		for (char& c : dbName) c = ::tolower((unsigned char)c);

		if (dbName == l) {
			h1 = poki[i].hlt;
			a1 = poki[i].atk;
			s1 = poki[i].spd;
			realName1 = poki[i].name;
			found1 = true;
		}
	}

	for (int z = 0; z < poki.size(); z++) {
		string dbName = poki[z].name;
		for (char& c : dbName) c = ::tolower((unsigned char)c);

		if (dbName == a) {
			h2 = poki[z].hlt;
			a2 = poki[z].atk;
			s2 = poki[z].spd;
			realName2 = poki[z].name;
			found2 = true;
		}
	}

	// Safety check now stops execution instead of running with zero stats
	if (!found1 || !found2) {
		cout << "\n❌ ERROR: One or both Pokemon names do not exist! Check your spelling." << endl;
		return{ 0,0 };
	}

	cout << "\n--- BATTLE START: " << realName1 << " VS " << realName2 << " ---" << endl;

	while (h1 > 0 && h2 > 0) {
		if (s1 >= s2) {
			cout << realName1 << " Attacks First!" << endl;
			h2 = h2 - a1;
			if (h2 <= 0) break;
			h1 = h1 - a2;
		}
		else {
			cout << realName2 << " Attacks First!" << endl;
			h1 = h1 - a2;
			if (h1 <= 0) break;
			h2 = h2 - a1;
		}
	}
	int w1 = 0;
	int w2 = 0;

	if (h1 > 0) {
		cout << " Winner: " << realName1 << "!" << endl;
		w1++;
	}
	else {
		cout << " Winner: " << realName2 << "!" << endl;
		w2++;
	}
	return { w1, w2 };
}
void leaderboard(int m, int n) {


	if (m > n) {
		cout << "1.Player1" << "WINS:" << m << endl;
		cout << "2.Player2" << "WINS:" << n << endl;
	}
	else {
		cout << "1.Player2" << "WINS:" << n << endl;
	}cout << "2.Player1" << "WINS:" << m << endl;


}

int main() {
	vector<Pokemon> x;
	preloadDatabase(x);
	int u = 0;
	int v = 0;
	int choice;
	while (true) {
		cout << "\n=== POKEMON DATABASE (PRELOADED) ===" << endl;
		cout << "1. DISPLAY ALL POKEMONS" << endl;
		cout << "2. DISPLAY POKEMON STATS" << endl;
		cout << "3. REMOVE POKEMON FROM DB" << endl;
		cout << "4. SORT DB BY HEALTH" << endl;
		cout << "5. FILTER BY TYPE" << endl;
		cout << "6. OVERALL STRONGEST POKEMON" << endl;
		cout << "7. HIGHEST INDIVIDUAL STAT" << endl;
		cout << "8.BATTLE" << endl;
		cout << "9.LEADERBOARD" << endl;
		cout << "10. EXIT" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: displayPoki(x); break;
		case 2: displayStats(x); break;
		case 3: delepoki(x); break;
		case 4: sortPokihlt(x); break;
		case 5: displaypokitype(x); break;
		case 6: strongestpoki(x); break;
		case 7: strongestpokibystat(x); break;
		case 8:
		{
			pair<int, int> t = battle(x);
			u += t.first;
			v += t.second;
		}
		break;
		case 9:leaderboard(u, v); break;
		default: return 0;
		}
	}
}
