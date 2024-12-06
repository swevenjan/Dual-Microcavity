#ifndef ADPrimaryGeneratorAction_h
#define ADPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class G4Tubs;
class G4GeneralParticleSource;

class ADPrimaryGeneratorAction :public G4VUserPrimaryGeneratorAction
{
public:
	ADPrimaryGeneratorAction();
	virtual ~ADPrimaryGeneratorAction();

	virtual void GeneratePrimaries(G4Event*);

	const G4ParticleGun* GetParticleGun() const { return fParticleGun; }

private:
	G4ParticleGun* fParticleGun;
	G4Tubs* fparticleTub;//Á£×Ó·¢ÉäÆ÷¿é
	G4GeneralParticleSource* fParticleSource;

};
#endif // !ADPrimaryGeneratorAction_h