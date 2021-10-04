#ifndef RT1_MUNDO_H
#define RT1_MUNDO_H
#include "./Camara.h"
#include "Cilindro.h"
#include "Esfera.h"
#include "Plano.h"
#include "Caja.h"
#include <stdlib.h>

class Mundo {
  public:
  Camara cam;

  float positive_random(int max){
    return ((rand() % (max * 10)) + 1) / 10.0;
  }

  float random(int max){
    float random_number = rand() % (max * 10) + 1;
    random_number = random_number - (max*10/2.0);
    return random_number / 10.0;
  }
  Mundo(){
    srand(time(NULL));
    std::cout<<"dentro de mundo";
    cam.calcularVectores(vec3f(5, 7, 27), vec3f(0, 0, 0), vec3f(0, 1, 0));
    cam.inicializar(800, 600, 45, 10);

    vector<Objeto*> objetos;

    /*auto *pCilindro1 = new Cilindro(vec3f(0, 5, 0),
                                          vec3f(0, 0, 0),
                                          2.5,
                                          vec3f(255, 233, 0),
                                          vec3f(10, 230, 30),
                                          1);

    objetos.push_back(pCilindro1);
*/
    for (int i = 0; i<10;i++ ){
      Esfera *pEsfera = new Esfera(
          vec3f(random(5), positive_random(3), random(5)),
          0.2,
          vec3f(positive_random(1), positive_random(1), positive_random(1)),
          vec3f(0.9, 0.5, 0.2), 4);
      pEsfera->dir = vec3f(random(1), random(1), random(1));
      cout<<pEsfera->dir<<endl;
      cout<<pEsfera->centro<<endl;
      cout<<endl;
      objetos.push_back(pEsfera);
    }

    /*Objeto *pEsfera = new Esfera(vec3f(0, 5, 0), 0.4, vec3f(0.9,0.7,0.46), vec3f(0.9, 0.5, 0.2), 4);pEsfera->es_reflexivo = true;objetos.push_back(pEsfera);

    Objeto *pEsfera3 = new Esfera(vec3f(1, 5, 1), 0.4, vec3f(0.9,0.7,0.46), vec3f(0.9, 0.5, 0.2), 4);pEsfera3->es_reflexivo = true;objetos.push_back(pEsfera3);

    Objeto *pEsfera5 = new Esfera(vec3f(0.5, 5, 0.5), 0.4, vec3f(0.9,0.7,0.46), vec3f(0.9, 0.5, 0.2), 4);pEsfera5->es_reflexivo = true;objetos.push_back(pEsfera5);

    Objeto *pEsfera7 = new Esfera(vec3f(-0.5, 5, -0.5), 0.4, vec3f(0.9,0.7,0.46), vec3f(0.9, 0.5, 0.2), 4);pEsfera7->es_reflexivo = true;objetos.push_back(pEsfera7);

    Objeto *pEsfera9 = new Esfera(vec3f(-1, 5, -1), 0.4, vec3f(0.9,0.7,0.46), vec3f(0.9, 0.5, 0.2), 4);pEsfera9->es_reflexivo = true;objetos.push_back(pEsfera9);

    Objeto *pEsfera11 = new Esfera(vec3f(-1.2, 5, 1.2), 0.4, vec3f(0.9,0.7,0.46), vec3f(0.9, 0.5, 0.2), 4);pEsfera11->es_reflexivo = true;objetos.push_back(pEsfera11);
    */
    //Objeto *pEsfera2 = new Esfera(vec3f(0.4, 5.1, 0.4), 0.4, vec3f(0, 0, 0), vec3f(1, 0.6, 0.3), 3);pEsfera2->es_reflexivo = true;objetos.push_back(pEsfera2);
    //Objeto *pEsfera4 = new Esfera(vec3f(1.1, 5.1, 1.1), 0.4, vec3f(0, 0, 0), vec3f(1, 0.6, 0.3), 3);pEsfera4->es_reflexivo = true;objetos.push_back(pEsfera4);
    //Objeto *pEsfera6 = new Esfera(vec3f(0.6, 5.1, 0.6), 0.4, vec3f(0, 0, 0), vec3f(1, 0.6, 0.3), 3);pEsfera6->es_reflexivo = true;objetos.push_back(pEsfera6);
    //Objeto *pEsfera8 = new Esfera(vec3f(-0.6, 5.1, -0.6), 0.4, vec3f(0, 0, 0), vec3f(1, 0.6, 0.3), 3);pEsfera8->es_reflexivo = true;objetos.push_back(pEsfera8);
    //Objeto *pEsfera10 = new Esfera(vec3f(-1.1, 5.1, -1.1), 0.4, vec3f(0, 0, 0), vec3f(1, 0.6, 0.3), 3);pEsfera10->es_reflexivo = true;objetos.push_back(pEsfera10);
    //Objeto *pEsfera12 = new Esfera(vec3f(-1.3, 5.1, 1.3), 0.4, vec3f(0, 0, 0), vec3f(1, 0.6, 0.3), 3);pEsfera12->es_reflexivo = true;objetos.push_back(pEsfera12);
/*
    Caja *pCaja = new Caja(
            vec3f(6.1, 2, 6.1),
            vec3f	(141, 73, 37),
            vec3f(0, 0, 0),
            5);
    pCaja->es_reflexivo = true;
    objetos.push_back(pCaja);
*/
    Plano *pPlano = new Plano(vec3f(0, 0, 0),
                              vec3f(0, 1, 0),
                              vec3f(0.6, 0.6, 1),
                              vec3f(0.9, 0.4, 0), 3);
    pPlano->es_reflexivo = true;

    objetos.push_back(pPlano);
    ////Matrix de ESFERAS

    /*for(int kd=0;kd<4;kd++){
        for(int ks=0;ks<4;ks++){
            Objeto *pEspefera14 = new Esfera(vec3f(-10+kd*10,0,-10+ks*10),
                                             4,
                                             vec3f(1,0,0.25),
                                             vec3f(kd*0.4,ks*0.4,0.4),
                                             4);
            pEspefera14->es_reflexivo = true;
            pEspefera14->es_refractivo = true;
            objetos.push_back(pEspefera14);
        }
    }
    */

    cam.setObjetos(objetos);
  };
  void run();
};


#endif //RT1_MUNDO_H
