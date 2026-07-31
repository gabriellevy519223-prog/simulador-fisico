#include <iostream>
#include "simu.h"
#include <cmath>

using namespace std;

void objetos::setmassa(){
    cout<<"qual a massa do objeto? ";
    cin>> massa;
}
double objetos::getmassa ()const{
    return massa;
}
void objetos::setforma(){
    cout <<"escolha o formato do seu objeto entre: cubo, paralelepipedo e esfera: "<<endl;
    cin>> corpo;
    if (corpo == "cubo"){
        cout<<"qual o tamanho da aresta em metros? "<<endl;
        cin>> aresta;
        vol = aresta*aresta*aresta;
        cout<<"volume do cubo: "<<vol<<" m^3"<<endl;

    }else if(corpo == "paralelepipedo"){
        cout<<"qual a altura do paralelepipedo em metros? "<<endl;
        cin>> altura;
        cout<<"qual a largura do paralelepipedo em metros? "<<endl;
        cin>> largura;
        cout<<"qual a profundidade do paralelepipedo em metros? "<<endl;
        cin>> profundidade;
        vol = altura*largura*profundidade;
        cout<<"volume do paralelepipedo: "<<vol<<" m^3"<<endl;


    }else if(corpo =="esfera"){
        cout<<"qual o tamanho do raio da esfera em metros? "<<endl;
        cin>> raio;
        vol = 3.1416*4/3*raio*raio*raio;
        cout<<"volume da esfera: "<<vol<<" m^3"<<endl;

    }else{
        cout<<"essa figura não existe!"<<endl;
    }
}
double objetos::getforma() const{
    return vol;
}
void objetos::setdensidade(){
    densidade = massa/vol;
    cout<< "densidade do objeto: "<<densidade<<" kg/m^3"<<endl<<endl;
}
double objetos::getdensidade ()const{
    return densidade;
}
void objetos::setposicao(){
    //coleta das posições:
    cout<<"qual a posicao inicial do seu objeto em x? "<<endl<<endl;
    cin>> posx;
    cout<<"qual a posicao inicial do seu objeto em y? "<<endl<<endl;
    cin>> posy;
    cout<<"qual a posicao inicial do seu objeto em x? "<<endl<<endl;
    cin>> posz;
    //print das posições:
    cout<<"pisicao inicial do seu objeto: "<<"("<<posx<<","<<posy<<","<<posz<<")"<<endl<<endl;

}
void objetos::setmaterial(){
    cout<<"escolha o material do seu objeto entre: aluminio, ferro e madeira: "<<endl;
    cin>>material;
}
void objetos::setprop_material(){
    if(material == "aluminio"){
        dense_material =  aluminio1;
        tipo_material = "cfc";
    }else if(material == "ferro"){
        dense_material =  ferro1;
        tipo_material = "ccc";
    }else if(material == "madeira"){
        dense_material =  madeira1;
        tipo_material = "ccc";
    }
    cout<< "densidade: "<<dense_material<<endl<<endl;

}
double objetos::getdense_material() const{
    return dense_material;
}
string objetos::getmaterial() const{
    return material;
}
void objetos::setatritoestatico(){
    cout<<"qual o valor do atrito estatico do seu objero com o solo? ";
    cin>> atritoestatico;

}
double objetos::getatritocinetico ()const{
    return atritocinetico;
}
void objetos::setatritocinetico(){
    cout<<"qual o valor do atrito cinetico do seu objero com o solo? ";
    cin>> atritocinetico;

}
double objetos::getatritoestatico ()const{
    return atritoestatico;
}
//retorno das posições
double objetos::getposicaox ()const{
    return posx;
}
double objetos::getposicaoy ()const{
    return posy;
}
double objetos::getposicaoz ()const {
    return posz;
}
void campo::setsolo(){
    cout<<"qual material do solo entre aluminio, ferro e madeira? ";
    cin>> solo;
}
//caso o usuario escolha
void campo::setatritomat(string materialobj){
    if(solo == "ferro" && materialobj == "ferro"){
        atritoc = 0.15;
        atritoe = 1.1;
        chaveatr = true;
    }else if((solo == "ferro" || materialobj == "aluminio") && (solo == "aluminio" || materialobj == "ferro")){
        atritoc = 0.47;
        atritoe = 0.61;
        chaveatr = true;
    }else if((solo == "ferro" || materialobj == "madeira") && (solo == "madeira" || materialobj == "ferro" )){
        atritoc = 0.5;
        atritoe = 0.6;
        chaveatr = true;
    }else if((solo == "madeira" || materialobj == "aluminio") && (solo == "aluminio" || materialobj == "madeira" )){
        atritoc = 0.45;
        atritoe = 0.55;
        chaveatr = true;
    }else if( solo == "aluminio" && materialobj == "aluminio"){
        atritoc = 1.05;
        atritoe = 1.35;
        chaveatr = true;
    }else if( solo == "madeira" && materialobj == "madeira"){
        atritoc = 0.20;
        atritoe = 0.50;
        chaveatr = true;
    }else{
        cout<<"esse solo não existe! tente novamente"<<endl<<endl;
        chaveatr = false;
    }

}
int campo::getchave ()const{

    if(chaveatr){
        return 1;
    }else{
        return 0;
    }
}
void campo::setatritoeobj(double atritoeobj){
    atritoe = atritoeobj;
}
void campo::setatritocobj(double atritocobj){
    atritoc = atritocobj;
}
//função que recebe e trata a força

