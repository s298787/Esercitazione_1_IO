#include <fstream> //libreria i/o su file
#include <iostream> //libreria i/o su compiler
// #include <math.h>
#include <iomanip> //libreria per formattare output

using namespace std;

double contrazione(double x)
{
    x = 0.75*x - 1.75; //manda [1;5] in [-1;2]
    return x;
}

int main()
{
    string nomefile = "data.csv";
    ifstream fstr(nomefile); //apre il file di lettura
    if(fstr.fail()) //controlla se il file di lettura esiste
    {
        cerr << "File not found"; //stampa un errore se il file di input non esiste e restituisce codice 1
        return 1;
    }

    string fileout = "result.csv";
    ofstream ofstr(fileout); //crea il file di output "result.csv"

    if (ofstr.is_open())
    {
        ofstr << "# N Mean" <<endl; //scrive la prima riga nel file di output
        double val;
        double mean = 0; //inizializza la media
        int i = 0;
        while (fstr >> val) //prende la riga da fstr e la mette in val
        {
            i = i+ 1;
            val = contrazione(val); //funzione che contrae in [-1;2]
            mean = mean*(i-1)/i + val/i; //aggiunge l'i-esimo numero alla media
            ofstr << scientific << setprecision(16) << i << " " << mean << endl; //scrive la riga nel file di output
        }
        ofstr.close(); //chiude il file di output
        fstr.close(); //chiude il file di input
        return 0;
    }
    cerr << "File creation unsuccessful"; //stampa un errore nel caso non sia riuscito a creare un file di output e restituisce codice 2
    return 2;
}
