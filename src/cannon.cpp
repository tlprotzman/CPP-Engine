#include "particle.h"
#include "physics.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
	float pos[3] = {1, 1, 1};
	Particle* p = new Particle(1, pos);
	std::cout << *p << std::endl;
	float vel[3] = {5, 100, 30};
	p -> setVel(vel);
	std::cout << *p << std::endl;
	
	float dt = 0.01;
	float time = 0;
	float gravity[3] = {0, 0, -9.8};

	std::ofstream log("../log/log.txt");
	logParticle(log, *p, time);

	while (p -> getPos()[2] > 0) {
		time += dt;
		p -> applyAcceleration(gravity);
		p -> update(dt);
		logParticle(log, *p, time);
		// std::cout << "Time : " << time << " " << *p << std::endl;
		float temp[3];
		std::cout << calcKinetic(p -> getMass(), p -> getVel(), temp) << std::endl;
	}


	delete p;
	return 0;
}