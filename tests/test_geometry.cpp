//
// Created by bpenin on 06/06/19.
//

#include <iostream>
#include "MathUtils/MathUtils.h"

using namespace mathutils;

bool double_equals(double a, double b, double epsilon = 1e-3)
{
  return std::abs(a - b) < epsilon;
}

int main(int argc, char* argv[]) {

  Eigen::Vector3d euler_angles(30*MU_PI/180,45*MU_PI/180,-60*MU_PI/180);
  Eigen::Quaterniond quat(0.7,0,0,0.7);

  assert( double_equals(quaternionToEulerAnglesZYX(eulerAnglesZYXToQuaternion(euler_angles))(0) , euler_angles(0)) );
  assert( double_equals(quaternionToEulerAnglesZYX(eulerAnglesZYXToQuaternion(euler_angles))(1) , euler_angles(1)) );
  assert( double_equals(quaternionToEulerAnglesZYX(eulerAnglesZYXToQuaternion(euler_angles))(2) , euler_angles(2)) );
  assert( double_equals(rotationMatrixToEulerAnglesZYX(eulerAnglesZYXToRotationMatrix(euler_angles))(0) , euler_angles(0)) );
  assert( double_equals(rotationMatrixToEulerAnglesZYX(eulerAnglesZYXToRotationMatrix(euler_angles))(1) , euler_angles(1)) );
  assert( double_equals(rotationMatrixToEulerAnglesZYX(eulerAnglesZYXToRotationMatrix(euler_angles))(2) , euler_angles(2)) );
  assert( double_equals(RotationMatrixToQuaternion(quaternionToRotationMatrix(quat)).x() , quat.x()) );
  assert( double_equals(RotationMatrixToQuaternion(quaternionToRotationMatrix(quat)).y() , quat.y()) );
  assert( double_equals(RotationMatrixToQuaternion(quaternionToRotationMatrix(quat)).z() , quat.z() , 4e-3));
  assert( double_equals(RotationMatrixToQuaternion(quaternionToRotationMatrix(quat)).w() , quat.w() , 4e-3));

  return 0;
}

