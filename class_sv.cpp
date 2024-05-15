#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#define MH 3
using namespace std;
class sinhvien
{
private:
    int maHS;
    char hoten[50];
    string quequan;
    char ngaysinh[11];
    double diem[3];

public:
    void setMaHS(int id)
    {
        maHS = id;
    }
    void setHoTen(char *ht)
    {
        strcpy(hoten, ht);
    }
    void setQueQuan(string qq)
    {
        quequan = qq;
    }
    void setNgaySinh(char *ns)
    {
        strcpy(ngaysinh, ns);
    }
    void setDiem(double *d)
    {
        for (int i = 0; i < MH; i++)
            diem[i] = d[i];
    }
    void output()
    {
        cout << "\n=.......................=\n";
        cout << maHS << endl;
        cout << hoten << endl;
        cout << quequan << endl;
        cout << ngaysinh << endl;
        for (int i = 0; i < MH; i++)
            cout << diem[i] << "  ";
        cout << "\n=.......................=\n";
    }
};
int main()
{
    ifstream infile;
    infile.open("data.txt");
    if (infile.is_open())
    {
        while (infile.eof() == false)
        {
            int maHS;
            char hoten[50];
            string quequan;
            char ngaysinh[11];
            double diem[MH];
            sinhvien sv;
            infile >> maHS;
            sv.setMaHS(maHS);
            infile.ignore(1);
            infile.getline(hoten, 50, '\n');
            sv.setHoTen(hoten);
            getline(infile, quequan, '\n');
            sv.setQueQuan(quequan);
            infile.getline(ngaysinh, 11, '\n');
            sv.setNgaySinh(ngaysinh);
            for (int i = 0; i < MH; i++)
            {
                infile >> diem[i];
            }
            sv.setDiem(diem);

            sv.output();
        }
        infile.close();
    }
}