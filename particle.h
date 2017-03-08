#include <fstream>

class Particle {
public:
	// CONSTRUCTORS/DESTRUCTOR
	Particle();
	Particle(float mass_);
	Particle(float mass_, float* pos_);
	Particle(float mass_, float* pos_, float* vel_);
	Particle(float mass_, float* pos_, float* vel_, unsigned int dimensions);	
	// ~Particle();

	// ACCESSORS
	const float getMass() const; 
	const float* getPos() const;	// Returns an array [x, y]
	const float* getVel() const;	// Retruns an array [x, y]

	// MUTATORS
	void applyForce(float* forces);	// Expects an array [fx, fy]
	void setPos(float* newPos);
	void setVel(float* newVel);
	void update(float dt);


private:
	float* pos;
	float* vel;
	float* force;
	float mass;
	unsigned int dimensions;

	void init(float mass_, float* pos_, float* vel_, unsigned int dimensions_);
	void updateVelocity(float dt);
	void updatePosition(float dt);
};

std::ostream& operator<<(std::ostream& out, const Particle& p);
void logParticle(std::ofstream& file, const Particle& p, float time);
