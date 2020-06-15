#include "CubeService.h"

CubeService::CubeService(Cube &cube)
: cube(cube) {}

std::pair<RotationDirection, RotationSign> CubeService::lastAction() {
    return std::make_pair(lastRD, lastSign);
}

void CubeService::rotate(RotationDirection rd, RotationSign sign) {
    cube.rotate(rd, sign);
    lastRD = rd;
    lastSign = sign;
}
