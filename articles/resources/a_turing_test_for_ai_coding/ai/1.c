// Claude 4.5 Sonnet
euler euler_from_quat(const quaternion *in_quat) {
  euler result;

  float w = in_quat->w;
  float x = in_quat->x;
  float y = in_quat->y;
  float z = in_quat->z;

  float sinr_cosp = 2.0f * (w * x + y * z);
  float cosr_cosp = 1.0f - 2.0f * (x * x + y * y);
  result.roll = atan2f(sinr_cosp, cosr_cosp);

  float sinp = 2.0f * (w * y - z * x);
  if (fabsf(sinp) >= 1.0f)
    result.pitch = copysignf(M_PI / 2.0f, sinp);
  else
    result.pitch = asinf(sinp);

  float siny_cosp = 2.0f * (w * z + x * y);
  float cosy_cosp = 1.0f - 2.0f * (y * y + z * z);
  result.yaw = atan2f(siny_cosp, cosy_cosp);

  return result;
}

