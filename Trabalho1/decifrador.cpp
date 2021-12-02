#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string decifrador(vector<vector<char>> tabela,string cifra,string chave){
    string mensagem;
    vector<char> text;
    vector<int> pos;
    cifra.erase(std::remove(cifra.begin(), cifra.end(), '\n'),cifra.end());
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
        chave += chave;
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
    string cifra,chave,resposta;
     cout << "Qual a criptografia?" << endl;
     getline(cin,cifra);
     cout << "Qual a senha?" << endl;
     getline(cin,chave);
     resposta = decifrador(tabela,cifra,chave);
     for (char i : resposta) {
         cout << i;
     }
     cout << endl;

 return 0;
}