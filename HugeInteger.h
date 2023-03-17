#pragma once
#include<iostream>
using namespace std;
class HugeInteger {
private:
	char* data;
	int size;
public:
	HugeInteger();
	HugeInteger(int size);
	HugeInteger(const HugeInteger& innt);
	HugeInteger setsize(int size);
	HugeInteger setdata(int siz);
	void Set_Size();
	friend istream & operator >> (istream& in, HugeInteger& innt);
	friend ostream & operator <<(ostream& out, const HugeInteger& innt);
	friend bool operator ==(const HugeInteger& innt1, const HugeInteger& innt2);
    friend bool operator !=(const HugeInteger& innt1, const HugeInteger& innt2);
	friend bool operator <(const HugeInteger& innt1, const HugeInteger& innt2);
	friend bool operator >(const HugeInteger& innt1, const HugeInteger& innt2);
	friend bool operator <=(const HugeInteger& innt1, const HugeInteger& innt2);
	friend bool operator >=(const HugeInteger& innt1, const HugeInteger& innt2);
    friend HugeInteger operator +( HugeInteger& innt1, HugeInteger& innt2);
	friend HugeInteger operator -(HugeInteger& innt1, HugeInteger& innt2);
	friend HugeInteger operator *(HugeInteger& innt1, HugeInteger& innt2);
};