void campo::forca(){
    // lembre-se de que devemos usar apenas atrito estatico e que o retorno é a força remanecente
    cout<<"qual a força aplicada em x? "<<endl<<endl;
    cin>> fx;
    cout<<"qual a força aplicada em y? "<<endl<<endl;
    cin>> fy;
    cout<<"qual a força aplicada em z? "<<endl<<endl;
    cin>> fz;
    //calculo de atrito estaticona força


}
void campo::saida_forca(double massaobj,double densi_obj){
    if(fx == 0 && fy == 0){
        double fn = g*massaobj;
        //importando para classe campo

        fn_mov = fn;
        fx = cosx_mov;
        fx = seny_mov;

    }else{
        double modulo_forca = sqrt(fx*fx +  fy*fy);
        double cosx = fx/modulo_forca;
        double seny = fy/modulo_forca;
        double fn = g*massaobj;
        double fue = fn*atritoe;
        double fuex = fue*cosx;
        double fuey = fue*seny;
        fx -= fuex;
        fy -= fuey;

        //importando para classe campo

        fn_mov = fn;
        cosx_mov = cosx;
        seny_mov = seny;

        //força de empuxo
        float densi_ar = 1.225;
        double ce = densi_ar/densi_obj;
        double fme = ce*fn;
        fme_objz = fme;

    }

}

void campo::setmovimento(double mobj, double volobj,double x,double y, double z){

    if(cosx_mov == 0 && seny_mov != 0){

        double fuc = fn_mov*atritoc;
        double fucy = fuc*seny_mov;

        //velocidade base sem atrito cinetico "necessario"
        double vel_objz = fz/mobj;
        double vel_objy = fy/mobj;

        //atrito para ser subtraido no main

        double afucy = fucy/mobj;

        //mandando para campo:

        afucy_camp = afucy;
        vel_objy_camp = vel_objy;
        vel_objz_camp = vel_objz;

    }else if(cosx_mov != 0 && seny_mov == 0){

        double fuc = fn_mov*atritoc;
        double fucx = fuc*cosx_mov;

        //velocidade base sem atrito cinetico "necessario"
        double vel_objz = fz/mobj;
        double vel_objx = fx/mobj;

        //atrito para ser subtraido no main

        double afucx = fucx/mobj;

        //mandando para campo:

        afucx_camp = afucx;
        vel_objx_camp = vel_objx;
        vel_objz_camp = vel_objz;

    }else if(cosx_mov != 0 && seny_mov != 0){

        double fuc = fn_mov*atritoc;
        double fucx = fuc*cosx_mov;
        double fucy = fuc*seny_mov;

        //velocidade base sem atrito cinetico "necessario"
        double vel_objx = fx/mobj;
        double vel_objy = fy/mobj;
        double vel_objz = fz/mobj;

        //atrito para ser subtraido no main
        double afucx = fucx/mobj;
        double afucy = fucy/mobj;

        //mandando para campo:
        afucx_camp = afucx;
        afucy_camp = afucy;
        vel_objx_camp = vel_objx;
        vel_objy_camp = vel_objy;
        vel_objz_camp = vel_objz;

    }else{
        double vel_objz = fz/mobj;
        vel_objz_camp = vel_objz;
    }






}
double campo::velocidadex(){
    return vel_objx_camp;
}
double campo::velocidadey(){
    return vel_objy_camp;
}
double campo::velocidadez(){
    return vel_objz_camp;
}
double campo::aceleracao_atritocx(){
    return afucx_camp;
}
double campo::aceleracao_atritocy(){
    return afucy_camp;
}
double campo::get_empuxo(){
    return fme_objz;
}
