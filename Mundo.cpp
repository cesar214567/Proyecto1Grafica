#include "Mundo.h"

void Mundo::run() {
  auto *pCilindro1 = new Cilindro(vec3f(0, 5, 0),
                                  vec3f(0, 0, 0),
                                  5,
                                  vec3f(255, 233, 0),
                                  vec3f(10, 230, 30),
                                  1);
  cam.Renderizar(pCilindro1);
}
