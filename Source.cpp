#include<iostream>
#include<string>
#include"HugeInteger.h"
using namespace std;

int main()
{
	HugeInteger h1;
	cin >> h1;
	cout << h1;
	cout << endl;
	HugeInteger h2;
	cin >> h2;
	cout << h2;
	cout << endl;

	//h1 == h2
	if (h1 == h2)
	{
		cout << "h1 == h2 " << "Yes!" << endl;
	}
	else
	{
		cout << "h1 == h2 " << "No!" << endl;
	}

	//h1 != h2
	if (h1 != h2)
	{
		cout << "h1 != h2 " << "Yes!" << endl;
	}
	else
	{
		cout << "h1 != h2 " << "No!" << endl;
	}

	//h1 < h2
	if (h1 < h2)
	{
		cout << "h1 < h2 " << "Yes!" << endl;
	}
	else
	{
		cout << "h1 < h2 " << "No!" << endl;
	}

	//h1 > h2
	if (h1 > h2)
	{
		cout << "h1 > h2 " << "Yes!" << endl;
	}
	else
	{
		cout << "h1 > h2 " << "No!" << endl;
	}

	//h1 <= h2
	if (h1 <= h2)
	{
		cout << "h1 <= h2 " << "Yes!" << endl;
	}
	else
	{
		cout << "h1 <= h2 " << "No!" << endl;
	}

	//h1 >= h2
	if (h1 >= h2)
	{
		cout << "h1 => h2 " << "Yes!" << endl;
	}
	else
	{
		cout << "h1 => h2 " << "No!" << endl;
	}

	 //h3=h1+h2
	cout << "Sum of  two huge integers is : ";
	HugeInteger h3 = h1 + h2;
	cout << h3;
	cout << endl;

	 //h4=h1-h2
	cout << "Difference of  two huge integers is :";
	HugeInteger h4 = h1 - h2;
	cout << h4;
	cout << endl;

	cout << "Product of two huge integers is : ";
	HugeInteger h5 = (h1 * h2);
	cout << h5;
	cout << endl;

	system("pause");
	return 0;

}
