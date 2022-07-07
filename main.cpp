#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>    //libreria para la hora
//By Water :3

using namespace std;

//-----------------------------------------------Declaracion de funciones---------------------------------------------//
int amountOfLuck(string answer);
void luckMessage(int luckValue);
bool salir(string ans);
void playTheGame(int probabilidad);
bool esNumero(int esNumero);
int handicap(int chanceToWin);
//--------------------------------------------------------------------------------------------------------------------//

//main, el nucleo de todo...
int main()
{
    int totProb = 0;
    string res = "",res2 = "";
    
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    cout<<"SOFTWATER - NO TE TOMES MUY A PECHO LO DE LA SUERTE, ES SOLO PARA FINES DE ENTRETENIMIENTO :P"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"El dia de hoy te sientes con suerte (si/no/regular): ";
    getline(cin,res);   //se guarda la primera respuesta del usuario
    
    //bucle que solo admite las respuestas que se esperan
    while(res!="si"&&res!="no"&&res!="regular"){
        cout<<"Responde SI o NO te sientes con suerte?? (SI/NO/REGULAR): ";
        getline(cin,res);   //hasta que no responda como se espera no se podra salir del bucle
    }
    
    //Transforma el texto a minusculas, no importa si el usuario introduce solo mayusculas
    transform(res.begin(),res.end(),res.begin(),::tolower);
    totProb = amountOfLuck(res);    //se llama a la funcion que te otorga la suerte
    
    luckMessage(totProb);    //se llama a la funcion que imprime los mensajes dependiendo de tu suerte
    getline(cin,res2);  //se guarda la segunda respuesta del usuario
    //Transforma la segunda respuesta del usuario a minusculas
    transform(res2.begin(),res2.end(),res2.begin(),::tolower);
    
    //por si el usuario responde no el programa termina directamente
    if(salir(res2)){
        cout<<"Muy bien nos vemos"<<endl;
        return 0;
    }
    
    //bucle para solo recibir las respuestas disponibles a la pregunta
    while(res2!="si"&&res2!="no"){
        cout<<"quieres probar tu suerte SI o NO?: ";
        getline(cin,res2);
        if(salir(res2)){    //aca se vuelve a llamar a la funcion salir en caso de que el usuario responda "no"
            cout<<"Muy bien nos vemos!"<<endl;
            return 0;
        }
    }
    
    if(res2=="ya que"||res2=="yaque")
        res2=="si";
    if(res2=="si"){
        playTheGame(totProb);
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------//

//Funcion que te da al azar (o por cuestion de suerte, como tu lo quieras ver) un porcentaje de suerte
int amountOfLuck (string answer){
    int luckChance = 0;
    //funcion random en donde tenemos a la hora en tiempo real como seed (lo cual hara variar el numero random)
    srand(time(NULL));
    
    if(answer=="si"){
        //si te sientes con suerte te doy 20% mas de suerte para que salga alta tu probabilidad :3
        luckChance = (rand()%100)+21;
        return luckChance;
    } else if (answer=="no"){
        //si no te sientes suertudo entonces te quito 30% de suerte jejeje
        luckChance = (rand()%100)-31;
        return luckChance;
    } else if (answer=="regular"){
        //suerte regular, sin ventajas ni desventajas c:
        luckChance = (rand()%100)+1; //el mas 1 es para que alcance a llegar a 100
        return luckChance;
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------//

//Funcion que imprime mensajes de tu status de suerte (dependiendo de tu porcentaje de suerte)
void luckMessage(int luckValue){
    //Viejo if que usaba antes, ahora pase todo a un switch
    /*if (luckValue>=0&&luckValue<=19){
        cout<<"Tienes un "<<luckValue<<"% de suerte, no es muy buena...\nquieres probar tu suerte? (si/no): ";
    } else if (luckValue>=20&&luckValue<=49){
        cout<<"Tienes un "<<luckValue<<"% de suerte, tu es suerte decente\nquieres probar tu suerte? (si/no): ";
    } else if (luckValue>=50&&luckValue<=79){
        cout<<"Tienes un "<<luckValue<<"% de suerte, tienes buena suerte c;\nquieres probar tu suerte? (si/no): ";
    } else if (luckValue>=80&&luckValue<=99){
        cout<<"Tienes un "<<luckValue<<"% de suerte, si que tienes muy buena suerte hoy!! \nquieres probar tu suerte? (si/no): ";
    } else if (luckValue>=100&&luckValue<=110){
        cout<<"Tienes un "<<luckValue<<"% de suerte, diablos estas que desbordas suerte :o\nquieres probar tu suerte? (si/no): ";
    } else if (luckValue>=-30&&luckValue<=0){
        cout<<"Bro.... estas muy salado hoy, tu suerte es de "<<luckValue<<"% \naun asi puedes probar tu suerte, quieres? (no/ya que): ";
    }*/
    switch(luckValue){
        case -30 ... -1:
            cout<<"Bro.... estas muy salado hoy, tu suerte es de "<<luckValue<<"% \naun asi puedes probar tu suerte, quieres? (no/ya que): ";
            break;
        case 0:
            cout<<"Tienes un "<<luckValue<<"% de suerte\n no tienes suerte hoy... aunque considerate suertudo por dar con el 0 exacto\nquieres probar tu suerte? (si/no): ";
            break;
        case 1 ... 19:
            cout<<"Tienes un "<<luckValue<<"% de suerte, no es muy buena...\nquieres probar tu suerte? (si/no): ";
            break;
        case 20 ... 49:
            cout<<"Tienes un "<<luckValue<<"% de suerte, tu es suerte decente\nquieres probar tu suerte? (si/no): ";
            break;
        case 50 ... 79:
            cout<<"Tienes un "<<luckValue<<"% de suerte, tienes buena suerte c;\nquieres probar tu suerte? (si/no): ";
            break;
        case 80 ... 99:
            cout<<"Tienes un "<<luckValue<<"% de suerte, si que tienes muy buena suerte hoy!! \nquieres probar tu suerte? (si/no): ";
            break;
        case 100 ... 110:
            cout<<"Tienes un "<<luckValue<<"% de suerte, diablos estas que desbordas suerte :o\nquieres poner a prueba tu suerte? (si/no): ";
            break;
    }
}

//---------------------------------------------------------------------------------------------------------------------//

//funcion de relleno... eso pienso
bool salir(string ans){
    if(ans=="no")
        return true;
    else if(ans=="si")
        return false;
}

//----------------------------------------------------------------------------------------------------------------------//

//funcion donde se desarrolla el pequeño juego de adivina el numero (muy creativo jeje...)
void playTheGame(int probabilidad){
    string addAns = " ";
    do{
        srand(time(NULL)); //seed random para los randoms
        int num = 0;
        int guessNum = 0, ventaja = 999;
        
        cout<<"Adivina el numero en el que estoy pensando (0-9): ";
        cin>>num;
        
        //bucle para seguir esperando un numero en caso de que no se ingrese alguno c:
        while(esNumero(num)!=true){
            cout<<"Inserta solo un NUMERO, solo en el que estoy pensando, NO insertes algun otro caracter (0-9): ";
            cin>>num;
        }
        
        if(esNumero(num)){
            guessNum = (rand()%10); //La computadora solo pensara (o bueno generara) un numero del 0 al 9
            ventaja = handicap(probabilidad);   //se comprueba si tienes ventajas, claro esto depende si tu te sientes con suerte ;)
            
            switch(ventaja){    //dependiendo de que nivel de ventaja tengas te tocara alguno de los casos siguientes
                case 0:{
                    int lastChance = (rand()%10);   //ultimo reroll en caso de que no te toque alguna de las ventajas anteriores
                    if(lastChance==guessNum){   //para entrar en este if debe coincidir un numero random con otro random
                        guessNum = num; //entrando al if se altera el numero
                    }
                    break;
                }
                case 1: //case para la win asegurada
                    guessNum = num; //se altera el numero que deberia ser random y se pone el numero que te escribiste c:
                    break;
                case 777:{ //case especial... para ocasiones muy extrañas y especiales
                    guessNum = num;
                    cout<<"A pesar de tener una suerte tan pesima, lograste acertar al numero\n Felicidades!!!";
                    break;
                }
            }
            
            if(guessNum==num){
                cout<<"\a\a\aAdivinaste el numero!!\n el numero fue: "<<guessNum<<endl;//mensajes cutres de victoria y derrota
            } else {
                cout<<"No lograste adivinarlo :c\nel numero en el que pensaba era: "<<guessNum<<endl;
            } 
        }
        cout<<"Quieres volver a probar tu suerte? (si/no): ";
        cin>>addAns;
        transform(addAns.begin(),addAns.end(),addAns.begin(),::tolower);
    }while(salir(addAns)==false);
    cout<<"Gracias por jugar, nos vemos!!"<<endl;
}

//----------------------------------------------------------------------------------------------------------------------//

int handicap(int chanceToWin){
    srand(time(NULL));  //otra seed random basada en la hora real
    int ventaja = 999;
    
    switch(chanceToWin){
        case -30 ... 10:    //poco porcentaje de suerte == menos probabilidad de ganar
            ventaja = (rand()%1000)+3; //considerate con mucha suerte si es que te toca un buen case de 1 entre 1000 xd
            break;
        case 80 ... 99:     //mucho porcentaje de suerte == alta probabilidad de ganar
            ventaja = (rand()%2);
            break;
        case 100 ... 110:   //porcentaje mas arriba del 100 es win asegurada jsjsjsjs
            ventaja = 1;
            break;
    }
    return ventaja; //retorname la ventaja para los casos
}

//----------------------------------------------------------------------------------------------------------------------//

//funcion para verificar si es numero o no mediante un char
bool esNumero(int numero){
    if(numero>=0&&numero<=9)    //si es numero es true, si no pues false, lo normalito de oswi xd
        return true;
    else
        return false;
}





