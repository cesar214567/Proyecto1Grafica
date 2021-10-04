#include "Esfera.h"
#include "Cilindro.h"
#include "Rayo.h"
#include <iostream>
#include <cmath>
Esfera::Esfera(vec3f cen, float r, vec3f col, vec3f _kdkskr, float _n) : centro{cen}, radio{r}, Objeto(col, _kdkskr,_n) {}

bool Esfera::intersectar(Rayo ray, float &t, vec3f &col, vec3f &normal) {
    auto _a = ray.dir.productoPunto(ray.dir);
    auto _b = 2*ray.dir.productoPunto(ray.ori-centro);
    auto _c = (ray.ori-centro).productoPunto(ray.ori-centro)-radio*radio;
    auto D = _b*_b-4*_a*_c;
    if(D <= 0) {return false;}
    float t1 = (-_b + sqrt(D))/2*_a;
    float t2 = (-_b - sqrt(D))/2*_a;
    t = std::min(t1, t2);
    if(t <= 0) {return false;}
    col = color;
    vec3f pi = ray.punto_interseccion(t);
    normal = pi - centro;
    normal.normalize();

    return true;

}

bool inside_cilinder(Cilindro* cilindro, Esfera* esfera){
  float distance = sqrt(pow(esfera->centro.x,2) + pow(esfera->centro.z,2));
  return distance < cilindro->ra && esfera->centro.y > cilindro->pb.y && esfera->centro.y < cilindro->pa.y;
}

void Esfera::move(Objeto* object){
  Rayo ray;
  ray.dir = this->dir;
  ray.ori = this->centro;
  Cilindro *cilindro = dynamic_cast<Cilindro *>(object);
  if(!inside_cilinder(cilindro,this)){
    std::cout << "cambio direccion" << std::endl;
    this->dir = this->dir * float(-1.0);
  }

  centro.x += dir.x;
  centro.y += dir.y;
  centro.z += dir.z;
}
