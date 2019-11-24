#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct Notebook {
	struct disp_res {   
		int x, y;     
	};
	disp_res l;
	int f; 
	float d; 
	float hdd;  
	char model[21];  
	int price; 
	double weight;
	double length;
	double width;
	double height;
	int cpu;   
	int ram;
	int gpu;
};

int main()
{
	ifstream f("note.txt");
	int n = 0;
	char t, t1[1];
	char str [1000];
	while (!f.eof()) {
		f.getline(str, 1000);
		n++;
	}
	f.seekg(0, ios::beg);
	Notebook* mas = new Notebook[n];

	for (int i = 0; i < n; ++i) 
	{
		f.get(mas[i].model, 21);
		f >> mas[i].price >> mas[i].weight >> mas[i].height >> t >> mas[i].length >> t >> mas[i].width >> mas[i].cpu >> mas[i].ram >> mas[i].d >> mas[i].gpu >> mas[i].l.x >> t >> mas[i].l.y >> mas[i].f >> mas[i].hdd;
		cout << ' ' << mas[i].model << ' ' << mas[i].price << ' ' << "\t" << mas[i].weight << ' ' << "\t" << mas[i].height << '*' <<  mas[i].length << '*' <<  mas[i].width << ' ' << "\t" << mas[i].cpu << ' ' << "\t" << mas[i].ram << ' ' << "\t" << mas[i].d << ' ' << "\t" << mas[i].gpu << ' ' << "\t" <<  mas[i].l.x << '*' << mas[i].l.y << ' ' << "\t" << mas[i].f << ' ' << "\t" << mas[i].hdd<<"\t";
		cout << endl;
		f.getline(t1, 1);
	}
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (mas[i].price >= 3500) {
			k++;
		}
	}
	Notebook p;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (mas[j].cpu < mas[i].cpu ) {
				p = mas[i];
				mas[i] = mas[j];
				mas[j] = p;
			}
		}
	}
	ofstream bin("out.bin");
	bin << k;
	for (int i = 0; i < n; ++i) 
	{
		if (mas[i].price >= 3500) 
		{
			bin.write((char*)& mas[i], sizeof(Notebook));
		}
	}
	f.close();
	bin.close();
	return 0;
}