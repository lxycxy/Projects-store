#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


struct dishy
{

	int tablen;
	int dishno;
	string dish;
	int price;
	int  state;
};
struct tablel
{
	int tableno;
	int dishnum;
	int peonum;
	dishy bill[100];
};
struct tabley
{
	int no;
	int num;
	int state;
};