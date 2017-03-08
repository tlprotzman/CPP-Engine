void vecScaler(float scaler, const float* vector, unsigned int size, float* result);
float dotProduct(float* v1, float* v2, unsigned int size);
float clacMagnitude(float* vec, unsigned int size);

float calcFriction(float mass, const float* accel, float coefficient, float* result);
float calcMomentum(float mass, const float* velocity, float* result);
float calcKinetic(float mass, float* velocity, float* result);
float calcPotential(float mass, const float* pos, const float* field, float* result);