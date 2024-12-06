#include "ADPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Tubs.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4IonTable.hh"
#include "G4GeneralParticleSource.hh"
#include "G4RandomDirection.hh"

ADPrimaryGeneratorAction::ADPrimaryGeneratorAction() :G4VUserPrimaryGeneratorAction(),
fParticleGun(0), fparticleTub(0), fParticleSource(nullptr)
{
	
	fParticleSource = new G4GeneralParticleSource();


}

ADPrimaryGeneratorAction::~ADPrimaryGeneratorAction()
	{
		delete fParticleGun;
		delete fParticleSource;
	}

void ADPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{

	fParticleSource->GeneratePrimaryVertex(anEvent);
}