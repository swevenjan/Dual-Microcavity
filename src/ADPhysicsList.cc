#include "ADPhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

#include"G4HadronElasticPhysicsHP.hh"
#include"G4HadronPhysicsFTFP_BERT_HP.hh"
#include"G4HadronPhysicsQGSP_BERT_HP.hh"
#include"G4HadronInelasticQBBC.hh"
#include"G4HadronPhysicsINCLXX.hh"
#include"G4IonElasticPhysics.hh"
#include"G4IonPhysics.hh"
#include"G4IonINCLXXPhysics.hh"
#include"Gamma.hh"
// particles
#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronElasticPhysicsXS.hh"
#include "G4HadronElasticPhysicsHP.hh"
#include "G4NeutronTrackingCut.hh"
#include "G4StoppingPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ADPhysicsList::ADPhysicsList()
	: G4VModularPhysicsList() {
	SetVerboseLevel(1);
	//EM
	RegisterPhysics(new G4EmStandardPhysics());
	// Decay
	RegisterPhysics(new G4DecayPhysics());
	// Radioactive decay
	RegisterPhysics(new G4RadioactiveDecayPhysics());
	// Synchroton Radiation & GN Physics
	RegisterPhysics(new G4EmExtraPhysics(1));
	// Hadron Physics
	RegisterPhysics(new G4HadronElasticPhysicsXS(1));
	RegisterPhysics(new G4StoppingPhysics(1));
	RegisterPhysics(new G4IonPhysics(1));
	RegisterPhysics(new G4HadronInelasticQBBC(1));
	// Neutron tracking cut
	RegisterPhysics(new G4NeutronTrackingCut(1));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ADPhysicsList::~ADPhysicsList()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ADPhysicsList::ConstructParticle()
{
	G4BosonConstructor pBosonConstructor;
	pBosonConstructor.ConstructParticle();

	G4LeptonConstructor pLeptonConstructor;
	pLeptonConstructor.ConstructParticle();

	G4MesonConstructor pMesonConstructor;
	pMesonConstructor.ConstructParticle();

	G4BaryonConstructor pBaryonConstructor;
	pBaryonConstructor.ConstructParticle();

	G4ShortLivedConstructor pShortLivedConstructor;
	pShortLivedConstructor.ConstructParticle();

	G4IonConstructor pIonConstructor;
	pIonConstructor.ConstructParticle();
}


void ADPhysicsList::SetCuts()
{
	G4VUserPhysicsList::SetCuts();
}