#include"HugeInteger.h"
#include<iostream>
using namespace std;
HugeInteger::HugeInteger()//default constructor
{
	data = nullptr;
	size = 0;
}

HugeInteger::HugeInteger(int size)//parameterized constructor
{
	this->size = size;
	data = new char[size];
}

HugeInteger::HugeInteger(const HugeInteger& innt)//copy constructor
{
	data = innt.data;
	size = innt.size;
}

HugeInteger HugeInteger::setsize(int siz)
{
	HugeInteger t(siz);
	for (int i = 0; i < siz; i++)
		t.data[i] = '\0';
	return t;
}

void HugeInteger::Set_Size()
{
	int s = 0;
	int i = 0;
	while (data[i] >= 48 && data[i] <= 57)
	{
			s++;	
			i++;
	}
	size = s;
}

HugeInteger HugeInteger::setdata(int siz)
{
	size = siz;
	HugeInteger t(siz);
	for (int i = 0; i < siz; i++)
		t.data[i] = '0';
	return t;
}

istream & operator >> (istream& in, HugeInteger& innt)//for taking input into huge-int
 {
	 char temp[1000];
	 cout << "Enter HugeInt  ";
	 in.getline(temp,1000);
	 int len = strlen(temp);
	 bool part = false, bool2 = true;
	 int len1 = 0, len2 = 0, j = 0;
	 for (int i = 0; i < len; i++)
	 {
		 if (temp[i] == 48)
		 {
			 while (temp[i] == 48 && part == false)
			 {
				 i++;
				 len1++;
			 }
		 }
		 if (bool2 == true)
		 {
			 len2 = (len - len1) + 1;
			 innt.data = new char[len2];
			 part = true;
		 }
		 bool2 = false;
		 innt.data[j] = temp[i];
		 j++;
	 }
	 innt.size = j;
	 return in;
 }

