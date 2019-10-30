#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

class tabela;

class individ{
    friend class tabela;
private:

    char nume_specie; /// '+' sau '0'
    int varsta;/// de la 0 la 20
    double energie;
    unsigned char viu; /// 1 viu, 0 mort

    void hraneste(individ v[20][70], int i,int j){
        energie =energie +1+calcul_ap_energetic(v,i,j)+11/(abs(varsta-10)+1);
    }

    void inmulteste(individ v[20][70] , int i ,int j){
        char tip=v[i][j].nume_specie;
        if(v[i][j].varsta>5){
        if ((i-1)>=0&&v[i-1][j].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i-1][j]=a; v[i][j].energie=v[i][j].energie-20;}
        if ((i+1)<20&&v[i+1][j].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i+1][j]=a; v[i][j].energie=v[i][j].energie-20;}
        if ((j+1)<70&&v[i][j+1].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i][j+1]=a; v[i][j].energie=v[i][j].energie-20;}
        if ((j-1)>=0&&v[i][j-1].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i][j-1]=a; v[i][j].energie=v[i][j].energie-20;}
        if ((i-1)>=0&&(j-1)>=0&&v[i-1][j-1].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i-1][j-1]=a; v[i][j].energie=v[i][j].energie-20;}
        if ((i-1)>=0&&(j+1)<70&&v[i-1][j+1].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i-1][j+1]=a; v[i][j].energie=v[i][j].energie-20;}
        if ((i+1)<20&&(j+1)<70&&v[i+1][j+1].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i+1][j+1]=a; v[i][j].energie=v[i][j].energie-20;}
        if ((i+1)<20&&(j-1)>=0&&v[i+1][j-1].nume_specie==' '&&v[i][j].energie>25) {individ a(tip);v[i+1][j-1]=a; v[i][j].energie=v[i][j].energie-20;}
        }
    }

    void ataca(individ v[20][70], int i, int j){
        char tip=v[i][j].nume_specie;
        char tip2;
        if(tip=='+') tip2='0'; else tip2='+';
        double energ=v[i][j].energie;
        if ((i-1)>=0&&v[i-1][j].nume_specie==tip2&&v[i-1][j].energie<energ)
            {v[i][j].energie=v[i][j].energie-v[i-1][j].energie; v[i-1][j].moare();}
        if ((i+1)<20&&v[i+1][j].nume_specie==tip2&&v[i+1][j].energie<energ)
         {v[i][j].energie=v[i][j].energie-v[i+1][j].energie; v[i+1][j].moare();}
        if ((j+1)<70&&v[i][j+1].nume_specie==tip2&&v[i][j+1].energie<energ)
         {v[i][j].energie=v[i][j].energie-v[i][j+1].energie; v[i][j+1].moare();}
        if ((j-1)>=0&&v[i][j-1].nume_specie==tip2&&v[i][j-1].energie<energ)
         {v[i][j].energie=v[i][j].energie-v[i][j-1].energie; v[i][j-1].moare();}
        if ((i-1)>=0&&(j-1)>=0&&v[i-1][j-1].nume_specie==tip2&&v[i-1][j-1].energie<energ)
         {v[i][j].energie=v[i][j].energie-v[i-1][j-1].energie; v[i-1][j-1].moare();}
        if ((i-1)>=0&&(j+1)<70&&v[i-1][j+1].nume_specie==tip2&&v[i-1][j+1].energie<energ)
         {v[i][j].energie=v[i][j].energie-v[i-1][j+1].energie; v[i-1][j+1].moare();}
        if ((i+1)<20&&(j+1)<70&&v[i+1][j+1].nume_specie==tip2&&v[i+1][j+1].energie<energ)
         {v[i][j].energie=v[i][j].energie-v[i+1][j+1].energie; v[i+1][j+1].moare();}
        if ((i+1)<20&&(j-1)>=0&&v[i+1][j-1].nume_specie==tip2&&v[i+1][j-1].energie<energ)
         {v[i][j].energie=v[i][j].energie-v[i+1][j-1].energie; v[i+1][j-1].moare();}
    }

    void imbatraneste(){
        varsta++;
        energie=energie-5;
        if(energie<=0||varsta>20)   moare();
    }

    void moare(){
        viu='0';
        nume_specie=' ';
    }
