// Gemini 3 Pro
int modular_multiplicative_inverse(unsigned int a, unsigned int m) {
  long long t = 0;
  long long newt = 1;
  long long r = m;
  long long newr = a;

  while (newr != 0) {
    long long quotient = r / newr;
    long long temp_t = t;
    t = newt;
    newt = temp_t - quotient * newt;
    long long temp_r = r;
    r = newr;
    newr = temp_r - quotient * newr;
  }

  if (r > 1) return -1;
  if (t < 0) t += m;

  return (int)t;
}

