#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string cifrador(vector<vector<char>> tabela,string mensagem,string chave){
    string cifra;
    vector<char> text;
    vector<int> pos;
    transform(mensagem.begin(), mensagem.end(), mensagem.begin(), ::toupper);
    for(int i=0;i < mensagem.size();i++){
        if(mensagem[i] < 'A' || mensagem[i] > 'Z'){
            text.push_back(mensagem[i]);
            pos.push_back(i);
        }
    }
    for(int i=0;i < mensagem.size();i++){
        if(mensagem[i] < 'A' || mensagem[i] > 'Z'){
            mensagem.erase(mensagem.begin()+i);
            i--;
        }
    }
    for(int i=0;chave.size() < mensagem.size();i++){
        chave+=chave;
    }
    for(int i=0;chave.size() > mensagem.size();i++){
        chave.pop_back();
    }
    transform(chave.begin(), chave.end(), chave.begin(), ::toupper);
    for(int i=0;i < mensagem.size();i++){
        cifra.push_back(tabela[mensagem[i]-'A'][chave[i]-'A']);
    }
    for(int i=0;i < text.size();i++){
        cifra.insert(cifra.begin()+pos[i],text[i]);
    }
    return cifra;
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
    string mensagem,chave,resposta;
    cout << "Qual a mensagem?" << endl;
    getline(cin,mensagem);
    cout << "Qual a senha?" << endl;
    getline(cin,chave);

    resposta = cifrador(tabela,mensagem,chave);
    for (char i : resposta) {
        cout << i;
    }
    cout << endl;
 return 0;
}