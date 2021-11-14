#include <stdio.h>
#include <math.h>

int main() {
    /*FILE* fajl = fopen("be.txt","r");
    char gumik[3];
    double ujkor[3];
    int kopaskezd[3];
    double kopasmerteke[3];
    int elhasznalodasked[3];
    double elhasznalodasmert[3];
    int korokszama;
    double box;
    int i = 0;
    //int box1 = 0,box2 = 15,box3 = 50;
    //char gumi1 = 'A', gumi2 = 'B', gumi3 = 'C';
    while(!feof(fajl)){
        if(i < 3){
            fscanf(fajl,"%c %lf %d %lf %d %lf",&gumik[i],&ujkor[i],&kopaskezd[i],&kopasmerteke[i],&elhasznalodasked[i],&elhasznalodasmert[i]);
        }
        if(i == 3){
            fscanf(fajl,"%d", &korokszama);
        }
        if(i == 4){
            fscanf(fajl,"%lf", &box);
        }
        if(i == 5){
            fscanf(fajl,"%lf", &box);
        }
        i++;
    }

*/
    /*Mivel nem tudtam beolvasni a fájlt ezért így tároltam el az adatokat
     * A fájl utolsó soráról el kell még dönteni hogy legalább egyszer volt kereket cserélni,
     * ha nem volt akkor HIBA-val kell vissza térni,
     * és ez az utolsó sor ami a stratégiát jelöli 2-nél több is lehet
     * */
    //Még egy megjegyzés amik itt vannak a tömbe adatok a végeredményben egy értéket nem add hozzá és nem tudom hol
    char gumik[3] = {'A','B','C'};
    double ujkor[3] = {60.0,61.0,62.0};
    int kopaskezd[3] = {3,5,15};
    double kopasmerteke[3] = {1.0,0.5,0.1};
    int elhasznalodasked[3]= {5,8,15};
    double elhasznalodasmert[3] = {1.0,0.6,0.2};
    int korokszama = 60;
    double box = 25;
    double ido = 0;
    char kerek[3] = {'B','C','A'};
    int tombmeret = sizeof(kerek);
    int tartam[3] = {0, 15, 50};
    int akt_gumi;
    for (int j = 0; j < tombmeret; ++j) {
            if(kerek[0] == gumik[j]){
                akt_gumi = j;
                break;
            }
    }

    FILE* kifajl = fopen("ki.txt","w");
    if(tombmeret < 2) {
        fprintf(kifajl, "HIBA\n");
    }else{
    int k = 1;
    int kezd = 0;
    double akt_elhaszn = 0;
        for (int j = 0; j < korokszama; ++j) {
            ido += ujkor[akt_gumi];
            if(j >= kezd+kopaskezd[akt_gumi] && j <= kezd+elhasznalodasked[akt_gumi]){
                ido += kopasmerteke[akt_gumi];
            }
            if(j >= kezd+elhasznalodasked[akt_gumi]){
                akt_elhaszn += elhasznalodasmert[akt_gumi];
                ido += akt_elhaszn;
            }
            if(tartam[k] == j && j != 0){
                ido = ido + box;
                for (int h = 0; h < tombmeret; ++h) {
                    if(kerek[k] == gumik[h]){
                        akt_gumi = h;
                        k++;
                        akt_elhaszn = 0;
                        kezd = j;
                        fprintf(kifajl,"Kerek csere\n");
                        break;
                    }
                }
            }
            fprintf(kifajl,"%d %c %lf %d %lf %d %0.3lf %d \n",(j+1),gumik[akt_gumi], ujkor[akt_gumi],kopaskezd[akt_gumi], kopasmerteke[akt_gumi],elhasznalodasked[akt_gumi], akt_elhaszn, kezd);
        }
    fprintf(kifajl,"%0.3lf\n",ido);
    }
    //fclose(fajl);
    fclose(kifajl);
    return 0;
}
