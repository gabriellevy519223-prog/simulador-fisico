#ifndef SIMU_H_INCLUDED
#define SIMU_H_INCLUDED
#include <string>
#include <cmath>
using namespace std;
class objetos{
private:
    const double aluminio1 =2700,ferro1=7870,madeira1=500;
    float massa,aresta,altura,largura,profundidade,raio;
    string corpo;
    //material do objeto
    string material, tipo_material;
    double dense_material;
    //edição propriedades
    double vol,densidade,atritoestatico,atritocinetico;
    double posx,posy,posz;

    //atrito deve se tornar uma função futuramente
    double atrito;
public:
    //definindo valores para as variaveis
    void setmassa();
    void setforma();
    void setdensidade();
    void setposicao();
    void setmaterial();
    void setprop_material();
    void setatritoestatico();
    void setatritocinetico();
    //saida para o main
    double getdense_material() const;
    double getposicaox() const;
    double getposicaoy() const;
    double getposicaoz() const;
    double getdensidade() const;
    string getmaterial() const;
    double getforma() const;
    double getmassa() const;
    double getatritocinetico() const;
    double getatritoestatico ()const;
};
class campo{
private:
    //constantes e variaveis
    double fx,fy,fz;
    float g = 9.81;
    string solo;
    double atritoc,atritoe;
    bool chaveatr;

    //variaveis para o main:

    //na função forca:
    double fn_mov,cosx_mov,seny_mov;

    //função setmovimento:
    double afucx_camp,afucy_camp,vel_objx_camp,vel_objy_camp,vel_objz_camp,fme_objz;

public:
    void setsolo();
    void setatritocobj(double atritocobj);
    void setatritoeobj(double atritoeobj);
    void setatritomat(string materialobj);
    void forca();
    void saida_forca(double massaobj, double densi_obj);
    int getforcax();
    int getforcay();
    void setmovimento(double mobj, double volobj,double x,double y, double z);
    int getchave ()const;
    //retorno para o main
    double velocidadex();
    double velocidadey();
    double velocidadez();
    double aceleracao_atritocx();
    double aceleracao_atritocy();

    //retorno empuxo
    double get_empuxo();

};

#endif // SIMU_H_INCLUDED
