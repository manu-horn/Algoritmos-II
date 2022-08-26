#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    set<int> cs;
    for(int i : s){
        cs.insert(i);
    }
    for(int a : cs){
        res.push_back(a);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> cs;
    for(int i : s){
        cs.insert(i);
    }
    for(int a : cs){
        res.push_back(a);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> ca;
    set<int> cb;
    for(int i : a){
        ca.insert(i);
    }
    for(int i : b){
        cb.insert(i);
    }
    return ca == cb;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> ca;
    set<int> cb;
    for(int i : a){
        ca.insert(i);
    }
    for(int i : b){
        cb.insert(i);
    }
    return ca == cb;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int>res;

    for(int i: s){
        res[i]++;
    }

    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int>res;
    map<int,int> aps = contar_apariciones(s);

    for(pair<int,int> p : aps){
        if(p.second == 1){
            res.push_back(p.first);
        }
    }

    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int e : a){
        if(b.count(e)){
            res.insert(e);
        }
    }
    for(int e : b){
        if(a.count(e)){
            res.insert(e);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for(int e : s) {
        res[e % 10].insert(e);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    map<int,int> trad;
    set<char> key;
    for(pair<char,char> tup : tr){
        trad[tup.first] = tup.second;
    }
    for(char l : str){
        if(trad.count(l)){
            res.push_back(trad[l]);
        } else {
            res.push_back(l);
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    map<LU, set<LU>> lus; // a cada libreta le asocio su grupo (set de LUs)
    for(Mail m : s){
        set<LU> lib = m.libretas();
        for(LU l : lib){
            if(lus.count(l)){
                return (lus[l] != lib);
            } else{
                lus[l] = lib;
            }
        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(Mail m : s){
        set<LU> libsMail = m.libretas();
        Fecha date = m.fecha();
        if(!res.count(libsMail)){
            if(m.adjunto()){
            res[libsMail] = m;
            }
        } else {
            if(m.adjunto() && m.fecha() >= res[libsMail].fecha()){
                res[libsMail] = m;
            }
        }
    }
    return res;
}
