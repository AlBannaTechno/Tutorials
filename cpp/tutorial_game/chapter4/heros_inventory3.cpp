// Hero's Inventory 3.0
// Demonstrates iterators

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> inventory;
	inventory.push_back("Sword");
	inventory.push_back("Armor");
	inventory.push_back("Shield");

	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;

	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nYou trade your sword for a battle axe";
	myIterator = inventory.begin();
	*myIterator = "Battle Axe";
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nThe item name '" << *myIterator << "' has " << (*myIterator).size();
	cout << " letters in it.\n";
	
	cout << "\nThe item name '" << *myIterator << "' has " << myIterator->size();
	cout << " letters in it.\n";

	cout << "\nYou recover a crossbow from a slain enemy.";
	inventory.insert(inventory.begin(), "Crossbow");
	cout << "\nYour items:";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nYour armor is destroyed in a fierce battle.";
	inventory.erase((inventory.begin() + 2));
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	return 0;
}