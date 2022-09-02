#include "map.hpp"
#include <iostream>

int main(void) {
	ft::map<int, std::string> mp;

	mp[42] = "lol";

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

    std::cout << "-----------------------------------------\n";
    mp.erase(25); // right != NULL; left != NULL OK
	mp.erase(55); // right != NULL; left != NULL OK
    mp.erase(24); // right != NULL; left != NULL Ok
	mp.erase(54); // right != NULL; left != NULL OK
    mp.erase(22); // right != NULL; left != NULL OK
	mp.erase(51); // right != NULL; left != NULL OK
    mp.erase(21); // right != NULL; left != NULL OK
	mp.erase(53); // right != NULL; left != NULL OK
	mp.erase(20); // OK leaf
	mp.erase(23); // OK leaf
	mp.erase(42); // OK Two
	mp.erase(38); // OK leaf
	mp.erase(35); // OK One
	mp.erase(33); // OK leaf

    mp.preorder_traversal(mp.get_root());
}