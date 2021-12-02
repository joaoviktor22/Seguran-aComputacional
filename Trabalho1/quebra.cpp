#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string decifrador(vector<vector<char>> tabela,string cifra,string chave){
    string mensagem;
    vector<char> text;
    vector<int> pos;
    transform(cifra.begin(), cifra.end(), cifra.begin(), ::toupper);
    for(int i=0;i < cifra.size();i++){
        if(cifra[i] < 'A' || cifra[i] > 'Z'){
            text.push_back(cifra[i]);
            pos.push_back(i);
        }
    }
    for(int i=0;i < cifra.size();i++){
        if(cifra[i] < 'A' || cifra[i] > 'Z'){
            cifra.erase(cifra.begin()+i);
            i--;
        }
    }
    for(int i=0;chave.size() < cifra.size();i++){
        chave+= chave;
    }
    for(int i=0;chave.size() > cifra.size();i++){
        chave.pop_back();
    }
    transform(chave.begin(), chave.end(), chave.begin(), ::toupper);
    char m;
    for(int i=0;i < cifra.size();i++){
        if(cifra[i] >= 'A' && cifra[i] <= 'Z'){
            for(int j=0;j < tabela[chave[i]-'A'].size();j++){
                if(tabela[j][chave[i]-'A'] == cifra[i]){
                    m = j+'A';
                    break;
                }
            }
        } else{
            m = cifra[i];
        }
        mensagem.push_back(m);
    }
    for(int i=0;i < text.size();i++){
        mensagem.insert(mensagem.begin()+pos[i],text[i]);
    }
    return mensagem;
}

