#include <iostream>
#include "simu.h"
#include <cmath>

using namespace std;


int main()
{
    string material_obj,parada_loop10,parada_loop11;
    double massamat,fpeso,massa1;
    double vx,vy,vz,atrx,atry,femp;
    int chave_obj;
    objetos obj1;
    objetos obj2;
    cout<< "voce deseja escolher um material especifico para seu objeto ou deseja escolher as propriedades manualmente?"<<endl<<endl;
    cout<<"para escolher material digite 1, para setar as propriedades digite 2: "<<endl<<endl;
    cin>> chave_obj;

    while(true){
        if(chave_obj == 1){
            obj1.setmaterial();
            obj1.setforma();
            massamat = obj1.getdense_material()*obj1.getforma();
            cout<<"a massa do seu objeto: "<< massamat<< " kg"<<endl<<endl;
            cout<<"deseja confirmar seu material?";
            cin >> parada_loop10;

            if(parada_loop10 == "sim"){
                cout<<"seu material: "<<"volume: "<<obj1.getforma()<<" m^3"<<", massa: "<< massamat<< " kg"<<", densidade:"<<obj1.getdense_material()<<" kg/m^3"<<endl<<endl;
                break;
            }else{
                cout<<endl<<endl;
            }
        }else if(chave_obj == 2){
            obj2.setmassa();
            obj2.setforma();
            obj2.setdensidade();
            obj2.setatritoestatico();
            obj2.setatritocinetico();

            obj2.getatritocinetico();
            obj2.getatritoestatico();
            obj2.getmassa();
            obj2.getdensidade();
            cout<<"deseja confirmar seu material?";
            cin >> parada_loop11;
            if(parada_loop11 == "sim"){
                cout<<"seu material: "<<"volume: "<<obj2.getforma()<<" m^3"<<", massa: "<< obj2.getmassa()<< " kg"<<", densidade:"<<obj2.getdensidade()<<" kg/m^3"<<endl<<endl;
                break;
            }else{
                cout<<endl<<endl;
            }

        }else{
            cout<<"valor invalido!"<<endl<<endl;
        }

    }
    //deve-se futuramente interligar as classes tal que seja possivel que o campo distingua os objetos

    if(chave_obj == 2){

        campo camp2;

        camp2.setatritocobj(obj2.getatritocinetico());
        camp2.setatritoeobj(obj2.getatritoestatico());
        camp2.forca();
        camp2.saida_forca(obj2.getmassa(),obj2.getdensidade());
        camp2.setmovimento(obj2.getmassa(),0,0,0,0);


        vy = camp2.velocidadey();
        vz = camp2.velocidadez();
        atrx = camp2.aceleracao_atritocx();
        atry = camp2.aceleracao_atritocy();
        vx = camp2.velocidadex();
        femp = camp2.get_empuxo();
        massa1 = obj2.getmassa();



        //complemento
        double vfx,vfy,vfz;
        fpeso = obj2.getmassa()*9.81;




    }else if(chave_obj == 1){
        //implementar logica
        cout<<"não foi possivel inicializar"<<endl;
    }else{
        cout<<"não foi possivel inicializar"<<endl;
    }
    double sx = 0;
    double sy = 0;
    double sz = 0;

    double sx1 = 0;
    double sy1 = 0;
    double sz1 = 0;

    double sxf = 0;
    double syf = 0;
    double szf = 0;

    double t = 0.01;
    double ta = 0.01;
    double tf = 0;
    double vfx = 0;
    double vfy = 0;
    double vfz = 0;
    int inivz;


    string chave_sinalvx,chave_sinalvy,chave_sinalvz;

    if(vx > 0){
        chave_sinalvx = "positivo";
    }else if(vx < 0){
        chave_sinalvx ="negativo";
    }else{
        chave_sinalvx ="zero";
    }

    if(vy > 0){
        chave_sinalvy = "positivo";
    }else if(vy < 0){
        chave_sinalvy = "negativo";
    }else{
        chave_sinalvy = "zero";
    }
    if(vz > 0){
        inivz = 1;
    }else if(vz < 0){
        inivz = 0;
    }else{
        inivz = 0;
    }


    if(chave_obj == 2){

        do{
            cout<<endl<<"instante: "<<tf<<" s:"<<endl<<endl;
            if(inivz == 0){
                //zerando o vz
                vz = 0;
                //trata x
                if(chave_sinalvx =="positivo"){
                    if(vx > 0){
                        vfx = vx - atrx*t;
                        sx = vx*t - 0.5*atrx*t*t;
                    }else if(vx < 0){
                        vx = 0;
                        sx = 0;
                    }else if(vx == 0){
                        vfx = 0;
                        sx = 0;
                    }
                }else if(chave_sinalvx == "negativo"){
                    if(vx < 0){
                        vfx = vx + atrx*t;
                        sx = vx*t + 0.5*atrx*t*t;
                    }else if(vx > 0){
                        vx = 0;
                        sx = 0;
                    }else if(vx == 0){
                        vfx = 0;
                        sx = 0;
                    }
                }else if(chave_sinalvx == "zero"){
                    vfx = 0;
                    sx = 0;
                }
                if(chave_sinalvy =="positivo"){
                    if(vy > 0){
                        vfy = vy - atry*t;
                        sy = vy*t - 0.5*atry*t*t;
                    }else if(vy < 0){
                        vy = 0;
                        sy = 0;
                    }else if(vy == 0){
                        vfy = 0;
                        sy = 0;
                    }
                }else if(chave_sinalvy == "negativo"){
                    if(vx < 0){
                        vfx = vy + atry*t;
                        sx = vy*t + 0.5*atry*t*t;
                    }else if(vy > 0){
                        vy = 0;
                        syf = 0;
                    }else if(vy == 0){
                        vfy = 0;
                        syf = 0;
                    }
                }else if(chave_sinalvy == "zero"){
                    vfy = 0;
                    sy = 0;
                }
                t+=0.01;

            }else{
                if(0 == vz){
                    cout<<"objeto colidiu com o solo!"<<endl<<endl;
                    inivz = 0;
                }else{
                    vfx = vx;
                    vfy = vy;
                    sx1 = vx*ta;
                    sy1 = vy*ta;

                    double fresulz = (femp - fpeso)/massa1;

                    sz1 = vz*ta + 0.5*fresulz*ta*ta;

                    vfz = vz + fresulz*ta;


                    ta +=0.01;
                    if(sz1 < 0){
                        vfz = 0;
                        vz = 0;
                        sz1 = 0;
                    }

                }

            }


         // incrementos e valores



            sxf= sx + sx1;
            syf= sy + sy1;
            szf= sz + sz1;

            tf = ta + t;

            cout<<"distancia percorrida em x: "<<sxf<<" m"<<" velocidade x: "<<vfx<<" m/s"<<endl<<endl;
            cout<<"distancia percorrida em y: "<<syf<<" m"<<" velocidade y: "<<vfy<<" m/s"<<endl<<endl;
            cout<<"altura: "<<szf<<" m"<<" velocidade em z: "<<vfz<<" m/s"<<endl<<endl;


        } while (abs(vfx) > 0.1 ||abs(vfy) > 0.1|| abs(vfz) > 0.1);
    }
    double distancia_total = sqrt(sxf*sxf +  syf*syf);
    cout<<"distancia total percorrida: "<<distancia_total<<" m"<<endl<<endl;
    double velocidade_media = distancia_total/t;

    cout<<"velocidade total media do objeto: "<<velocidade_media<<" m/s";



    return 0;
}
