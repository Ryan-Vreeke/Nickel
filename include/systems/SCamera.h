#include "Components.h"
#include <unordered_map>

class SCamera {
public:
  SCamera();

  void makeLookMat(std::unordered_map<uint32_t, CCamera> &ccamera,
                   std::unordered_map<uint32_t, CTransform> &ctransform,
                   uint32_t camera);
};