double calcularic(const vector<char>& seq){
    double I = 0;
    vector<int> counts{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (char i : seq){
        counts[i-'A'] = counts[i-'A']+1;
    }
    double n = seq.size();
    for (int count : counts){
        I = I + ((count*(count-1))/(n*(n-1)));
    }
    return I;
}

int calcularchi(vector<char> seq,vector<double> freqport,vector<double> freqeng,const vector<vector<char>>& tabela,int ling){
    vector<double> key{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> counts{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string ajuda;
    string s(seq.begin(), seq.end());
    double tam = seq.size();
    for (int i = 0; i < freqeng.size(); ++i) {
        string pos(1,char(i+'A'));
        ajuda = decifrador(tabela,s,pos);
        counts = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (char j : ajuda){
            counts[j-'A'] = counts[j-'A']+1;
        }
        if(ling == 0){
            for (int k = 0; k < counts.size(); ++k) {
                key[i] = key[i] + (((double(counts[k]) - (tam*freqeng[k]))*(double(counts[k]) - (tam*freqeng[k])))/( (tam*freqeng[k])));
            }
        }else{
            for (int k = 0; k < counts.size(); ++k) {
                key[i] = key[i] + (((double(counts[k]) - (tam*freqport[k]))*(double(counts[k]) - (tam*freqport[k])))/( (tam*freqport[k])));
            }
        }
    }
    int chave = 0;
    double menor = key[0];
    for (int i = 0; i < key.size(); i++){
        if(key[i] < menor){
            menor = key[i];
            chave = i;
        }
    }
    return chave;
}

double achartamanho(string cifra,int tam){
    int k=0;
    double I = 0;
    vector<vector<char>> comp;
    string frase;
    for(int i=0; i < (cifra.size()/tam); i++){
        //push a vector each time you loop a row
        comp.emplace_back();
        for(int j=0; j<tam; j++){
            comp[i].push_back(cifra[k]);
            k++;
        }
    }
    vector<char> seq;
    vector<double> ic;
    int coluna = tam,linha;
    linha = cifra.size()/tam;
    for (int i = 0; i < coluna; i++){
        seq.clear();
        for (int j = 0; j < linha; j++){
            seq.push_back(comp[j][i]);
        }
        ic.push_back(calcularic(seq));
    }
    for(double i : ic){
        I = I + i;
    }
    I = I/ic.size();
    return I;
}

vector<int> quebrar(string cifra,int tam,const vector<double>& freqport,const vector<double>& freqeng,const vector<vector<char>>& tabela,int ling){
    int k=0;
    vector<vector<char>> comp;
    string frase;
    for(int i=0; i < (cifra.size()/tam); i++){
        comp.emplace_back();
        for(int j=0; j<tam; j++){
            comp[i].push_back(cifra[k]);
            k++;
        }
    }
    vector<char> seq;
    vector<int> keys;
    int coluna = tam,linha;
    linha = cifra.size()/tam;
    for (int i = 0; i < coluna; i++){
        seq.clear();
        for (int j = 0; j < linha; j++){
            seq.push_back(comp[j][i]);
        }
        keys.push_back(calcularchi(seq,freqport,freqeng,tabela,ling));
    }

    return keys;
}

int main() {
    vector<vector<char>> tabela{
        {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
        {'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A'},
        {'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B'},
        {'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'},
        {'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D'},
        {'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E'},
        {'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F'},
        {'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G'},
        {'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H'},
        {'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I'},
        {'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J'},
        {'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K'},
        {'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L'},
        {'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'},
        {'O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N'},
        {'P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'},
        {'Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'},
        {'R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q'},
        {'S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'},
        {'T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'},
        {'U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'},
        {'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'},
        {'W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'},
        {'X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'},
        {'Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'},
        {'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'}
    };
    vector<double> freqport{0.1463,0.0104,0.0388,0.0499,0.1257,0.0102,0.013,0.0128,0.0618,0.004,0.0002,0.0278,0.0474,0.0505,0.1073,0.0252,0.012,0.0653,0.0781,0.0434,0.0463,0.0167,0.0001,0.0021,0.0001,0.0047};
    vector<double> freqeng{0.08167,0.01492,0.02782,0.04254,0.12702,0.02228,0.02015,0.06094,0.06966,0.00153,0.00772,0.04025,0.02406,0.06749,0.07507,0.01929,0.00095,0.05987,0.06327,0.09056,0.02758,0.00978,0.02360,0.0015,0.01974,0.00074};
    string cif,msg,cifra;
    vector<char> text;
    vector<int> pos;
    cout << "Qual a criptografia?" << endl;
    getline(cin,cifra);
    transform(cifra.begin(), cifra.end(), cifra.begin(), ::toupper);
    for(int i=0;i < cifra.size();i++){
        if(cifra[i] < 'A' || cifra[i] > 'Z'){
            text.push_back(cifra[i]);
            pos.push_back(i);
        }
    }
    for(int i=0;i < cifra.size();i++){
        if(cifra[i] < 'A' || cifra[i] > 'Z'){
            cifra.erase(cifra.begin()+i);
            i--;
        }
    }
    int tam = 10;
    vector<double> ic;
    for(int i = 1;i < tam;i++){
        ic.push_back(achartamanho(cifra,i));
    }
    int keysize = 1;
    float maior = ic[0];
    for(int i = 0; i < ic.size(); i++){
        if(ic[i] > maior){
            maior = ic[i];
            keysize = i+1;
        }
    }
    cout << endl << "Tamanho da key = " <<keysize << endl;

    vector<int> resposta;
    int ling = 0;
    resposta = (quebrar(cifra,keysize,freqport,freqeng,tabela,ling));
    cout << endl << "Senha(ENG): ";

    for(int i : resposta){
        string resp(1,char(i+'A'));
        cout << resp;
    }
    cout << endl;
    ling = 1;
    resposta = (quebrar(cifra,keysize,freqport,freqeng,tabela,ling));
    cout << endl << "Senha(Portugues): ";

    for(int i : resposta){
        string resp(1,char(i+'A'));
        cout << resp;
    }
    cout << endl;
 return 0;
}