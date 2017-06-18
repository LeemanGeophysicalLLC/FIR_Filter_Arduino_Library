template <typename T, int ntaps>
FIR<T, ntaps>::FIR() {
  k = 0;
  for (int i=0; i<ntaps; i++){
    values[i] = 0;
  }
}

template <typename T, int ntaps>
void FIR<T, ntaps>::setGain(T newgain) {
  gain = newgain;
}

template <typename T, int ntaps>
void FIR<T, ntaps>::setFilterCoeffs(T *coeffs) {
  for (int i=0; i<ntaps; i++) {
    fir_coeffs[i] = coeffs[i];
  }
}

template <typename T, int ntaps>
T FIR<T, ntaps>::processReading(T newval){
  T output = 0;
  values[k] = newval;

  for (int i=0; i<ntaps; i++){
    output += fir_coeffs[i] * values[(i + k) % ntaps];
  }

  k = (k+1) % ntaps;

  return output/gain;
}
