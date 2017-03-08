#include "physics.h"
#include <cstdlib>
#include <math.h>

// Multiplies a vector by a scaler.  Returns result in result
void vecScaler(float scaler, float* vector, unsigned int size, float* result) {
	for (unsigned int i = 0; i < size; i++)
		result[i] = scaler * vector[i];
}

// Finds the dot product of two vectors
float dotProduct(float* v1, float* v2, unsigned int size) {
	float sum = 0;
	for (unsigned int i = 0; i < size; i++) 
		sum += v1[i] * v2[i];
	return sum;
}

// Calculates the magnitude of a vector
float calcMagnitude(float* vec, unsigned int size) {
	float sum = 0;
	for (unsigned int i = 0; i < size; i++)
		sum += pow(vec[i], 2);
	float result = pow(sum, 0.5);
	return result;
}

float calcFriction(float mass, const float* accel, float coefficient, float* result) {
	for (unsigned int i = 0; i < 3; i++)
		result[i] = mass * accel[i] * coefficient;
	return calcMagnitude(result, 3);
}

float clacMomentum(float mass, const float* velocity, float* result) {
	for (unsigned int i = 0; i < 3; i++)
		result[i] = mass * velocity[i];
	return calcMagnitude(result, 3);
}

float clacKinetic(float mass, float* velocity, float* result) {
	for (unsigned int i = 0; i < 3; i++)
		result[i] = 0.5 * mass * pow(velocity[i], 2);
	return calcMagnitude(result, 3);
}

float calcPotential(float mass, const float* pos, const float* field, float* result) {
	for (unsigned int i = 0; i < 3; i++) 
		result[i] = mass * pos[i] * field[i];
	return calcMagnitude(result, 3);
}