ostream& operator <<(ostream& out, const HugeInteger& innt)//to display huge-int
 {
	bool zero = true;
	 for (int i = 0; i < innt.size; i++)
	 {
		 if (innt.data[i] < 48 || innt.data[i]>57)
		 {
		 }
		 else
		 {
			 if (zero == true)
			 {
				 while (innt.data[i] == '0')
				 {
					 i++;
				 }
				 zero = false;
			 }
			 out << innt.data[i];
		 }
	 }
	 return out;
 }

 bool operator ==(const HugeInteger& innt1, const HugeInteger& innt2)//for h1==h2
 {
	 bool isequal = false;
	 if (innt1.size == innt2.size)
		 isequal = true;
	 if (isequal == true)
	 {
		 for (int i = 0; i < innt1.size;i++)
		 {
			 if (innt1.data[i] == innt2.data[i] && isequal == true)
			 {
				 isequal = true;
			 }
			 else
			 {
				 isequal = false;
			 }
		 }
	 }
	 return isequal;
 }

 bool operator !=(const HugeInteger& innt1, const HugeInteger& innt2) //for h1!=h2
 {
	 bool notequal = false;
	 if (innt1.size != innt2.size)
		 notequal = true;
	 else
	 {
		 for (int i = 0; i < innt1.size; i++)
		 {
			 if (notequal == false)
			 {
				 if (innt1.data[i] == innt2.data[i] && notequal == false)
				 {
				 }
				 else
				 {
					 notequal = true;
				 }
			 }
		 }
	 }
	 if (notequal == true)
		 return true;
	 else
		 return false;
 }

 bool operator <(const HugeInteger& innt1, const HugeInteger& innt2)//for h1<h2
 {
	 bool condition = true,islesser=true;
	 if (innt1.size < innt2.size)
		 islesser = true;
	 else if (innt1.size > innt2.size)
		 islesser = false;
	 else
	 {
		 for (int i = 0; i < innt1.size; i++)
		 {
			 if (innt1.data[i] == innt2.data[i] && condition == true)
			 {

			 }
			 else if (innt1.data[i] < innt2.data[i] && condition == true)
			 {
				 islesser = true;
				 condition= false;
			 }
			 else if (innt1.data[i] > innt2.data[i] && condition == true)
			 {
				 islesser = false;
				 condition = false;
			 }
		 }
		 if (condition == true)
		 {

			 for (int i = 0; i < innt1.size; i++)
			 {
				 if (innt1.data[i] == innt2.data[i])
				 {
					 islesser = false;
				 }
			 }
		 }
	 }
	 return islesser;
 }

 bool operator >(const HugeInteger& innt1, const HugeInteger& innt2)//for h1>h2
 {
	 bool condition = true, isgreater = true;
	 if (innt1.size > innt2.size)
		 isgreater = true;
	 else if (innt1.size < innt2.size)
		 isgreater = false;
	 else
	 {
		 for (int i = 0; i < innt1.size; i++)
		 {
			 if (innt1.data[i] == innt2.data[i] && condition == true)
			 {

			 }
			 else if (innt1.data[i] > innt2.data[i] && condition == true)
			 {
				 isgreater = true;
				 condition = false;
			 }
			 else if (innt1.data[i] < innt2.data[i] && condition == true)
			 {
				 isgreater = false;
				 condition = false;
			 }
		 }
		 if (condition == true)
		 {

			 for (int i = 0; i < innt1.size; i++)
			 {
				 if (innt1.data[i] == innt2.data[i])
				 {
					 isgreater = false;
				 }
			 }
		 }
	 }
	 return isgreater;
 }

 bool operator <=(const HugeInteger& innt1, const HugeInteger& innt2)
 {
	 bool condition = true, islesser = true;
	 if (innt1.size < innt2.size)
		 islesser = true;
	 else if (innt1.size > innt2.size)
		 islesser = false;
	 else
	 {
		 for (int i = 0; i < innt1.size; i++)
		 {
			 if (innt1.data[i] == innt2.data[i] && condition == true)
			 {

			 }
			 else if (innt1.data[i] < innt2.data[i] && condition == true)
			 {
				 islesser = true;
				 condition = false;
			 }
			 else if (innt1.data[i] > innt2.data[i] && condition == true)
			 {
				 islesser = false;
				 condition = false;
			 }
		 }
		 if (condition == true)
		 {

			 for (int i = 0; i < innt1.size; i++)
			 {
				 if (innt1.data[i] == innt2.data[i])
				 {
					 islesser = true;
				 }
			 }
		 }
	 }
	 return islesser;
 }

 bool operator >=(const HugeInteger& innt1, const HugeInteger& innt2)
 {
	 bool condition = true, isgreater = true;
	 if (innt1.size > innt2.size)
		 isgreater = true;
	 else if (innt1.size < innt2.size)
		 isgreater = false;
	 else
	 {
		 for (int i = 0; i < innt1.size; i++)
		 {
			 if (innt1.data[i] == innt2.data[i] && condition == true)
			 {

			 }
			 else if (innt1.data[i] > innt2.data[i] && condition == true)
			 {
				 isgreater = true;
				 condition = false;
			 }
			 else if (innt1.data[i] < innt2.data[i] && condition == true)
			 {
				 isgreater = false;
				 condition = false;
			 }
		 }
		 if (condition == true)
		 {

			 for (int i = 0; i < innt1.size; i++)
			 {
				 if (innt1.data[i] == innt2.data[i])
				 {
					 isgreater = true;
				 }
			 }
		 }
	 }
	 return isgreater;
 }

 HugeInteger operator +( HugeInteger& innt1, HugeInteger& innt2)
 {
	 
	 if (innt1.size > innt2.size)
	 {
		 int x = 0, y = 0, carry = 0, count = 0, size = 0;
		 char temp[1000];
		 size = innt1.size;
		 temp[innt1.size] = '\0';
		 x = innt2.size - 1, y = innt1.size - 1;
		 
		 for (int i = x,j=y; i >=0; i--,j--)
		 {
			 int num1 = 0, num2 = 0;
			 num1 = innt1.data[j] - 48;
			 num2 = innt2.data[i] - 48;
			 int sum = num1 + num2 + carry;
			 if (sum > 9)
			 {
				 int s = sum % 10;
				 sum = sum / 10;
				 carry = sum % 10;
				 char t = s+48 ;
				 temp[size] = t;
				 size--;
				 count++;
			 }
			 else
			 {
				 char t = sum+48;
				 temp[size] = t;
				 size--;
				 count++;
				 carry = 0;
			 }
			 if (i == 0)
			 {
				 j--;
				 while (j >= -1)
				 {
					 num1 = innt1.data[j] - 48;
					 sum = num1 + carry;
					 if (sum > 9)
					 {
						 int s = sum % 10;
						 sum = sum / 10;
						 carry = sum % 10;
						 char t = s + 48;
						 temp[size] = t;
						 size--;
						 count++;
						 if (j == 0 && carry != 0)
						 {
							 char c = carry + 48;
							 temp[size] = c;
							 carry = 0;
							 size--;
							 count++;
							 j--;
						 }
						 j--;
					 }
					 else
					 {
						 char t = sum + 48;
						 temp[size] = t;
						 size--;
						 count++;
						 carry = 0;
						 j--;
					 }
				 }
			 }
		 }
		 HugeInteger tem(count+1);
		 {
			 tem.data[count + 1] = '\0';
			 for (int i =0,j=0; i <= count; i++,j++)
			 {
				 if (temp[i] < 48 || temp[i]>57)
				 {
					 j--;
				 }
				 else
				 {
					 tem.data[j] = temp[i];
				 }
				 
			 }
		 }
		 return tem;
	 }

	 if (innt1.size < innt2.size)
	 {
		 int x = 0, y = 0, carry = 0, count = 0, size = 0;
		 char temp[1000];
		 size = innt2.size;
		 temp[innt2.size] = '\0';
		 x = innt1.size - 1, y = innt2.size - 1;
		 for (int i = x, j = y; i >= 0; i--, j--)
		 {
			 int  num1 = innt2.data[j] - 48;
			 int num2 = innt1.data[i] - 48;
			 int sum = num1 + num2 + carry;
			 if (sum > 9)
			 {
				 int s = sum % 10;
				 sum = sum / 10;
				 carry = sum % 10;
				 char t = s + 48;
				 temp[size] = t;
				 size--;
				 count++;
			 }
			 else
			 {
				 char t = sum + 48;
				 temp[size] = t;
				 size--;
				 count++;
				 carry = 0;
			 }
			 if (i == 0)
			 {

				 j--;
				 while (j >= -1)
				 {
					 num1 = innt2.data[j] - 48;
					 sum = num1 + carry;
					 if (sum > 9)
					 {
						 int s = sum % 10;
						 sum = sum / 10;
						 carry = sum % 10;
						 char t = s + 48;
						 temp[size] = t;
						 size--;
						 count++;
						 if (j == 0 && carry != 0)
						 {
							 char c = carry + 48;
							 temp[size] = c;
							 carry = 0;
							 size--;
							 count++;
							 j--;
						 }
						 j--;
					 }
					 else
					 {
						 char t = sum + 48;
						 temp[size] = t;
						 size--;
						 count++;
						 carry = 0;
						 j--;
					 }
					
				 }
			 }

		 }
		 HugeInteger tem(count + 1);
		 {
			 tem.data[count + 1] = '\0';
			 for (int i = 0, j = 0; i <= count; i++, j++)
			 {
				 if (temp[i] < 48 || temp[i]>57)
				 {
					 j--;
				 }
				 else
				 {
					 tem.data[j] = temp[i];
				 }

			 }
		 }
		 return tem;
	 }

	 if (innt1.size == innt2.size)
	 {
		 int count = 0, size = innt1.size;
		 char temp[1000];
		 temp[innt1.size+1] = '\0';
		 int carry = 0;
		 for (int i = (innt2.size - 1), j = (innt1.size - 1); i >= 0; i--, j--)
		 {

			 int num1 = innt1.data[j] - 48;
			 int num2 = innt2.data[i] - 48;
			 int sum = num1 + num2 + carry;
			 if (sum > 9)
			 {
				 int s = sum % 10;
				 sum = sum / 10;
				 carry = sum % 10;
				 char t = s + 48;
				 temp[size] = t;
				 size--;
				 count++;
			 }
			 else
			 {
				 char t = sum + 48;
				 temp[size] = t;
				 size--;
				 count++;
				 carry = 0;
			 }
			 if (i == 0 && carry != 0)
			 {
				 while (j > -1)
				 {
					 sum = 0 + carry;
					 int s = sum % 10;
					 sum = sum / 10;
					 carry = sum % 10;
					 char t = s + 48;
					 temp[size] = t;
					 size--;
					 count++;
					 j--;
					 carry = 0;
				 }
			 }
		 }
		 HugeInteger tem(count + 1);
		 {
			 tem.data[count + 1] = '\0';
			 for (int i = 0, j = 0; i <= count; i++, j++)
			 {
				 if (temp[i] < 48 || temp[i]>57)
				 {
					 j--;
				 }
				 else
				 {
					 tem.data[j] = temp[i];
				 }

			 }
		 }
		 return tem;
	 }
	 
 }

 HugeInteger operator -(HugeInteger& innt1, HugeInteger& innt2)
 {

	 if (innt1.size > innt2.size)
	 {
		 int count = 0, size = innt1.size;
		 char temp[1000];
		 temp[innt1.size] = '\0';
		 for (int i = (innt2.size - 1), j = (innt1.size - 1); i >= 0; i--, j--)
		 {

			 int num1 = innt1.data[j] - 48;
			 int num2 = innt2.data[i] - 48;
			 int sub =0;
			 if (num1<num2)
			 {
				 num1 = num1 + 10;
				 sub = num1 - num2;
				 innt1.data[j - 1] = innt1.data[j - 1] - 1;
				 char t = sub + 48;
				 temp[size] = t;
				 size--;
				 count++;
			 }
			 else if (num1 >= num2)
			 {
				 sub = num1 - num2;
				 char t = sub + 48;
				 temp[size] = t;
				 size--;
				 count++;
			 }
			 if (i == 0)
			 {
				 j--;
				 while (j != -1)
				 {
					 num1 = innt1.data[j] - 48;
					 char t = num1 + 48;
					 temp[size] = t;
					 size--;
					 count++;
					 j--;
				 }
			 }
		 }
		 HugeInteger tem(count + 1);
		 {
			 tem.data[count + 1] = '\0';
			 for (int i = 0, j = 0; i <= count; i++, j++)
			 {
				 if (temp[i] < 48 || temp[i]>57)
				 {
					 j--;
				 }
				 else
				 {
					 tem.data[j] = temp[i];
				 }

			 }
		 }
		 return tem;
	 }

	 if (innt1.size < innt2.size)
	 {
		 int count = 0, size = innt2.size;
		 char temp[1000];
		 temp[innt2.size] = '\0';
		 for (int i = (innt1.size - 1), j = (innt2.size - 1); i >= 0; i--, j--)
		 {

			 int num1 = innt2.data[j] - 48;
			 int num2 = innt1.data[i] - 48;
			 int sub = 0;
			 if (num1 < num2)
			 {
				 num1 = num1 + 10;
				 sub = num1 - num2;
				 innt2.data[j - 1] = innt2.data[j - 1] - 1;
				 char t = sub + 48;
				 temp[size] = t;
				 size--;
				 count++;
			 }
			 else if (num1 >= num2)
			 {
				 sub = num1 - num2;
				 char t = sub + 48;
				 temp[size] = t;
				 size--;
				 count++;
			 }
			 if (i == 0)
			 {
				 j--;
				 while (j != -1)
				 {
					 num1 = innt2.data[j] - 48;
					 char t = num1 + 48;
					 temp[size] = t;
					 size--;
					 count++;
					 j--;
				 }
			 }
		 }
		 HugeInteger tem(count + 1);
		 {
			 tem.data[count + 1] = '\0';
			 for (int i = 0, j = 0; i <= count; i++, j++)
			 {
				 if (temp[i] < 48 || temp[i]>57)
				 {
					 j--;
				 }
				 else
				 {
					 tem.data[j] = temp[i];
				 }

			 }
		 }
		 return tem;
	 }

	 if (innt1.size == innt2.size)
	 {
		 bool g = innt1 > innt2;
		 if (g == true)
		 {
			 int count = 0, size = innt1.size;
			 char temp[1000];
			 temp[innt1.size] = '\0';
			 for (int i = (innt2.size - 1), j = (innt1.size - 1); i >= 0; i--, j--)
			 {

				 int num1 = innt1.data[j] - 48;
				 int num2 = innt2.data[i] - 48;
				 int sub = 0;
				 if (num1 < num2)
				 {
					 num1 = num1 + 10;
					 sub = num1 - num2;
					 innt1.data[j - 1] = innt1.data[j - 1] - 1;
					 char t = sub + 48;
					 temp[size] = t;
					 size--;
					 count++;
				 }
				 else if (num1 >= num2)
				 {
					 sub = num1 - num2;
					 char t = sub + 48;
					 temp[size] = t;
					 size--;
					 count++;
				 }
			 }
			 HugeInteger tem(count + 1);
			 {
				 tem.data[count + 1] = '\0';
				 for (int i = 0, j = 0; i <= count; i++, j++)
				 {
					 if (temp[i] < 48 || temp[i]>57)
					 {
						 j--;
					 }
					 else
					 {
						 tem.data[j] = temp[i];
					 }

				 }
			 }
			 return tem;
		 }
		 else
		 {
			 int count = 0, size = innt2.size;
			 char temp[1000];
			 temp[innt2.size] = '\0';
			 for (int i = (innt1.size - 1), j = (innt2.size - 1); i >= 0; i--, j--)
			 {

				 int num1 = innt2.data[j] - 48;
				 int num2 = innt1.data[i] - 48;
				 int sub = 0;
				 if (num1 < num2)
				 {
					 num1 = num1 + 10;
					 sub = num1 - num2;
					 innt2.data[j - 1] = innt2.data[j - 1] - 1;
					 char t = sub + 48;
					 temp[size] = t;
					 size--;
					 count++;
				 }
				 else if (num1 >= num2)
				 {
					 sub = num1 - num2;
					 char t = sub + 48;
					 temp[size] = t;
					 size--;
					 count++;
				 }
			 }
			 HugeInteger tem(count + 1);
			 {
				 tem.data[count + 1] = '\0';
				 for (int i = 0, j = 0; i <= count; i++, j++)
				 {
					 if (temp[i] < 48 || temp[i]>57)
					 {
						 j--;
					 }
					 else
					 {
						 tem.data[j] = temp[i];
					 }

				 }
			 }
			 return tem;
		 }
		 
	 }
 }

 HugeInteger operator *(HugeInteger& innt1, HugeInteger& innt2)
 {
	 if (innt1.size > innt2.size)
	 {
		 HugeInteger ret=ret.setdata(innt1.size + innt2.size + 1);
		 HugeInteger temp(innt1.size + innt2.size + 1);
		 int zeros = 0;
		 for (int i = innt2.size - 1; i >= 0; i--)
		 {
			 int b = 0;
			 char tempa[500];
			 while (b < 500)
			 {
				 tempa[b] = '0';
				 b++;
			 }
			 int carry = 0;
			 int size = innt1.size;
			 int num1 = innt2.data[i] - 48;

			 for (int j = innt1.size - 1; j >= 0; j--)
			 {
				 int num2 = innt1.data[j] - 48;
				 int prod = (num1 * num2) + carry;
				 if (prod > 9)
				 {
					 int p = prod % 10;
					 prod = prod / 10;
					 carry = prod % 10;
					 char t = p + 48;
					 tempa[size] = t;
					 size--;
					 if (j == 0 && carry != 0)
					 {
						 char c = carry + 48;
						 tempa[size] = c;
						 size--;
					 }
				 }
				 else if (prod <= 9 || prod >= 0)
				 {
					 char t = prod + 48;
					 tempa[size] = t;
					 size--;
					 carry = 0;
				 }
			 }
			 for (int b = 0, c = 0; b <= innt1.size + zeros ; b++, c++)
			 {
				 if (tempa[b] < 48 || tempa[b]>57)
				 {
					 if (b == innt1.size + 1)
					 {
						 for (int a = 1; a <= zeros; a++)
						 {
							 temp.data[c] = '0';
							 c++;
						 }
					 }
					 c--;
				 }
				 else
				 {
					 temp.data[c] = tempa[b];

				 }
			 }
			 temp.Set_Size();
			 ret = temp + ret;
			 ret.Set_Size();
			 zeros++;
		 }
		 return ret;
	 }

	 if (innt1.size < innt2.size)
	 {
		 HugeInteger ret = ret.setdata(innt1.size + innt2.size + 1);
		 HugeInteger temp(innt1.size + innt2.size + 1);
		 int zeros = 0;
		 for (int i = innt1.size - 1; i >= 0; i--)
		 {
			 int b = 0;
			 char tempa[500];
			 while (b < 500)
			 {
				 tempa[b] = '0';
				 b++;
			 }
			 int carry = 0;
			 int size = innt2.size;
			 int num1 = innt1.data[i] - 48;

			 for (int j = innt2.size - 1; j >= 0; j--)
			 {
				 int num2 = innt2.data[j] - 48;
				 int prod = (num1 * num2) + carry;
				 if (prod > 9)
				 {
					 int p = prod % 10;
					 prod = prod / 10;
					 carry = prod % 10;
					 char t = p + 48;
					 tempa[size] = t;
					 size--;
					 if (j == 0 && carry != 0)
					 {
						 char c = carry + 48;
						 tempa[size] = c;
						 size--;
					 }
				 }
				 else if (prod <= 9 || prod >= 0)
				 {
					 char t = prod + 48;
					 tempa[size] = t;
					 size--;
					 carry = 0;
				 }
			 }
			 for (int b = 0, c = 0; b <= innt2.size + zeros; b++, c++)
			 {
				 if (tempa[b] < 48 || tempa[b]>57)
				 {
					 if (b == innt2.size + 1)
					 {
						 for (int a = 1; a <= zeros; a++)
						 {
							 temp.data[c] = '0';
							 c++;
						 }
					 }
					 c--;
				 }
				 else
				 {
					 temp.data[c] = tempa[b];

				 }
			 }
			 temp.Set_Size();
			 ret = temp + ret;
			 ret.Set_Size();
			 zeros++;
		 }
		 return ret;
	 }

	 if (innt1.size == innt2.size)
	 {
		 HugeInteger ret = ret.setdata(innt1.size + innt2.size);
		 HugeInteger temp(innt1.size + innt2.size );
		 int zeros = 0;
		 for (int i = innt1.size - 1; i >= 0; i--)
		 {
			 int b = 0;
			 char tempa[500];
			 while (b<500)
			 {
				 tempa[b] = '0';
				 b++;
			 }
			 int carry = 0;
			 int size = innt2.size;
			 int num1 = innt1.data[i] - 48;

			 for (int j = innt2.size - 1; j >= 0; j--)
			 {
				 int num2 = innt2.data[j] - 48;
				 int prod = (num1 * num2) + carry;
				 if (prod > 9)
				 {
					 int p = prod % 10;
					 prod = prod / 10;
					 carry = prod % 10;
					 char t = p + 48;
					 tempa[size] = t;
					 size--;
					 if (j == 0 && carry != 0)
					 {
						 char c = carry + 48;
						 tempa[size] = c;
						 size--;
					 }
				 }
				 else if (prod <= 9 || prod >= 0)
				 {
					 char t = prod + 48;
					 tempa[size] = t;
					 size--;
					 carry = 0;
				 }
			 }
			 for (int b = 0, c = 0; b <= innt2.size + zeros; b++, c++)
			 {
				 if (tempa[b] < 48 || tempa[b]>57)
				 {
					 if (b == innt2.size + 1)
					 {
						 for (int a = 1; a <= zeros; a++)
						 {
							 temp.data[c] = '0';
							 c++;
						 }
					 }
					 c--;
				 }
				 else
				 {
					 temp.data[c] = tempa[b];

				 }
			 }
			 temp.Set_Size();
			 ret = temp + ret;
			 ret.Set_Size();
			 zeros++;
		 }
		 return ret;
	 }
	 
 }
