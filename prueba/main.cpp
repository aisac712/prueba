#include <iostream>
#include <string>
#include <math.h>                   //para usar la funcion ceil() q redondea al entero mayor
#include <vector>           //librería estándar de los vectores

#include <bits/stdc++.h>            //para hacer string to charArray

using std::string;
using std::to_string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

string encriptamiento(bool, string, int);

int main(int argc, char** argv) {
    /*string k ="";
    cin >> k;
    
    string k2 = encriptamiento(false, k, 3);
    
    /*cout << k.substr(0, 3) << endl;
    cout << k.substr(3, 3) << endl;
    cout << k.substr(6, 3) << endl;
    cout << k2 << endl;*/
    
//    string dequien = "Mensaje de aisoc#";
//    string msj = "buen_dia_nicolle#";
//    string llave = "3#";
//    string mensaje = dequien + msj + llave;
//    vector<string> tokens;
//    
//    for (auto i = strtok(&mensaje[0], "#"); i != NULL; i = strtok(NULL, "#")){
//        tokens.push_back(i);
//    }
//    
//    cout << tokens[0] << endl;
//    cout << tokens[1] << endl;
//    cout << tokens[2] << endl;
    string coor;
    cin >> coor;
    int i = -(coor.at(2)-48-8);
    int j = coor.at(1)-65;

    int i2 = -(coor.at(5)-48-8);
    int j2 = coor.at(4)-65;
    
    cout << to_string(i) << to_string(j);
    return 0;
}

string encriptamiento(bool encriptar, string mensaje, int llave){
    string mensaje2 = "";
    if(llave==0){
        return mensaje;
    } else{
        if(encriptar){
            
            //int llaveOriginal = llave;
            
            for(int i=0; i< ceil( (double)mensaje.size()/ (double)llave); i++){
                //cout << std::to_string( ceil( (double)mensaje.size()/ (double)llave) ) << endl;
                string cadenaReducida="";
                if(i==0){
                    //cout << mensaje.substr(0, llave) << endl;
                    cadenaReducida = mensaje.substr(0, llave);
                    
                } else {
                    //cout << mensaje.substr(llave*i, llaveOriginal) << endl;
                    cadenaReducida = mensaje.substr(llave*i, llave);
                }
                char char_array[cadenaReducida.length() + 1];
                strcpy(char_array, cadenaReducida.c_str());

                for(int j=0; j<cadenaReducida.length(); j++){
                    if(i%2==1)
                        char_array[j] = char_array[j]-llave;
                    else if(i%2==0)
                        char_array[j] = char_array[j]+llave;
                    
                    mensaje2+=char_array[j];
                }

                for(int i=0; i<cadenaReducida.length(); i++){
                    cout << char_array[i] << " ";
                }
                cout << "" << endl;
                
            }
            
            return encriptamiento(true, mensaje2, llave-1);
        } else{
            
            for(int i=0; i<ceil( (double)mensaje.size()/ (double)llave); i++){
                string cadenaReducida="";
                if(i==0){
                    //cout << mensaje.substr(0, llave) << endl;
                    cadenaReducida = mensaje.substr(0, llave);
                    
                } else {
                    //cout << mensaje.substr(llave*i, llaveOriginal) << endl;
                    cadenaReducida = mensaje.substr(llave*i, llave);
                }
                char char_array[cadenaReducida.length() + 1];
                strcpy(char_array, cadenaReducida.c_str());

                for(int j=0; j<cadenaReducida.length(); j++){
                    if(i%2==1)
                        char_array[j] = char_array[j]+llave;
                    else if(i%2==0)
                        char_array[j] = char_array[j]-llave;
                    
                    mensaje2+=char_array[j];
                }

                for(int i=0; i<cadenaReducida.length(); i++){
                    cout << char_array[i] << " ";
                }
                cout << "" << endl;
                
            }
            
            return encriptamiento(false, mensaje2, llave-1);
        }
        
        
    }
    
    
}