public:
    individ(){
        nume_specie=' ';
    }
    individ(char tip){
    this->nume_specie=tip;
    varsta=0;
    energie=10;
    viu='1';
    }

    individ(individ &x){
        nume_specie=x.nume_specie;
        varsta=x.varsta;
        energie=x.energie;
        viu=x.viu;
    }

    int calcul_ap_energetic(individ v[20][70],int i, int j)
    {
        int s=0;
        if ((i-1)>=0&&v[i-1][j].nume_specie==' ') s++;
        if ((i-2)>=0&&v[i-2][j].nume_specie==' ') s++;
        if ((i+1)<20&&v[i+1][j].nume_specie==' ') s++;
        if ((i+2)<20&&v[i+2][j].nume_specie==' ') s++;
        if ((j+1)<70&&v[i][j+1].nume_specie==' ') s++;
        if ((j+2)<70&&v[i][j+2].nume_specie==' ') s++;
        if ((j-1)>=0&&v[i][j-1].nume_specie==' ') s++;
        if ((j-2)>=0&&v[i][j-2].nume_specie==' ') s++;
        if ((i-1)>=0&&(j-1)>=0&&v[i-1][j-1].nume_specie==' ') s++;
        if ((i-1)>=0&&(j+1)<70&&v[i-1][j+1].nume_specie==' ') s++;
        if ((i+1)<20&&(j+1)<70&&v[i+1][j+1].nume_specie==' ') s++;
        if ((i+1)<20&&(j-1)>=0&&v[i+1][j-1].nume_specie==' ') s++;
        return s;
    }
///suprasriere operator <<
    friend ostream& operator <<(ostream& out, const individ &indiv);
};

    ostream& operator <<(ostream& out, const individ &indiv){
    out<<"nume specie: ";
    out<<indiv.nume_specie<<endl;
    out<<"varsta: ";
    out<<indiv.varsta<<endl;
    out<<"energie: ";
    out<<indiv.energie<<endl;
    out<<"viu: ";
    out<<indiv.viu<<endl;
    return out;
    }

class tabela {
    friend class individ;
private:
    individ indivizi[20][70];
public:

    ~tabela(){}

    void generare_aleatoare(){
    int x,y,z;
        for(int k=0;k<50;k++)
        {

            x=rand()%20;
            y=rand()%70;
            z=rand()%2;
            if(indivizi[x][y].nume_specie=='+'||indivizi[x][y].nume_specie=='0') k--;
            else {
                    if(z==0) {individ a('+');indivizi[x][y]=a;}
                    if(z==1) {individ a('0');indivizi[x][y]=a;}
                }
        }
    }

void afisare_tabela(){
    cout<<endl;
    for(int i=0;i<71;i++)   cout<<'_';
            cout<<endl;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<70;j++)
            {   if(j==0) cout<<'|';
                if(indivizi[i][j].viu=='1')
                    cout<<indivizi[i][j].nume_specie;
                    else cout<<' ';
                if(j==69) cout<<'|';
            }
            cout<<endl;
    }
    cout<<'|';
    for(int i=0;i<70;i++)   cout<<'_';
        cout<<'|';
}

    void actualizare(){
     for(int i=0;i<20;i++)
            for(int j=0;j<70;j++)
                if(indivizi[i][j].nume_specie=='+'||indivizi[i][j].nume_specie=='0'){
                        indivizi[i][j].hraneste(indivizi,i,j);
                        indivizi[i][j].inmulteste(indivizi,i,j);
                        indivizi[i][j].ataca(indivizi,i,j);
                        indivizi[i][j].imbatraneste();
                    }
    }
    void afis_indiv(){
        for(int i=0;i<20;i++)
            for(int j=0;j<70;j++)
                if(indivizi[i][j].nume_specie=='+'||indivizi[i][j].nume_specie=='0')
                    cout<<indivizi[i][j]<<endl<<endl;
    }
};

int main()
{
    tabela a;
    a.generare_aleatoare();
    for(int i=0; i<100; i++)
    {
        a.actualizare();
        a.afisare_tabela();
    }

}
