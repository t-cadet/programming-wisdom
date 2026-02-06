// https://github.com/TheAlgorithms/C/blob/master/geometry/quaternions.c
euler euler_from_quat(const quaternion *in_quat) {
  euler out_euler;
  if (!in_quat) {
    fprintf(stderr, "%s: Invalid input.", __func__);
    return out_euler;
  }

  out_euler.roll = atan2f(2.f * (in_quat->w * in_quat->q1 + in_quat->q2 * in_quat->q3), 1.f - 2.f * (in_quat->q1 * in_quat->q1 + in_quat->q2 * in_quat->q2));
  out_euler.pitch = asinf(2.f * (in_quat->w * in_quat->q2 + in_quat->q1 * in_quat->q3));
  out_euler.yaw = atan2f(2.f * (in_quat->w * in_quat->q3 + in_quat->q1 * in_quat->q2), 1.f - 2.f * (in_quat->q2 * in_quat->q2 + in_quat->q3 * in_quat->q3));

  return out_euler;
}

